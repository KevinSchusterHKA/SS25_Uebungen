#include "Fahrt.h"
#include <iostream>
using namespace std;

Fahrt::Fahrt(int nummer, string kunde, int abhol, int abgabe)
    : nummer(nummer), kunde(kunde), abholdatum(abhol), abgabedatum(abgabe) {}

void Fahrt::anzeigen() {
    cout << "Fahrt #" << nummer << " mit " << kunde
         << " von " << abholdatum << " bis " << abgabedatum << endl;
}

int Fahrt::getNummer() {
    return nummer;


}

int Fahrt::getAbholdatum() {
    return abholdatum;
}

int Fahrt::getAbgabedatum() {
    return abgabedatum;
}
string Fahrt::getKunde() const {
    return kunde;
}


