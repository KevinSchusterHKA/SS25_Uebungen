#ifndef MIETWAGEN_H
#define MIETWAGEN_H
using namespace std;

#include <string>
#include <vector>
#include "Fahrt.h"

class Mietwagen {
private:
    string marke;
    string kennzeichen;
    int sitze;
    vector<Fahrt> fahrtenbuch;

public:
    Mietwagen();
    void anmieten();
    void fahrtenAnzeigen() const;
    bool nummerPruefen(int nummer) const;
    bool fahrtLoeschen();
    void fahrzeugAnzeigen() const;
    bool verfuegbarkeitPruefen(const Fahrt& neueFahrt) const;
    void fahrtenSortierenUndAnzeigen() const;
};

#endif

