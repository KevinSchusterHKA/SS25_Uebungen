#include <iostream>
#include "Fahrt.h"
using namespace std;

Fahrt::Fahrt(int n, string k, int ab, int bis) {
	nummer = n;
	kunde = k;
	abholddatum = ab;
	abgabedatum = bis;
}

void Fahrt::anzeigen(void) {
	cout << "Nr." << nummer << ": Kunde " << kunde << " holt Fahrzeug am " << abholddatum << " ab und bringt es am " << abgabedatum << " zueruck" << endl;
}

int Fahrt::getNummer(void) {
	return nummer;
}

int Fahrt::getAbholddatum(void) {
	return abholddatum;
}

int Fahrt::getAbgabedatum(void) {
	return abgabedatum;
}

string Fahrt::getKunde(void) {
	return kunde;
}