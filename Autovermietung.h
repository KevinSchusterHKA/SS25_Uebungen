#ifndef Autovermietung_H
#define Autovermietung_H
#include <string>
#include <vector>
#include "Mietwagen.h"

using namespace std;

// Add necessary includes and declarations here

class Autovermietung {
private:
    vector<Mietwagen*> fahrzeuge;
    
public:
Autovermietung();
~Autovermietung();
void dialog();
Mietwagen* mietwagenSuchen();
void fahrzeugeAnzeigen(int order);
vector<Mietwagen*> sortbymarke(int order);
};

#endif