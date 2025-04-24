#pragma once
#include "Mietwagen.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Vermietung
{
private:
	string Name;
	vector <Mietwagen*> Fuhrpark;
public:
	Vermietung(string name);

	void addFahrzeug(Mietwagen* fahrzeug);
	int getFahrzeug(string kennzeichen);
	void dialog();
};

