import datetime
# import tkinter as tk

mydict = {"transaction1": ["date1", "value1", "ratesNr1", "description1", "categoryList"],
          "transaction2": ["2023-06-02", 50000, "6", "pardoseala rece si adezivi","finisaje"],
          "transaction3": ["2023-06-03", 150000, "18", "Pardoseala calda- parchet", "finisaje"],
          "transaction4": ["2023-06-03", 100000, "12", "Pardoseala calda- mocheta", "finisaje"],
          "transaction5": ["2023-06-04", 190, "1", "dibluri"],
          }

# def get_transaction_id(mydict):
#     key_count = len(mydict)
#     key_count += 1
#     transaction_id = "transaction_%d" % key_count 
#     return transaction_id

# def get_transaction_data(transaction_date, transaction_value, transaction_rates, transaction_description, transaction_category):
#     new_transaction_data = []
#     # Ask user for transaction date
#     transaction_date_input = input("Enter the transaction date: ")
#     new_transaction_data.append(transaction_date_input)

#     # Ask user for transaction value
#     transaction_value_input = float(input("Enter the transaction value: "))
#     new_transaction_data.append(transaction_value_input)

#     # Ask user for transaction rates
#     transaction_rates_input = int(input("Enter the transaction rates: "))
#     new_transaction_data.append(transaction_rates_input)

#     # Ask user for transaction description
#     transaction_description_input = input("Enter the transaction description: ")
#     new_transaction_data.append(transaction_description_input)

#     # Ask user for transaction category
#     transaction_category_input = input("Enter the transaction category: ")
#     new_transaction_data.append(transaction_category_input)

#     return new_transaction_data

# # Example usage
# # transaction_data = get_transaction_data("transaction_date", "transaction_value", "transaction_rates", "transaction_description", "transaction_category")
# # print(transaction_data)


# def add_transaction(transaction_id, transaction_data, mydict):
#     transaction_data = get_transaction_data("transaction_date", "transaction_value", "transaction_rates", "transaction_description", "transaction_category")
#     print(f"Transaction id: {transaction_id} successfuly added!")
#     mydict[transaction_id] = transaction_data

# # Example usage
# # transaction_id = "transaction6" # a transaction counter should be here to add an automatic value
# # transaction_data = ["2023-06-04", 75000, "8", "Vopsitorie interior", "finisaje"]
# # add_transaction(transaction_id, transaction_data, mydict)

# # print("Number of keys in the dictionary:", key_count)



# add_transaction(get_transaction_id, get_transaction_data, mydict)


# # print(mydict)


# # Sample of getting the transaction data:
# transaction_id = "transaction5"
# if transaction_id in mydict:
#     transaction_values = mydict[transaction_id]
#     print(transaction_values)
# else:
#     print("Transaction ID not found in the dictionary.")



# Search for a specific transaction by:
## it's transaction_id.
# def transaction_values(transaction_id):
#     transaction_id = input("Type the transaction id") #"transaction6"
#     if transaction_id in mydict:
#         transaction_values = mydict[transaction_id]
#         print(transaction_values)
#     else:
#         print("Transaction ID not found in the dictionary.")

# transaction_values(transaction7)

# thisdict = {
# 	"brand": "Ford",
#  	"model": "Mustang",
#  	"year": 1964
# }


# s1 = {1,2,3,4,5,6} #<class 'set'>
# print(type(s1))
# s2 = {6,7,8,9}
# print(s1&s2)





"""
OUTPUT from the console:
## Menu to add a new transaction:

Enter the transaction date: 2023-06-03
Enter the transaction value: 690
Enter the transaction rates: 6
Enter the transaction description: borduri
Enter the transaction category: finisaje exterioare
Transaction id: <function get_transaction_id at 0x00000213799AD4C0> successfuly added!



## How an interogation of the transaction data look like:
['2023-06-04', 190, '1', 'dibluri']


"""


# import tkinter as tk
# from tkcalendar import DateEntry

# def submit_transaction():
#     transaction_id = "transaction" + str(len(mydict) + 1)  # Automatically determine the transaction ID
#     transaction_date = transaction_date_entry.get_date().strftime('%Y-%m-%d')  # Convert date to string
#     transaction_value = float(transaction_value_entry.get())
#     transaction_rates = transaction_rates_var.get()
#     transaction_description = transaction_description_entry.get()
#     transaction_category = transaction_category_var.get()

#     # Process the transaction data as needed (e.g., add to the dictionary)
#     mydict[transaction_id] = [transaction_date, transaction_value, transaction_rates, transaction_description, transaction_category]
#     print("Transaction added successfully!")

#     # Clear the entry fields
#     transaction_date_entry.set_date('')
#     transaction_value_entry.delete(0, tk.END)
#     transaction_rates_var.set('')
#     transaction_description_entry.delete(0, tk.END)
#     transaction_category_var.set('')

# root = tk.Tk()

# # Create labels
# tk.Label(root, text="Transaction ID:").grid(row=0, column=0)
# tk.Label(root, text="Transaction Date:").grid(row=1, column=0)
# tk.Label(root, text="Transaction Value:").grid(row=2, column=0)
# tk.Label(root, text="Transaction Rates:").grid(row=3, column=0)
# tk.Label(root, text="Transaction Description:").grid(row=4, column=0)
# tk.Label(root, text="Transaction Category:").grid(row=5, column=0)

# # Create entry fields
# transaction_id_entry = tk.Entry(root, state='disabled')
# transaction_id_entry.grid(row=0, column=1)

# transaction_date_entry = DateEntry(root, width=12)
# transaction_date_entry.grid(row=1, column=1)

# transaction_value_entry = tk.Entry(root)
# transaction_value_entry.grid(row=2, column=1)

# transaction_rates_var = tk.StringVar(root)
# transaction_rates_var.set('')  # Initial value
# transaction_rates_dropdown = tk.OptionMenu(root, transaction_rates_var, "1", "3", "6", "12", "18", "32")
# transaction_rates_dropdown.grid(row=3, column=1)

# transaction_description_entry = tk.Entry(root)
# transaction_description_entry.grid(row=4, column=1)

# transaction_category_var = tk.StringVar(root)
# transaction_category_var.set('')  # Initial value
# transaction_category_dropdown = tk.OptionMenu(root, transaction_category_var, "finisajeI", "finisajeE", "mobilier", "electrocasnice", "other")
# transaction_category_dropdown.grid(row=5, column=1)

# # Create submit button
# submit_button = tk.Button(root, text="Submit", command=submit_transaction)
# submit_button.grid(row=6, column=0, columnspan=2)

# # Initialize the dictionary
# mydict = {}

# root.mainloop()















import tkinter as tk
from tkcalendar import DateEntry

def submit_transaction():
    transaction_id = "transaction" + str(len(mydict) + 1)  # Automatically determine the transaction ID
    transaction_date = transaction_date_entry.get_date().strftime('%Y-%m-%d')  # Convert date to string
    transaction_value = float(transaction_value_entry.get())
    transaction_rates = transaction_rates_var.get()
    transaction_description = transaction_description_entry.get()
    transaction_category = transaction_category_var.get()

    # Process the transaction data as needed (e.g., add to the dictionary)
    mydict[transaction_id] = [transaction_date, transaction_value, transaction_rates, transaction_description, transaction_category]
    print("Transaction added successfully!")

    # Clear the entry fields
    transaction_date_entry.set_date('')
    transaction_value_entry.delete(0, tk.END)
    transaction_rates_var.set('')
    transaction_description_entry.delete(0, tk.END)
    transaction_category_var.set('')

def visualize_transactions():
    for transaction_id, transaction_data in mydict.items():
        print("Transaction ID:", transaction_id)
        print("Transaction Data:", transaction_data)
        print()

def generate_report():
    start_date = start_date_entry.get_date()
    end_date = end_date_entry.get_date()

    # Process the report generation for the specified date range
    # ...

    # Clear the entry fields
    start_date_entry.set_date('')
    end_date_entry.set_date('')

root = tk.Tk()

# Create functions for menu options
def add_transaction():
    root.withdraw()  # Hide the main window
    add_transaction_window = tk.Toplevel(root)

    # Create labels
    tk.Label(add_transaction_window, text="Transaction Date:").grid(row=0, column=0)
    tk.Label(add_transaction_window, text="Transaction Value:").grid(row=1, column=0)
    tk.Label(add_transaction_window, text="Transaction Rates:").grid(row=2, column=0)
    tk.Label(add_transaction_window, text="Transaction Description:").grid(row=3, column=0)
    tk.Label(add_transaction_window, text="Transaction Category:").grid(row=4, column=0)

    # Create entry fields
    transaction_date_entry = DateEntry(add_transaction_window, width=12)
    transaction_date_entry.grid(row=0, column=1)

    transaction_value_entry = tk.Entry(add_transaction_window)
    transaction_value_entry.grid(row=1, column=1)

    transaction_rates_var = tk.StringVar(add_transaction_window)
    transaction_rates_var.set('')  # Initial value
    transaction_rates_dropdown = tk.OptionMenu(add_transaction_window, transaction_rates_var, "1", "3", "6", "12", "18", "32")
    transaction_rates_dropdown.grid(row=2, column=1)

    transaction_description_entry = tk.Entry(add_transaction_window)
    transaction_description_entry.grid(row=3, column=1)

    transaction_category_var = tk.StringVar(add_transaction_window)
    transaction_category_var.set('')  # Initial value
    transaction_category_dropdown = tk.OptionMenu(add_transaction_window, transaction_category_var, "finisajeI", "finisajeE", "mobilier", "electrocasnice", "other")
    transaction_category_dropdown.grid(row=4, column=1)

    # Create submit button
    submit_button = tk.Button(add_transaction_window, text="Submit", command=submit_transaction)
    submit_button.grid(row=5, column=0, columnspan=2)

    add_transaction_window.protocol('WM_DELETE_WINDOW', root.deiconify)  # Show main window on close

def visualize():
    visualize_transactions()

def generate():
    root.withdraw()  # Hide the main window
    generate_report_window = tk.Toplevel(root)

    # Create labels
    tk.Label(generate_report_window, text="Start Date:").grid(row=0, column=0)
    tk.Label(generate_report_window, text="End Date:").grid(row=1, column=0)

    # Create entry fields
    start_date_entry = DateEntry(generate_report_window, width=12)
    start_date_entry.grid(row=0, column=1)

    end_date_entry = DateEntry(generate_report_window, width=12)
    end_date_entry.grid(row=1, column=1)

    # Create generate report button
    generate_report_button = tk.Button(generate_report_window, text="Generate Report", command=generate_report)
    generate_report_button.grid(row=2, column=0, columnspan=2)

    generate_report_window.protocol('WM_DELETE_WINDOW', root.deiconify)  # Show main window on close

# Create main menu labels and buttons
welcome_label = tk.Label(root, text="Welcome to the Transaction Manager!")
welcome_label.pack()

add_transaction_button = tk.Button(root, text="Add Transaction", command=add_transaction)
add_transaction_button.pack()

visualize_button = tk.Button(root, text="Visualize Transactions", command=visualize)
visualize_button.pack()

generate_report_button = tk.Button(root, text="Generate Report", command=generate)
generate_report_button.pack()

# Initialize the dictionary
mydict = {}

root.mainloop()




"""
ISSUES:


  File "c:\GitHubProjects\BankCreditApp\Python Solution\main.py", line 207, in submit_transaction
    transaction_date = transaction_date_entry.get_date().strftime('%Y-%m-%d')  # Convert date to string
NameError: name 'transaction_date_entry' is not defined

"""