#include "Fahrt.h"
#include <iostream>

Fahrt::Fahrt(int n, std::string k, int ab, int bis) :nummer(n), kunde(k), abholdatum(ab), abgabedatum(bis) {}

int Fahrt::getNummer() {
    return this->nummer;
}

std::string Fahrt::getKunde() {
    return this->kunde;
}

int Fahrt::getAbholDatum() {
    return this->abholdatum;
}

int Fahrt::getAbgabeDatum() {
    return this->abgabedatum;
}

void Fahrt::anzeigen() {
   std::cout << "Buchungsnummer: " << this->nummer
        << ", Kunde: " << this->kunde
        << ", Abholung: " << this->abholdatum
        << ", Abgabe: " << this->abgabedatum << std::endl;
}