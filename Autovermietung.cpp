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
			"4: Fahrt löschen" << std::endl <<
			"5: Fahrzeug hinzufuegen" << std::endl <<
			"6: Alle Fahrzeuge ausgeben" << std::endl <<
			"0: Programm beenden" << std::endl;
		int wahl;
		std::cin >> wahl;

		int index,nummer, abholdatum, abgabedatum;
		bool dir;
		std::string kunde;
		
		switch (wahl) {
			case 1: {

				std::cout << "Welches Fahrzeug (indexNr)?" << std::endl;
				std::cin >> index;
				if (!mietwagenSuchen(index)) {
					std::cout << "Mietwagen existiert nicht! "<<std::endl;
					break;
				}
				fahrzeug = fahrzeuge[index];
				fahrzeug->fahrzeugAnzeigen();

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

				std::cout << "Welches Fahrzeug (indexNr)?" << std::endl;
				std::cin >> index;
				if (!mietwagenSuchen(index)) {
					std::cout << "Mietwagen existiert nicht! " << std::endl;
					break;
				}
				fahrzeug = fahrzeuge[index];

				std::cout << "Geben sie eine Buchungsnummer an: ";
				std::cin >> nummer;
				fahrzeug->fahrtAnzeigen(nummer);
				break;

			case 3:
				std::cout << "Welches Fahrzeug (indexNr)?" << std::endl;
				std::cin >> index;
				if (!mietwagenSuchen(index)) {
					std::cout << "Mietwagen existiert nicht! " << std::endl;
					break;
				}

				std::cout << "Alphabetische Ausgabe (0: absteigend, 1: aufsteigend):" << std::endl;
				std::cin >> dir;
				

				fahrzeug = fahrzeuge[index];
				fahrzeug->alleFahrtenAnzeigen(dir);
				break;
				
			case 4:
				std::cout << "Welches Fahrzeug (indexNr)?" << std::endl;
				std::cin >> index;
				if (!mietwagenSuchen(index)) {
					std::cout << "Mietwagen existiert nicht! " << std::endl;
					break;
				}
				fahrzeug = fahrzeuge[index];
				std::cout << "Geben sie eine Buchungsnummer an: ";
				std::cin >> nummer;
				if (fahrzeug->fahrtLoeschen(nummer)) {
					std::cout << "Fahrzeug wurde gelöscht"<<std::endl;
				}
				break;

			case 5: {
				Mietwagen* m = new Mietwagen();
				fahrzeuge.push_back(m);

				break;
			}
			case 6:

				std::cout << "Alphabetische Ausgabe (0: absteigend, 1: aufsteigend):" << std::endl;
				std::cin >> dir;
				for (Mietwagen* m : sortierteFahrzeuge(dir)) {
					
					m->fahrzeugAnzeigen();
					m->alleFahrtenAnzeigen(dir);
					
				}
				break;

			case 0:
				running = false;
				break;
			default:

				break;
		}


	}
}

bool Autovermietung::mietwagenSuchen(int index) {
	if (index >= 0 && index < fahrzeuge.size()) {
		return true;
	}
	else {
		
		return false;
	}
}



std::vector<Mietwagen*> Autovermietung::sortierteFahrzeuge(bool dir) {
	std::vector<Mietwagen*> tmp = fahrzeuge;  // Kopie vom Original

	if (dir) {
		for (int i = 1; i < tmp.size(); ++i) {
			Mietwagen* key = tmp[i];
			int j = i - 1;

			// Aufsteigend sortieren nach vollständigem Kundennamen
			while (j >= 0 && tmp[j]->getKennzeichen() > key->getKennzeichen()) {
				tmp[j + 1] = tmp[j];
				j--;
			}
			tmp[j + 1] = key;
		}
	}
	else {
		for (int i = 1; i < tmp.size(); ++i) {
			Mietwagen* key = tmp[i];
			int j = i - 1;

			// Absteigend sortieren nach vollständigem Kundennamen
			while (j >= 0 && tmp[j]->getKennzeichen() < key->getKennzeichen()) {
				tmp[j + 1] = tmp[j];
				j--;
			}
			tmp[j + 1] = key;
		}
	}
	return tmp;
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
