#pragma once
#include <string>
#include <vector>
#include "Fahrt.h"
class Mietwagen {
private:
	std::string marke, kennzeichen;
	int sitze;
	std::vector<Fahrt> fahrtenbuch;
	std::vector<Fahrt> sortierteFahrten(bool dir);
	bool verfuegbarkeitPruefen(Fahrt f);
public:
	Mietwagen();
	std::string getKennzeichen();
	void anmieten(Fahrt f);
	void fahrtAnzeigen(int nummer);
	void alleFahrtenAnzeigen(bool dir);
	void fahrzeugAnzeigen();
	bool nummerPruefen(int nummer);
	bool fahrtLoeschen(int nummer);
};