#ifndef AUTOVERMIETUNG_H
#define AUTOVERMIETUNG_H
using namespace std;

#include <vector>
#include "Mietwagen.h"

class Autovermietung {
private:
    vector<Mietwagen*> fahrzeuge;

public:
    Autovermietung();
    ~Autovermietung();
    void dialog();
    Mietwagen* mietwagenSuchen();
};

#endif
