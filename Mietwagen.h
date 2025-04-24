#pragma once
#include <string>
#include <vector>
#include "Fahrt.h"

class Mietwagen
{
private:
    std::string string;
    std::string kennzeichnen;
    int sitze;
    std::vector<Fahrt> fahrtenbuch;

public:
    Mietwagen();
    Mietwagen(std::string name, std::string kennz, int sitze);


    void anmieten(Fahrt f);
    void fahrtAnzeigen(int nummer);
    void alleFahrtenAnzeigen();
    bool nummerPruefen(int nummer);
    bool fahrtLoeschen(int nummer);
    bool verfuegbarkeitPruefen(Fahrt f);
    void fahrzeugAnzeigen();
    std::string getstring();
    void sortiereFahrten(bool aufsteigend);

};
