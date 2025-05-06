#pragma once
#include <string>

class Fahrt {
private:
    int nummer;
    std::string kunde;
    int abholdatum;
    int abgabedatum;

public:
    Fahrt(int n, std::string k, int ab, int bis);
    void anzeigen();
    int getNummer();
    std::string getKunde();
    int getAbholDatum();
    int getAbgabeDatum();
};