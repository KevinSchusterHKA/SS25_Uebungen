#include <iostream>
#include "Mietwagen.h"
using namespace std;

Mietwagen::Mietwagen() {	//konstruktor
	cout << "Neues Fahrzeug:" << endl;
	
	cout << "Automarke? ";	cin >> marke;
	cout << "KFZ-Kennzeichen? ";	cin >> kennzeichen;
	cout << "Sitze? ";	cin >> sitze;

	cout << "--> Fahrzeug " << marke << " mit KFZ-Kennzeichen " << kennzeichen << " und " << sitze << " Sitzen wurde aufgenommen " << endl << endl;
}

Mietwagen::Mietwagen(string m, string k, int s) {
	marke = m;
	kennzeichen = k;
	sitze = s;
}

void Mietwagen::anmieten(Fahrt f) {
	if (verfuegbarkeitPruefen(f)) {
		cout << "Buchung wegen Ueberschneidung nicht erfolgt!" << endl << endl;
	}
	else {
		fahrtenbuch.push_back(f);
		cout << "Fahrt " << f.getNummer() << " erfolgreich angelegt\n\n";
	}
}

void Mietwagen::fahrtAnzeigen(int nummer) {
	bool nicht_existiert= true;

	for (int i = 0; i < fahrtenbuch.size(); i++) {	//Sehen nur die richtiger fahrt
		if (fahrtenbuch[i].getNummer() == nummer) {
			fahrtenbuch[i].anzeigen();
			cout << endl;
			nicht_existiert = false;
		}
	}
	if (nicht_existiert) { cout << "Fahrt exisitert nicht\n\n"; }
}

void Mietwagen::alleFahrtenAnzeigen(void) {
	if (fahrtenbuch.size() == 0) { cout << "Mietwagen wurde noch nicht verliehen\n"; }	//Wenn lehr ist
	for (int i = 0; i < fahrtenbuch.size(); i++) {	//ganze fahrtenbuch
		fahrtenbuch[i].anzeigen();
		cout << "----------------------------------------\n";
	}
	cout << endl;
}

bool Mietwagen::nummerPruefen(int nummer) {
	for (int i = 0; i < fahrtenbuch.size(); i++) {
		if (nummer == fahrtenbuch[i].getNummer()) {
			cout << "Buchungsnummer ist schon vergeben, bitte neu eingeben" << endl;
			return true;
		}
	}
	return false;
}

bool Mietwagen::fahrtLoeschen(int nummer) {
	for (int i = 0; i < fahrtenbuch.size(); i++) {
		if (nummer == fahrtenbuch[i].getNummer()) {
			fahrtenbuch.erase(fahrtenbuch.begin()+i);
			cout << "Buchungsnummer " << nummer << " wurde geloescht" << endl << endl;
			return false;	//erfolgreich
		}
	}
	//Fehler
	cout << "Buchungsnummer existiert nicht, bitte neu eingeben" << endl;
	return true;	
}

bool Mietwagen::verfuegbarkeitPruefen(Fahrt f) {
	int neuAbholung = f.getAbholddatum();
	int neuAbgabe = f.getAbgabedatum();

	for (int i = 0; i < fahrtenbuch.size(); i++) {
		int altAbholung = fahrtenbuch[i].getAbholddatum();
		int altAbgabe = fahrtenbuch[i].getAbgabedatum();

		if ((neuAbgabe >= altAbholung && neuAbgabe <= altAbgabe) ||			//die neue Abgabe zwischen vorhandener Abholung UND vorhandener Abgabe liegt
			(neuAbholung >= altAbholung && neuAbholung <= altAbgabe) ||		//die neue Abholung zwischen vorhandener Abholung UND vorhandener Abgabe liegt 
			(altAbholung >= neuAbholung && altAbholung <= neuAbgabe)) {		//die vorhandene Abholung zwischen neuer Abholung UND neuer Abgabe liegt
			return true;	//Überschneidung gefunden
		}
	}
	return false;	// Keine Überschneidung gefunden
}

void Mietwagen::fahrzeugAnzeigen(void) {
	cout << "--> Fahrzeug " << marke << " mit KFZ-Kennzeichen " << kennzeichen << endl;
}

void Mietwagen::insertionSort(int richtung) {
	int j;
	for (int i = 0; i < fahrtenbuch.size(); i++) {	//alle Element
		Fahrt kopie = fahrtenbuch[i];
		
		for (j = i - 1; j >= 0 &&
			((richtung == 1 && fahrtenbuch[j].getKunde() < kopie.getKunde()) ||		//aufsteigend
				(richtung == 0 && fahrtenbuch[j].getKunde() > kopie.getKunde()));	//absteigend
			j--) {
			fahrtenbuch[j + 1] = fahrtenbuch[j];	//verschieben recht
		}
		fahrtenbuch[j + 1] = kopie;
	}
}