#ifndef MIETWAGEN_H
#define MIETWAGEN_H

#include "Fahrt.h"
#include <string>
#include <vector>
using namespace std;

class Mietwagen {
private:
    string marke;
    string kennzeichen;
    int sitze;
    vector<Fahrt> fahrtenbuch;


public:
    Mietwagen();
    Mietwagen(string marke, string kennzeichen, int sitze);
    void anmietenDirekt(Fahrt f);
    void anmieten();
    void alleFahrtenAnzeigen();
    void fahrtAnzeigen(int nummer);
    bool nummerPruefen(int nummer);
    void fahrtLoeschen(int nummer);
    bool verfuegbarkeitPruefen(Fahrt f);
    void fahrzeugAnzeigen();
    void sortiereFahrten(bool aufsteigend);
    string getMarke();

};

#endif
