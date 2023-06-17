#include <iostream>
#include <string>
#include <ctime>

std::string getCurrentDate() {
	std::time_t now = std::time(nullptr); // Obținem timpul curent
	std::tm currentTime;
	localtime_s(&currentTime, &now); // Convertim timpul într-o structură tm

	int day = currentTime.tm_mday; // Ziua curentă
	int month = currentTime.tm_mon + 1; // Luna curentă (indicele începe de la 0, așa că adăugăm 1)
	int year = currentTime.tm_year + 1900; // Anul curent (numărul de ani de la 1900)

	// Construim un șir de caractere în formatul DD/MM/YYYY
	std::string date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);

	return date;
}


int main() {
	std::string nume_cont{};
	std::cout << "Va rugam sa va inregistrati: ";
	std::cin >> nume_cont;
	std::cout << std::endl;

	std::string login{};
	std::cout << "Va rugam sa va autentificati: ";
	std::cin >> login;
	std::cout << std::endl;

	if (login != nume_cont) {
		std::cout << "Acest cont este invalid - va rugam incercati din nou" << std::endl;
	} else {
		std::cout << "Bun venit in aplicatia BankCreditApp" << std::endl;
	}
	std::cout << std::endl;

	std::string currentDate = getCurrentDate();
	std::cout << "Data curenta este: " << currentDate << std::endl;
	std::cout << "Va rugam sa intoduceti data la care a fost facuta achizitia: ";
	std::cout << std::endl;

	double suma_platita;
	std::cout << "Va rugam sa introduceti suma platita pe achizitie: RON ";
	std::cin >> suma_platita;
	std::cout << std::endl;

	if (suma_platita < 200) {
		std::cout << "Suma trebuie platita intr-o singura rata" << std::endl;
	}
	else {
		std::cout << "Puteti alege ca suma sa fie platita in 4, 6, 8, 10 sau 12 rate." << std::endl;
		std::cout << "Va rugam sa alegeti numarul de rate convenabil pentru dumneavoastra" << std::endl;

		int numar_rate;
		std::cout << "Va rugam sa specificati numarul de rate dorit: " << std::endl;
		std::cin >> numar_rate;
		std::cout << std::endl;

		double suma_lunara_de_plata = 0;

		switch (numar_rate) {
		case 4:
			suma_lunara_de_plata = suma_platita / numar_rate;
			std::cout << suma_lunara_de_plata;
			std::cout << std::endl;
			break;
		case 6:
			suma_lunara_de_plata = suma_platita / numar_rate;
			std::cout << suma_lunara_de_plata;
			std::cout << std::endl;
			break;
		case 8:
			suma_lunara_de_plata = suma_platita / numar_rate;
			std::cout << suma_lunara_de_plata;
			std::cout << std::endl;
			break;
		case 10:
			suma_lunara_de_plata = suma_platita / numar_rate;
			std::cout << suma_lunara_de_plata;
			std::cout << std::endl;
			break;
		case 12:
			suma_lunara_de_plata = suma_platita / numar_rate;
			std::cout << suma_lunara_de_plata;
			std::cout << std::endl;
			break;
		default:
			std::cout << "Operatiune invalida - Va rugam incercati din nou" << std::endl;
			std::cout << std::endl;
			break;
		}
	}
	std::cout << std::endl;
	return 0;
}
