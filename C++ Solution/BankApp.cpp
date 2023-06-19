#include <iostream>
#include <string>
#include <ctime>
#include "BankApp.h"


ProduseCumparate::ProduseCumparate(const std::string& numeCont, const std::string& login)
    : nume_cont(numeCont), login(login), suma_platita(0), numar_rate(0) {
    // Inițializarea membrilor în constructor
}


void ProduseCumparate::inregistrare() {
    std::cout << "Va rugam sa va inregistrati: ";
    std::cin >> nume_cont;
    std::cout << std::endl;
}

void ProduseCumparate::autentificare() {
    std::cout << "Va rugam sa va autentificati: ";
    std::cin >> login;
    std::cout << std::endl;

    if (login != nume_cont) {
        std::cout << "Acest cont este invalid - va rugam incercati din nou" << std::endl;
    }
    else {
        std::cout << "Bun venit in aplicatia BankCreditApp" << std::endl;
    }
    std::cout << std::endl;
}

void ProduseCumparate::introducereProdus() {
    std::cout << "Va rugam introduceti numele produsului cumparat: ";
    std::cin >> nume_produs;
    std::cout << std::endl;
}

std::string ProduseCumparate::getCurrentDate() {
    std::time_t now = std::time(nullptr);
    std::tm currentTime;
    localtime_s(&currentTime, &now);

    int day = currentTime.tm_mday;
    int month = currentTime.tm_mon + 1;
    int year = currentTime.tm_year + 1900;

    std::string date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);

    std::cout << "Data curenta la care a fost facuta achizitia (" << nume_produs << ") este: " << date << std::endl;

    return date;
}

double ProduseCumparate::calculSumaLunaraPlata() {
    std::cout << "Va rugam sa introduceti suma platita pe achizitie: RON ";
    std::cin >> suma_platita;
    std::cout << std::endl;

    double suma_lunara_de_plata = 0;

    if (suma_platita < 200) {
        std::cout << "Suma trebuie platita intr-o singura rata RON: " << suma_platita << std::endl;
    }
    else {
        std::cout << "Puteti alege ca suma sa fie platita in 4, 6, 8, 10 sau 12 rate." << std::endl;
        std::cout << "Va rugam sa alegeti numarul de rate convenabil pentru dumneavoastra" << std::endl;

        std::cout << "Va rugam sa specificati numarul de rate dorit: ";
        std::cin >> numar_rate;
        std::cout << std::endl;

        switch (numar_rate) {
        case 4:
        case 6:
        case 8:
        case 10:
        case 12:
            suma_lunara_de_plata = suma_platita / numar_rate;
            std::cout << "Suma lunara de plata pentru produsul " << nume_produs << " este: " << suma_lunara_de_plata << std::endl;
            break;
        default:
            std::cout << "Operatiune invalida - Va rugam incercati din nou" << std::endl;
            std::cout << std::endl;
            break;
        }
    }

    return suma_lunara_de_plata;
}