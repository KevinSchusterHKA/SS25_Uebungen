#pragma once
#include "Fahrt.h"
#include <string>
#include <vector>
using namespace std;

class Mietwagen {
private:
	string marke;
	string kennzeichen;
	int sitze;
	vector<Fahrt> fahrtenbuch;

public:
	Mietwagen();	//konstruktor
	Mietwagen(string m, string k, int s);	//ueberladen konstruktor

	void anmieten(Fahrt f);
	void fahrtAnzeigen(int nummer);
	void alleFahrtenAnzeigen();
	bool nummerPruefen(int nummer);
	bool fahrtLoeschen(int nummer);
	bool verfuegbarkeitPruefen(Fahrt f);
	void fahrzeugAnzeigen();
	void insertionSort(int richtung);
};
