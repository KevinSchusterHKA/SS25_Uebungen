#ifndef AUTOVERMIETUNG_H
#define AUTOVERMIETUNG_H

#include "mietwagen.h"
#include <vector>
using namespace std;

class Autovermietung {
private:
    vector<Mietwagen*> fahrzeuge;

public:
    Autovermietung();
    ~Autovermietung();
    void dialog();
    Mietwagen* mietwagenSuchen();
    void sortiereFahrzeuge(bool aufsteigend);
    void addFahrzeug(Mietwagen* wagen);


};

#endif
