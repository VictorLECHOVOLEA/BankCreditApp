#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class CSVFileManager {
private:
    std::string filename;

public:
    explicit CSVFileManager(const std::string& filename) : filename(filename) {}

    void createFile() {
        std::ofstream file(filename);
        if (file) {
            file << "Shop name,Amount,Transaction Description\n";
            file.close();
            std::cout << "CSV file created successfully.\n";
        } else {
            std::cerr << "Error creating CSV file.\n";
        }
    }

    void readFile() {
        std::ifstream file(filename);
        if (file) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string shop_name, amount, trans_description;
                if (std::getline(iss, shop_name, ',') &&
                    std::getline(iss, amount, ',') &&
                    std::getline(iss, trans_description, ',')) {
                    std::cout << "Shop name: " << shop_name << ", Amount: " << amount << ", Transaction Description: " << trans_description << "\n";
                }
            }
            file.close();
        } else {
            std::cerr << "Error opening CSV file.\n";
        }
    }

    void addRecord(const std::string& shop_name, const std::string& amount, const std::string& trans_description) {
        std::ofstream file(filename, std::ios_base::app);
        if (file) {
            file << shop_name << "," << amount << "," << trans_description << "\n";
            file.close();
            std::cout << "Record added successfully.\n";
        } else {
            std::cerr << "Error opening CSV file.\n";
        }
    }

    void readRecord(const std::string& shop_name) {
        std::ifstream file(filename);
        if (file) {
            std::string line;
            bool found = false;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string recordName, amount, trans_description;
                if (std::getline(iss, recordName, ',') &&
                    std::getline(iss, amount, ',') &&
                    std::getline(iss, trans_description, ',')) {
                    if (recordName == shop_name) {
                        std::cout << "Shop name: " << recordName << ", Amount: " << amount << ", Transaction Description: " << trans_description << "\n";
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                std::cout << "Record not found.\n";
            }
            file.close();
        } else {
            std::cerr << "Error opening CSV file.\n";
        }
    }

    void updateRecord(const std::string& shop_name, const std::string& amount, const std::string& trans_description) {
        std::ifstream file(filename);
        if (file) {
            std::string line;
            std::vector<std::string> records;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string recordName, recordAge, recordHobby;
                if (std::getline(iss, recordName, ',') &&
                    std::getline(iss, recordAge, ',') &&
                    std::getline(iss, recordHobby, ',')) {
                    if (recordName == shop_name) {
                        recordAge = amount;
                        recordHobby = trans_description;
                    }
                    records.push_back(recordName + "," + recordAge + "," + recordHobby);
                }
            }
            file.close();

            std::ofstream outFile(filename);
            if (outFile) {
                for (const std::string& record : records) {
                    outFile << record << "\n";
                }
                outFile.close();
                std::cout << "Record updated successfully.\n";
            } else {
                std::cerr << "Error opening CSV file for writing.\n";
            }
        } else {
            std::cerr << "Error opening CSV file.\n";
        }
    }

    void deleteRecord(const std::string& shop_name) {
        std::ifstream file(filename);
        if (file) {
            std::string line;
            std::vector<std::string> records;
            bool found = false;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string recordName, amount, trans_description;
                if (std::getline(iss, recordName, ',') &&
                    std::getline(iss, amount, ',') &&
                    std::getline(iss, trans_description, ',')) {
                    if (recordName != shop_name) {
                        records.push_back(recordName + "," + amount + "," + trans_description);
                    } else {
                        found = true;
                    }
                }
            }
            file.close();

            std::ofstream outFile(filename);
            if (outFile) {
                for (const std::string& record : records) {
                    outFile << record << "\n";
                }
                outFile.close();
                if (found) {
                    std::cout << "Record deleted successfully.\n";
                } else {
                    std::cout << "Record not found.\n";
                }
            } else {
                std::cerr << "Error opening CSV file for writing.\n";
            }
        } else {
            std::cerr << "Error opening CSV file.\n";
        }
    }

    void deleteFile() {
        if (remove(filename.c_str()) != 0) {
            std::cerr << "Error deleting CSV file.\n";
        } else {
            std::cout << "CSV file deleted successfully.\n";
        }
    }
};

void welcome() {
    std::cout << "Welcome to the CSV File Manager!\n";
    std::cout << "Options:\n";
    std::cout << "1. Create a new database\n";
    std::cout << "2. Add record\n";
    std::cout << "3. Read file\n";
    std::cout << "4. Read record\n";
    std::cout << "5. Update record\n";
    std::cout << "6. Delete record\n";
    std::cout << "7. Delete file\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    CSVFileManager manager("data.csv");

    int choice;
    std::string shop_name, amount, trans_description;

    welcome();
    while (std::cin >> choice && choice != 0) {
        switch (choice) {
            case 1:
                manager.createFile();
                break;
            case 2:
                std::cout << "Enter shop_name: ";
                std::cin >> shop_name;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cout << "Enter trans_description: ";
                std::cin >> trans_description;
                manager.addRecord(shop_name, amount, trans_description);
                break;
            case 3:
                manager.readFile();
                break;
            case 4:
                std::cout << "Enter shop_name to search: ";
                std::cin >> shop_name;
                manager.readRecord(shop_name);
                break;
            case 5:
                std::cout << "Enter shop_name to update: ";
                std::cin >> shop_name;
                std::cout << "Enter new amount: ";
                std::cin >> amount;
                std::cout << "Enter new trans_description: ";
                std::cin >> trans_description;
                manager.updateRecord(shop_name, amount, trans_description);
                break;
            case 6:
                std::cout << "Enter shop_name to delete: ";
                std::cin >> shop_name;
                manager.deleteRecord(shop_name);
                break;
            case 7:
                manager.deleteFile();
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }

        std::cout << "\n";
        welcome();
    }

    return 0;
}




// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>

// class CSVFileManager {
// private:
//     std::string filename;

// public:
//     explicit CSVFileManager(const std::string& filename) : filename(filename) {}

//     void createFile() {
//         std::ofstream file(filename);
//         if (file) {
//             file << "Shop name,Amount,Transaction Description\n";
//             file.close();
//             std::cout << "CSV file created successfully.\n";
//         } else {
//             std::cerr << "Error creating CSV file.\n";
//         }
//     }

//     void readFile() {
//         std::cout << "  Reading the file:\n";
//         std::ifstream file(filename);
//         if (file) {
//             std::string line;
//             while (std::getline(file, line)) {
//                 std::istringstream iss(line);
//                 std::string shop_name, amount, trans_description;
//                 if (std::getline(iss, shop_name, ',') &&
//                     std::getline(iss, amount, ',') &&
//                     std::getline(iss, trans_description, ',')) {
//                     std::cout << "Shop name: " << shop_name << ", Amount: " << amount << ", Transaction Description: " << trans_description << "\n";
//                 }
//             }
//             file.close();
//         } else {
//             std::cerr << "Error opening CSV file.\n";
//         }
//     }

//     void addRecord(const std::string& shop_name, const std::string& amount, const std::string& trans_description) {
//         std::ofstream file(filename, std::ios_base::app);
//         if (file) {
//             file << shop_name << "," << amount << "," << trans_description << "\n";
//             file.close();
//             std::cout << "Record added successfully.\n";
//         } else {
//             std::cerr << "Error opening CSV file.\n";
//         }
//     }

//     void readRecord(const std::string& shop_name) {
//         std::cout << "  Reading a record:\n";
//         std::ifstream file(filename);
//         if (file) {
//             std::string line;
//             bool found = false;
//             while (std::getline(file, line)) {
//                 std::istringstream iss(line);
//                 std::string recordName, amount, trans_description;
//                 if (std::getline(iss, recordName, ',') &&
//                     std::getline(iss, amount, ',') &&
//                     std::getline(iss, trans_description, ',')) {
//                     if (recordName == shop_name) {
//                         std::cout << "Shop name: " << recordName << ", Amount: " << amount << ", Transaction Description: " << trans_description << "\n";
//                         found = true;
//                         break;
//                     }
//                 }
//             }
//             if (!found) {
//                 std::cout << "Record not found.\n";
//             }
//             file.close();
//         } else {
//             std::cerr << "Error opening CSV file.\n";
//         }
//     }

//     void updateRecord(const std::string& shop_name, const std::string& amount, const std::string& trans_description) {
//         std::cout << "  Updating a record:\n";
//         std::ifstream file(filename);
//         if (file) {
//             std::string line;
//             std::vector<std::string> records;
//             while (std::getline(file, line)) {
//                 std::istringstream iss(line);
//                 std::string recordName, recordAge, recordHobby;
//                 if (std::getline(iss, recordName, ',') &&
//                     std::getline(iss, recordAge, ',') &&
//                     std::getline(iss, recordHobby, ',')) {
//                     if (recordName == shop_name) {
//                         recordAge = amount;
//                         recordHobby = trans_description;
//                     }
//                     records.push_back(recordName + "," + recordAge + "," + recordHobby);
//                 }
//             }
//             file.close();

//             std::ofstream outFile(filename);
//             if (outFile) {
//                 for (const std::string& record : records) {
//                     outFile << record << "\n";
//                 }
//                 outFile.close();
//                 std::cout << "Record updated successfully.\n";
//             } else {
//                 std::cerr << "Error opening CSV file for writing.\n";
//             }
//         } else {
//             std::cerr << "Error opening CSV file.\n";
//         }
//     }

//     void deleteRecord(const std::string& shop_name) {
//         std::cout << "  Deleting a record:\n";
//         std::ifstream file(filename);
//         if (file) {
//             std::string line;
//             std::vector<std::string> records;
//             bool found = false;
//             while (std::getline(file, line)) {
//                 std::istringstream iss(line);
//                 std::string recordName, amount, trans_description;
//                 if (std::getline(iss, recordName, ',') &&
//                     std::getline(iss, amount, ',') &&
//                     std::getline(iss, trans_description, ',')) {
//                     if (recordName != shop_name) {
//                         records.push_back(recordName + "," + amount + "," + trans_description);
//                     } else {
//                         found = true;
//                     }
//                 }
//             }
//             file.close();

//             std::ofstream outFile(filename);
//             if (outFile) {
//                 for (const std::string& record : records) {
//                     outFile << record << "\n";
//                 }
//                 outFile.close();
//                 if (found) {
//                     std::cout << "Record deleted successfully.\n";
//                 } else {
//                     std::cout << "Record not found.\n";
//                 }
//             } else {
//                 std::cerr << "Error opening CSV file for writing.\n";
//             }
//         } else {
//             std::cerr << "Error opening CSV file.\n";
//         }
//     }
// };

// int main() {
//     CSVFileManager manager("data.csv");

//     // Create a new CSV file
//     manager.createFile();

//     // Add records to the CSV file
//     manager.addRecord("John Doe", "25", "Skiing");
//     manager.addRecord("Jane Smith", "30", "Gardening");
//     manager.addRecord("Bob Johnson", "40", "Fishing");

//     // Read all records from the CSV file
//     manager.readFile();

//     // Read a specific record from the CSV file
//     manager.readRecord("Jane Smith");

//     // Update a record in the CSV file
//     manager.updateRecord("Bob Johnson", "45", "Hiking");

//     // Read all records after the update
//     manager.readFile();

//     // Delete a record from the CSV file
//     manager.deleteRecord("John Doe");

//     // Read all records after the deletion
//     manager.readFile();

//     return 0;
// }





/*
Help me build a c++ class that would have multiple functions. these functions should create or read CSV file and write or read some data like shop_name, amount, hoby.  Then a function to Read a particular record, then another one to Update a record and finally, one to delete a recortd.
Certainly! I can help you with that. Here's an example of a C++ class that can handle creating, reading, writing, updating, and deleting records in a CSV file:

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class CSVFileManager {
private:
    std::string filename;

public:
    explicit CSVFileManager(const std::string& filename) : filename(filename) {}

    void createFile() {
        std::ofstream file(filename);
        if (file) {
            file << "Shop name,Amount,Transaction Description\n";
            file.close();
            std::cout << "CSV file created successfully.\n";
        } else {
            std::cerr << "Error creating CSV file.\n";
        }
    }

    void readFile() {
        std::ifstream file(filename);
        if (file) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string shop_name, amount, trans_description;
                if (std::getline(iss, shop_name, ',') &&
                    std::getline(iss, amount, ',') &&
                    std::getline(iss, trans_description, ',')) {
                    std::cout << "Shop name: " << shop_name << ", Amount: " << amount << ", Transaction Description: " << trans_description << "\n";
                }
            }
            file.close();
        } else {
            std::cerr << "Error opening CSV file.\n";
        }
    }

    void addRecord(const std::string& shop_name, const std::string& amount, const std::string& trans_description) {
        std::ofstream file(filename, std::ios_base::app);
        if (file) {
            file << shop_name << "," << amount << "," << trans_description << "\n";
            file.close();
            std::cout << "Record added successfully.\n";
        } else {
            std::cerr << "Error opening CSV file.\n";
        }
    }

    void readRecord(const std::string& shop_name) {
        std::ifstream file(filename);
        if (file) {
            std::string line;
            bool found = false;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string recordName, amount, trans_description;
                if (std::getline(iss, recordName, ',') &&
                    std::getline(iss, amount, ',') &&
                    std::getline(iss, trans_description, ',')) {
                    if (recordName == shop_name) {
                        std::cout << "Shop name: " << recordName << ", Amount: " << amount << ", Transaction Description: " << trans_description << "\n";
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                std::cout << "Record not found.\n";
            }
            file.close();
        } else {
            std::cerr << "Error opening CSV file.\n";
        }
    }

    void updateRecord(const std::string& shop_name, const std::string& amount, const std::string& trans_description) {
        std::ifstream file(filename);
        if (file) {
            std::string line;
            std::vector<std::string> records;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string recordName, recordAge, recordHobby;
                if (std::getline(iss, recordName, ',') &&
                    std::getline(iss, recordAge, ',') &&
                    std::getline(iss, recordHobby, ',')) {
                    if (recordName == shop_name) {
                        recordAge = amount;
                        recordHobby = trans_description;
                    }
                    records.push_back(recordName + "," + recordAge + "," + recordHobby);
                }
            }
            file.close();

            std::ofstream outFile(filename);
            if (outFile) {
                for (const std::string& record : records) {
                    outFile << record << "\n";
                }
                outFile.close();
                std::cout << "Record updated successfully.\n";
            } else {
                std::cerr << "Error opening CSV file for writing.\n";
            }
        } else {
            std::cerr << "Error opening CSV file.\n";
        }
    }

    void deleteRecord(const std::string& shop_name) {
        std::ifstream file(filename);
        if (file) {
            std::string line;
            std::vector<std::string> records;
            bool found = false;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string recordName, amount, trans_description;
                if (std::getline(iss, recordName, ',') &&
                    std::getline(iss, amount, ',') &&
                    std::getline(iss, trans_description, ',')) {
                    if (recordName != shop_name) {
                        records.push_back(recordName + "," + amount + "," + trans_description);
                    } else {
                        found = true;
                    }
                }
            }
            file.close();

            std::ofstream outFile(filename);
            if (outFile) {
                for (const std::string& record : records) {
                    outFile << record << "\n";
                }
                outFile.close();
                if (found) {
                    std::cout << "Record deleted successfully.\n";
                } else {
                    std::cout << "Record not found.\n";
                }
            } else {
                std::cerr << "Error opening CSV file for writing.\n";
            }
        } else {
            std::cerr << "Error opening CSV file.\n";
        }
    }
};

int main() {
    CSVFileManager manager("data.csv");

    // Create a new CSV file
    manager.createFile();

    // Add records to the CSV file
    manager.addRecord("John Doe", "25", "Skiing");
    manager.addRecord("Jane Smith", "30", "Gardening");
    manager.addRecord("Bob Johnson", "40", "Fishing");

    // Read all records from the CSV file
    manager.readFile();

    // Read a specific record from the CSV file
    manager.readRecord("Jane Smith");

    // Update a record in the CSV file
    manager.updateRecord("Bob Johnson", "45", "Hiking");

    // Read all records after the update
    manager.readFile();

    // Delete a record from the CSV file
    manager.deleteRecord("John Doe");

    // Read all records after the deletion
    manager.readFile();

    return 0;
}


In this example, the CSVFileManager class handles various operations related to the CSV file, including creating the file, reading all records, adding a new record, reading a specific record, updating a record, and deleting a record. The main function demonstrates the usage of these functions.

Make sure to replace "data.csv" with the actual file path you want to use for your CSV file.
*/




/*
https://www.geeksforgeeks.org/csv-file-management-using-c/
// #include <iostream>
// #include <string>
// #include <vector>
// #include <fstream>

// void create() {
//     // file pointer
//     fstream fout;

//     // opens an existing csv file or creates a new file
//     fout.open("transactions.csv", ios::out | ios::app);

// }

*/



/*
BUGS

Enter shop_name to search: dedeman
Record not found.

Enter shop_name: Emag
Enter amount: 200
Enter trans_description: masina de spalat

Emag,200,masina




*/