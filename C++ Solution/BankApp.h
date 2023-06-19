#pragma once

class ProduseCumparate {
private:
    std::string nume_cont;
    std::string login;
    std::string nume_produs;
    double suma_platita;
    int numar_rate;

public:
    ProduseCumparate(const std::string& numeCont, const std::string& login);

    void inregistrare();
    void autentificare();
    void introducereProdus();
    std::string getCurrentDate();
    double calculSumaLunaraPlata();
};