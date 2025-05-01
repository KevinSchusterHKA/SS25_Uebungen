#pragma once
#include "Mietwagen.h"
#include <vector>
using namespace std;

class Autovermietung {
private :
	vector<Mietwagen*> fahrzeuge;
public:
	Autovermietung();	//konstruktor
	~Autovermietung();	//destruktor
	void dialog();
	int mietwagenSuchen();
};