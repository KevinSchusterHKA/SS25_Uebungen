#pragma once

#include <string>
#include <vector>
#include "Fahrt.h"

class Mietwagen {
private:
    std::string marke;
    std::string kennzeichen;
    int sitze;
    std::vector<Fahrt> fahrtenbuch;

public:
    Mietwagen();
    Mietwagen(std::string m, std::string k, int s, Fahrt f);
    std::string getMarke();
    std::string getKennzeichen();
    void anmieten(Fahrt f);
    void fahrtAnzeigen(int nummer);
    void alleFahrtenAnzeigen();
    bool nummerPruefen(int nummer);
    bool fahrtLoeschen();
    bool verfuegbarkeitPruefen(Fahrt f);
    void fahrzeugAnzeigen();
    void insertionsortFahrten(int sort);
};