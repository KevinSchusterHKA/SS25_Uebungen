#pragma once
#include <vector>
#include "Mietwagen.h"


class Autovermietung {
private:
	std::vector<Mietwagen*> fahrzeuge;
public:
	Autovermietung();
	void dialog();



};