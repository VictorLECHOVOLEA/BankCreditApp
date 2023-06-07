#include <iostream>
#include <string>
#include <vector>

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
		std::cout << "Acest cont este invalid - va rugam incergati din nou" << std::endl;
	} else {
		std::cout << "Bun venit in aplicatia BankCreditApp" << std::endl;
	}
	std::cout << std::endl;

	std::string data_de_cumparare{};
	std::cout << "Va rugam sa intoduceti data la care a fost facuta achizitia: ";
	std::cin >> data_de_cumparare;
	std::cout << std::endl;

	double suma_platita;
	std::cout << "Va rugam sa introduceti suma platita pe achizitie: ";
	std::cin >> suma_platita;
	std::cout << " Ron" << std::endl;
	std::cout << std::endl;

	std::cout << "Puteti alege ca suma sa fie platita in 1, 4, 6, 8, 10 sau 12 rate." << std::endl;
	std::cout << "Va rugam sa alegeti numarul de rate convenavil pentru dumneavoastra" << std::endl;

	while (suma_platita < 200) {
		std::cout << "Suma trebuie platita intr-o singura rata" << std::endl;
		break;
	}
	std::cout << std::endl;

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
	return 0;
}
