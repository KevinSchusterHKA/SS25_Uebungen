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
		std::cout << "Fahrt existiert nicht" << std::endl;
	}
}

void Mietwagen::alleFahrtenAnzeigen() {
	for (Fahrt f : fahrtenbuch) {
		
		f.anzeigen();
		std::cout << "____________________________" << std::endl;

	}
}