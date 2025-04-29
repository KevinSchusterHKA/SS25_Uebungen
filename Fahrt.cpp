#include "Fahrt.h"

Fahrt::Fahrt(int n, std::string k, int ab, int bis) {
	nummer = n;
	kunde = k;
	abholdatum = ab;
	abgabedatum = bis;
}

int Fahrt::getNummer() {
	return nummer;
}

void Fahrt::anzeigen() {
	std::cout << "Nr.  " << nummer << " Kunde:  " << kunde << " holt Fahrzeug am " << abholdatum << " und bringt es am " << abgabedatum << " zurück"<<std::endl;
}

int Fahrt::getAbgabedatum() {
	return abgabedatum;
}

int Fahrt::getAbholdatum() {
	return abholdatum;
}

bool Fahrt::verfuegbarkeitPruefen(Fahrt f) {

}