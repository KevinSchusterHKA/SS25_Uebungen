#include <iostream>
#include "Autovermietung.h"
using namespace std;

Autovermietung::Autovermietung() {
	vector<string> kunden = { "Roald,Amundsen","Jacques,Cousteau","David,Livingstone" };
	vector<string> automarken = { "Jeep","Chrysler","Rolls-Royce" };
	vector<string> kennzeichen = { "KA-PJ-1015","KA-PJ-1016","KA-PJ-1017" };
	
	for (int i = 0; i < 3; i++) {
		Mietwagen* fahrzeug = new Mietwagen(automarken[i], kennzeichen[i], 5);
		fahrzeuge.push_back(fahrzeug);

		Fahrt f(i + 1000, kunden[i], 20250401 + i, 20250410 + i);
		fahrzeuge[i]->anmieten(f);
	}
}

Autovermietung::~Autovermietung() {
	for (int i = 0; i < fahrzeuge.size(); i++) {
		delete fahrzeuge[i];
	}
	cout << "Vielen Dank" << endl;
}

int Autovermietung::mietwagenSuchen() {
	int index = 0;

	do {	//Muss richitiger index geben
		cout << "Welches Fahrzeug (indexNr)? ";
		cin >> index;

		if (index < 0 || index >= fahrzeuge.size()) {
			cout << "index existiert nicht" << endl;
		}
	} while (index < 0 || index >= fahrzeuge.size());

	fahrzeuge[index]->fahrzeugAnzeigen();
	return index;
}

void Autovermietung::dialog() {
	int wahl = 0; bool beendet = false;
	int buchungsnummer, abholdatum, abgabedatum, index, richtung;
	string kunde;

	Mietwagen* fahrzeug; // = new Mietwagen();
	//fahrzeuge.push_back(fahrzeug);


	do {
		cout << "1: Fahrzeug mieten \n2: Fahrt anzeigen \n3: Alle Fahrten anzeigen \n4: Fahrt loeschen \n5: Fahrzeug hinzufuegen \n6: Alle Fahrzeuge ausgeben\n0: Programm beenden" << endl;
		cin >> wahl;

		switch (wahl) {
		case 1: {	//bracket weil Fahrt in case 1 deklariert ist
			index = mietwagenSuchen();	//index
			do {
				cout << "Buchungsnummer? "; cin >> buchungsnummer;
			} while (fahrzeuge[index]->nummerPruefen(buchungsnummer));

			cout << "Kunde (Nachname, Vorname)? "; cin >> kunde;
			cout << "Abholdatum (yyyymmdd) ? "; cin >> abholdatum;
			cout << "Abgabedatum (yyyymmdd) ? "; cin >> abgabedatum;

			//ob dessen „abholdatum“ vor dessen „abgabedatum“ liegt
			if (abholdatum > abgabedatum) {
				cout << "Abholung liegt vor dem Abgabedatum: Buchung wird abgebrochen \n\n";
				break;
			}

			Fahrt f(buchungsnummer, kunde, abholdatum, abgabedatum);

			fahrzeuge[index]->anmieten(f);	
			break;
		}
			
		case 2:
			index = mietwagenSuchen();	//index
			cout << "Buchungsnummer? "; cin >> buchungsnummer;
			fahrzeuge[index]->fahrtAnzeigen(buchungsnummer);
			break;
		case 3:
			index = mietwagenSuchen();	//index
			cout << "Alphabetische Ausgabe (0: absteigend, 1:aufsteigend): "; cin >> richtung;
			fahrzeuge[index]->insertionSort(richtung);
			fahrzeuge[index]->alleFahrtenAnzeigen();
			break;

		case 4:
			index = mietwagenSuchen();	//index
			do {
				cout << "Buchungsnummer? "; cin >> buchungsnummer;
			} while (fahrzeuge[index]->fahrtLoeschen(buchungsnummer));
			break;

		case 5:
			fahrzeug = new Mietwagen();
			fahrzeuge.push_back(fahrzeug);
			break;

		case 6:
			cout << "Alphabetische Ausgabe (0: absteigend, 1:aufsteigend): "; cin >> richtung;
			for (int i = 0; i < fahrzeuge.size(); i++) {
				cout << "*****************************" << endl;
				fahrzeuge[i]->insertionSort(richtung);
				fahrzeuge[i]->fahrzeugAnzeigen();
				fahrzeuge[i]->alleFahrtenAnzeigen();
			}
			break;

		case 0:
			cout << "Programm wird beendet" << endl;
			beendet = true;	//fertig
			break;

		default:
			cout << "Ungueltige Eingabe!" << endl << endl;
			break;
		}

	} while (!beendet);	//fertig
}