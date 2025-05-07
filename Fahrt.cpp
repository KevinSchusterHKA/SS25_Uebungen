#include "Fahrt.h"
#include <iostream>

Fahrt::Fahrt(int buchungsnummer, std::string kunde, int abholdatum, int abgabedatum)
    : buchungsnummer(buchungsnummer), kunde(kunde), abholdatum(abholdatum), abgabedatum(abgabedatum) {}

int Fahrt::getAbholdatum() const { return abholdatum; }
int Fahrt::getAbgabedatum() const { return abgabedatum; }
int Fahrt::getBuchungsnummer() const { return buchungsnummer; }
std::string Fahrt::getKunde() const { return kunde; }

void Fahrt::anzeigen() const {
    std::cout << "Nr. " << buchungsnummer << ", Kunde: " << kunde
              << ", von " << abholdatum << " bis " << abgabedatum << "\n";
}
