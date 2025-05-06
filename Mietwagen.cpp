#include "Mietwagen.h"
#include <iostream>
Mietwagen::Mietwagen() {
	std::cout << "Geben sie die Marke an: ";
	std::cin>>marke;
	std::cout << std::endl;
	std::cout << "Geben sie das Kennzeichen an: ";
	std::cin >> kennzeichen;
	std::cout << std::endl;
	std::cout << "Geben sie die Anzahler der Sitze an: ";
	std::cin >> sitze;
	std::cout << std::endl;
	

	std::cout << "Marke: " << marke << std::endl <<
		"Kennzeichen: " << kennzeichen << std::endl <<
		"Anzahl Sitze: " << sitze << std::endl;

}

void Mietwagen::anmieten(Fahrt fahrt) {

	for (Fahrt f : fahrtenbuch) {
		if (!f.verfuegbarkeitPruefen(fahrt)) {
			
			std::cout << "Buchung wegen Ueberschneidung nicht erfolgt!";
			return;
		}
	}
	if (fahrt.getAbholdatum() > fahrt.getAbgabedatum()) {
		std::cout << "Abgabedatum vor Abholdatum!!" << std::endl;
		return;
	}
	fahrtenbuch.push_back(fahrt);
	std::cout << "Es wurde erfolgreich eine fahrt angelegt" << std::endl;

}

void Mietwagen::fahrtAnzeigen(int nummer) {
	bool exists = false;
	for (Fahrt f : fahrtenbuch) {
		if (f.getNummer() == nummer) {
			f.anzeigen();
			exists = true;
		}
	}

	if (!exists) {
		std::cout << "Fahrt existiert nicht!" << std::endl;
	}
}

void Mietwagen::alleFahrtenAnzeigen() {
	for (Fahrt f : fahrtenbuch) {
		
		f.anzeigen();
		std::cout << "____________________________" << std::endl;

	}
}

bool Mietwagen::nummerPruefen(int nummer) {
	
	for (Fahrt f : fahrtenbuch) {
		if (f.getNummer() == nummer) {

			return true;
		}
	}

	return false;
}

bool Mietwagen::fahrtLoeschen(int nummer) {
	bool exists = false;
	for (int i = 0; i < fahrtenbuch.size(); i++) {
		if (fahrtenbuch[i].getNummer() == nummer) {
			
			exists = true;
			fahrtenbuch.erase(fahrtenbuch.begin() + i);
		}
	}

	if (!exists) {
		std::cout << "Nummer existiert nicht";
	}
	return exists;
}

void Mietwagen::fahrzeugAnzeigen() {
	std::cout << "Marke: " << marke << " Kennzeichen: " << kennzeichen<<std::endl;

}