#pragma once
#include <vector>
#include "Mietwagen.h"


class Autovermietung {
private:
	std::vector<Mietwagen*> fahrzeuge;
	std::vector<Mietwagen*> sortierteFahrzeuge(bool dir);
public:
	Autovermietung();
	void dialog();
	bool mietwagenSuchen(int index);
	~Autovermietung();


};