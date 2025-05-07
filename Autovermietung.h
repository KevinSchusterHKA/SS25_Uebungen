#pragma once
#include <vector>
#include <string>
#include "Mietwagen.h"
#include <fstream>
#include <sstream>

class Autovermietung {
private:
    std::vector<Mietwagen*> fahrzeuge;
    std::vector<std::string> kunden;

public:
    Autovermietung();
    ~Autovermietung();

    void dialog();
    Mietwagen* mietwagenSuchen(int index);
    void fahrzeugeSortiertAusgeben(int richtung);
    void ladeDatenAusDatei(const std::string& dateiname);
    void alleFahrzeugeMitIndexAusgeben() const;
};
