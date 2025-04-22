#pragma once

#include <string>
#include <iostream>

using namespace std;

class Fahrt {
private:
    int nummer;
    string kunde;
    int abholdatum;
    int abgabedatum;

public:
    Fahrt(int nummer, string kunde, int abholdatum, int abgabedatum)
        : nummer(nummer), kunde(kunde), abholdatum(abholdatum), abgabedatum(abgabedatum) {}

    // Getter und Setter
    int getNummer() { return nummer; }
    void setNummer(int n) { nummer = n; }

    string getKunde() { return kunde; }
    void setKunde(string k) { kunde = k; }

    int getAbholdatum() { return abholdatum; }
    void setAbholdatum(int abhol) { abholdatum = abhol; }

    int getAbgabedatum() { return abgabedatum; }
    void setAbgabedatum(int abgabe) { abgabedatum = abgabe; }

    // Methode zur Anzeige der Fahrtinformationen in der Konsole
    void anzeigen(){
        cout << "Fahrt Nummer: " << nummer << 
                   " , Kunde: " << kunde  <<
                   " , Abholdatum: " << abholdatum << 
                   " , Abgabedatum: " << abgabedatum
                   << endl;	
    }

};
