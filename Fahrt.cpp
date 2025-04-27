#include "Fahrt.h"
#include <iostream>

// Konstruktor
Fahrt::Fahrt(int n, const std::string& k, int ab, int bis)
    : nummer(n), kunde(k), abholdatum(ab), abgabedatum(bis)
{
}

// Ausgabe der Fahrtdetails
void Fahrt::anzeigen() const
{
    std::cout << "Fahrt " << nummer << ": " << kunde
        << ", Abholung: " << abholdatum
        << ", Abgabe: " << abgabedatum << std::endl;
}

// Getter-Methoden
int Fahrt::getNummer() const { return nummer; }
int Fahrt::getAbholdatum() const { return abholdatum; }
int Fahrt::getAbgabedatum() const { return abgabedatum; }
std::string Fahrt::getKunde() const { return kunde; }
