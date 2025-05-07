#include "Fahrt.h"
#include <iostream>
using namespace std;

Fahrt::Fahrt(int nummer, const string& kunde, int abhol, int abgabe)
    : buchungsnummer(nummer), kunde(kunde), abholdatum(abhol), abgabedatum(abgabe) {
}

int Fahrt::getBuchungsnummer() const {
    return buchungsnummer;
}

int Fahrt::getAbholdatum() const {
    return abholdatum;
}

int Fahrt::getAbgabedatum() const {
    return abgabedatum;
}

string Fahrt::getKunde() const {
    return kunde;
}

void Fahrt::anzeigen() const {
    cout << "Buchungsnummer: " << buchungsnummer
        << ", Kunde: " << kunde
        << ", Abholdatum: " << abholdatum
        << ", Abgabedatum: " << abgabedatum << endl;
}
