#pragma once
#include <string>

class Fahrt {
private:
    int buchungsnummer;
    std::string kunde;
    int abholdatum;
    int abgabedatum;

public:
    Fahrt(int buchungsnummer, std::string kunde, int abholdatum, int abgabedatum);

    int getAbholdatum() const;
    int getAbgabedatum() const;
    int getBuchungsnummer() const;
    std::string getKunde() const;

    void anzeigen() const;
};
