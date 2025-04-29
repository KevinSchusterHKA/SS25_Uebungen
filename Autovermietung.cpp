// Autovermietung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Mietwagen.h"
#include "Autovermietung.h"


Autovermietung::Autovermietung() {

}


Autovermietung::~Autovermietung() {
	for (Mietwagen *m : fahrzeuge) {
		delete m;
	}
	std::cout << "Vielen Dank!" << std::endl;

}

void Autovermietung::dialog() {
	Mietwagen *fahrzeug = new Mietwagen;

	fahrzeuge.push_back(fahrzeug);
	bool running = true;
	while (running) {
		std::cout << "1: Fahrzeug Mieten" << std::endl <<
			"2: Fahrt anzeigen" << std::endl <<
			"3: Alle Fahrten anzeigen" << std::endl <<
			"0: Programm beenden" << std::endl;
		int wahl;
		std::cin >> wahl;

		int nummer, abholdatum, abgabedatum;
		std::string kunde;
		
		switch (wahl) {
			case 1: {


			std::cout << "Buchungsnummer: ";
			std::cin >> nummer;
			std::cout << std::endl;
			if (fahrzeug->nummerPruefen(nummer)) {
				std::cout << "Nummer existiert bereits!!!" << std::endl;
				break;
			}

			std::cout << "Kunde (Nachname;Vorname): ";
			std::cin >> kunde;
			std::cout << std::endl;

			std::cout << "Abholdatum: ";
			std::cin >> abholdatum;
			std::cout << std::endl;

			std::cout << "Abgabedatum: ";
			std::cin >> abgabedatum;
			std::cout << std::endl;
			
				Fahrt fahrt(nummer, kunde, abholdatum, abgabedatum);
				fahrzeug->anmieten(fahrt);
			
			break;
		}

			case 2:
				std::cout << "Geben sie eine Buchungsnummer an: ";
				std::cin >> nummer;
				fahrzeug->fahrtAnzeigen(nummer);
				break;

			case 3:
				fahrzeug->alleFahrtenAnzeigen();
				break;

			case 0:
				running = false;
				break;
			default:

				break;
		}


	}
}





//test
// Dies ist ein weiterer Test
// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
