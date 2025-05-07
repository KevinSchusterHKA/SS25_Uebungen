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

public:
	Mietwagen();
	void anmieten(Fahrt f);
	void fahrtAnzeigen(int nummer);
	void alleFahrtenAnzeigen();
	void fahrzeugAnzeigen();
	bool nummerPruefen(int nummer);
	bool fahrtLoeschen(int nummer);
};