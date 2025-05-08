#ifndef FAHRT_H
#define FAHRT_H

#include <string>
using namespace std;

class Fahrt {
private:
    int nummer;
    string kunde;
    int abholdatum;
    int abgabedatum;

public:
    Fahrt(int nummer, string kunde, int abhol, int abgabe);
    void anzeigen();
    int getNummer();
    int getAbholdatum();
    int getAbgabedatum();
    string getKunde() const;



};

#endif
