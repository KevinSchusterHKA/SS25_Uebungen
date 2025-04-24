#pragma once
#include "Fahrt.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Mietwagen
{
private:
	string Kennzeichen;
	string Marke;
	int Sitze = 4;
	vector <Fahrt> Fahrtenbuch;

public:
	Mietwagen(string marke, string kennzeichen, int sitze);

	void printFahrzeug();
	void alleFahrtenAnzeigen(int dir);
	void anmieten(Fahrt fahrt);
	string getKennzeichen();
	int bnrPruefen(int bnr);
	void fahrtAnzeigen(int bnr);
	bool fahrtLoeschen(int bnr);
	int verfuegbarkeitPruefen(Fahrt fahrt);

	void insertionSort(vector<Fahrt> &object);
	void insertionSort(vector<Mietwagen*>& object);
};

