#ifndef FAHRT_H
#define FAHRT_H
using namespace std;

#include <string>

class Fahrt {
private:
    int buchungsnummer;
    string kunde;
    int abholdatum;
    int abgabedatum;

public:
    Fahrt(int nummer, const string& kunde, int abhol, int abgabe);

    int getBuchungsnummer() const;
    int getAbholdatum() const;
    int getAbgabedatum() const;
    string getKunde() const;
    void anzeigen() const;
};

#endif

