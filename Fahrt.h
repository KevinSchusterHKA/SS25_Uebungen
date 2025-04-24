#pragma once
#include <string>
class Fahrt
{
public:
    int nummer;
    std::string kunde;
    int abholdatum;
    int abgabedatum;









    Fahrt(int n, std::string k, int ab, int bis);
    void anzeigen();
    int getNummer();
    int getabholdatum();
    int getabgabedatum();

    std::string getkunde();
};


