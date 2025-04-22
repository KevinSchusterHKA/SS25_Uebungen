#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Fahrt.cpp"

using namespace std;

class Mietwagen {
private:
    string marke;
    string kennzeichen;
    int sitze;
    vector<Fahrt> fahrtenbuch;

public:
    Mietwagen() {}

    Mietwagen(string marke, string kennzeichen, int sitze)
        : marke(marke), kennzeichen(kennzeichen), sitze(sitze), fahrtenbuch(vector<Fahrt>()) {}

    //Getter und Setter
    string getMarke() { return marke; }
    void setMarke(string marke) { marke = marke; }

    string getKennzeichen() { return kennzeichen; }
    void setKennzeichen(string kennzeichen) { kennzeichen = kennzeichen; }

    int getSitze() { return sitze; }
    void setSitze(int sitze) { sitze = sitze; }

    vector<Fahrt> getFahrtenbuch() { return fahrtenbuch; }
    void setFahrtenbuch(vector<Fahrt> fahrtenbuch) { fahrtenbuch = fahrtenbuch; }
    
    // Methode um eine neue Fahrt hinzuzufügen
    void anmieten(Fahrt f) {
        if(verfuebarkeitPruefen(f) == false) {
            cout << "Fahrzeug ist nicht verfügbar!" << endl;
            return; 
        }
        fahrtenbuch.push_back(f); 
        cout << "Fahrt mit Nummer " << f.getNummer() << " wurde hinzugefügt." << endl;
    }

    // Methode um die Fahrzeugdaten in der Konsole anzuzeigen
    // Gibt die Marke, das Kennzeichen und die Anzahl der Sitze aus
    void fahrzeugAnzeigen() {
        cout << "---->Fahrzeug Marke: " << marke <<
        ", Fahrzeug Kennzeichen: " << kennzeichen << 
        ", Anzahl Sitze: " << sitze << endl;
    }

    // Methode um eine Bestimmte Fahrt mit der gegebenen Nummer anzuzeigen
    void fahrtAnzeigen(int nummer){
        if (nummer >= 0 && nummer < fahrtenbuch.size()) {
            Fahrt fahrt = fahrtenbuch[nummer];
            fahrt.anzeigen();
        } else {
            cout << "Ungültige Fahrtnummer!" << endl;
        }
    }

    // Methode um alle Fahrten anzuzeigen
    void alleFahrtenAnzeigen() {
        cout << "--->Fahrzeug " << getMarke()  << " mit dem Kennzeichen " << getKennzeichen() << " hatte folgende fahrten: " << endl;
        cout << "Anzahl Fahrten: " << fahrtenbuch.size() << endl;
        for (Fahrt f : fahrtenbuch) {
            f.anzeigen();
            cout << endl;
        }
    }

    // Methode um zu schauen ob die Fahrt mit der gegebenen Nummer existiert
    // Gibt true zurück, wenn die Nummer existiert, sonst false
    bool nummerPruefen(int nummer) {
        for (Fahrt f : fahrtenbuch) {
            if (f.getNummer() == nummer) {
                return true; 
            }
        }
        return false;
    }

    // Methode um eine Fahrt mit der gegebenen Nummer zu löschen
    // Gibt true zurück, wenn die Fahrt erfolgreich gelöscht wurde, sonst false
    bool fahrtLoeschen(int nummer) {
        for (size_t i = 0; i < fahrtenbuch.size(); ++i) {
            if (fahrtenbuch[i].getNummer() == nummer) {
                fahrtenbuch.erase(fahrtenbuch.begin() + i);
                return true; 
            }
        }
        return false; 
    }

    // Methode um die Verfügbarkeit des Fahrzeugs zu prüfen
    // Gibt true zurück, wenn das Fahrzeug verfügbar ist, sonst false
    bool verfuebarkeitPruefen(Fahrt f) {
        for (Fahrt fahrt : fahrtenbuch) {
            if (fahrt.getAbholdatum() <= f.getAbgabedatum() && f.getAbgabedatum() <= fahrt.getAbgabedatum()) {
                return false; 
            }
            if (fahrt.getAbholdatum() <= f.getAbholdatum() && f.getAbholdatum() <= fahrt.getAbgabedatum()) {
                return false; 
            }
            if (f.getAbholdatum() <= fahrt.getAbholdatum() && fahrt.getAbholdatum() <= f.getAbgabedatum()) {
                return false; 
            }  
        }
        return true; 
    }

};