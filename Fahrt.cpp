#include "Fahrt.h"
#include <iostream>
Fahrt::Fahrt(int nummer, std::string kunde, int abholdatum, int abgabedatum) {
    this->nummer = nummer;
    this->kunde = kunde;
    this->abholdatum = abholdatum;
    this->abgabedatum = abgabedatum;
}




void Fahrt::anzeigen() {
    std::cout << "Fahrt Nummer: " << nummer << ", Kunde: " << kunde
        << ", Abholdatum: " << abholdatum
        << ", Abgabedatum: " << abgabedatum << std::endl;
}

int Fahrt::getNummer() {
    return nummer;
}
int Fahrt::getabholdatum() {
    return abholdatum;
}
int Fahrt::getabgabedatum() {
    return abgabedatum;
}
std::string  Fahrt::getkunde() {
    return kunde;
}