#pragma once
#include <string>
#include <vector>
#include "Fahrt.h"
class Mietwagen {
private:
	std::string marke, kennzeichen;
	int sitze;
	std::vector<Fahrt> fahrtenbuch;

public:
	Mietwagen();
	void anmieten(Fahrt f);
	void fahrtAnzeigen(int nummer);
	void alleFahrtenAnzeigen();

};