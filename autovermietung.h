#pragma once
#include <vector>
#include "Mietwagen.h"

class autovermietung
{
private:

    std::vector<Mietwagen*>  fahrzeuge;


public:

    autovermietung();
    ~autovermietung();
    void dialog();
    int mietwagenSuchen();
    std::vector<std::pair<int, Mietwagen*>> sortiereFahrzeuge(bool aufsteigend); 

};




