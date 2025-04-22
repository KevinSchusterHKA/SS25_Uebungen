#include <iostream>
#include <string>
#include <vector>
#include "Fahrt.cpp"
#include "Mietwagen.cpp"
#include "Insertionsort.cpp"

using namespace std;

class Autovermietung {
private:
    vector<Mietwagen> fahrzeuge;

public:
    Autovermietung() : fahrzeuge(vector<Mietwagen>()) {}

    // Getter und Setter
    vector<Mietwagen> getFahrzeuge() { return fahrzeuge; }
    void setFahrzeuge(vector<Mietwagen> neueFahrzeuge) { fahrzeuge = neueFahrzeuge; }

    //Destruktor für Autovermietung. Wird aufgerufen, wenn das Objekt zerstört wird
    ~Autovermietung() {
            fahrzeuge.clear();
            cout << "Vielen Dank!" << endl;
    }

    //Fügt ein Fahrzeug zur Fahrzeugliste hinzu
    void addFahrzeug(Mietwagen wagen) {
        fahrzeuge.push_back(wagen);
        cout << "Fahrzeug hinzugefügt: " << wagen.getMarke() << endl;
    }

    //Eröffnet einen Konsolendialog zum Verwalten der Autovermietung
    void dialog() {
        int auswahl = 1;
        while (auswahl != 0) {
            cout << "1. Fahrzeug mieten" << endl;
            cout << "2. Fahrt anzeigen" << endl;
            cout << "3. Alle Fahrten anzeigen" << endl;
            cout << "4. Fahrt löschen" << endl;
            cout << "5. Fahrzeug hinzufügen" << endl;
            cout << "6. Alle Fahrzeuge anzeigen" << endl;
            cout << "0. Programm Beenden" << endl;
            
            cin >> auswahl;

            switch (auswahl) {
                case 1: // Fahrzeug mieten
                {
                    int nummer, abholdatum, abgabedatum;
                    string kundenname, kennzeichen;
    
                    cout << "Bitte geben Sie das KFZ-Kennzeichen ein: ";
                    cin >> kennzeichen;

                    Mietwagen* w = findeFahrzeug(kennzeichen);

                    cout << "Bitte geben Sie die Fahrtnummer ein: ";
                    cin >> nummer;

                    if (w->nummerPruefen(nummer)) {
                        cout << "Fahrtnummer existiert bereits." << endl;
                        break;
                    } 

                    cout << "Bitte geben Sie den Namen des Kunden ein: ";
                    cin.ignore();
                    getline(cin, kundenname);

                    cout << "Bitte geben Sie das Abholdatum (im Format JJJJMMTT) ein: ";
                    cin >> abholdatum;

                    cout << "Bitte geben Sie das Abgabedatum (im Format JJJJMMTT) ein: ";
                    cin >> abgabedatum;

                    if(!pruefeDatum(abholdatum, abgabedatum)) {
                        break;
                    }

                    Fahrt f(nummer, kundenname, abholdatum, abgabedatum); 
                
                    w->anmieten(f); 
                    break;
                }
                case 2: // Fahrt anzeigen
                {
                    int fahrtennummer;
                    cout << "Buchungsnummer? ";
                    cin >> fahrtennummer;

                    bool gefunden = false;
                    for (Mietwagen wagen : fahrzeuge) {
                        for (Fahrt f : wagen.getFahrtenbuch()) {
                            if (f.getNummer() == fahrtennummer) {
                                gefunden = true;
                                //f.anzeigen();
                                Fahrt fahrt(f.getNummer(), f.getKunde(), f.getAbholdatum(), f.getAbgabedatum());
                                fahrt.anzeigen();
                                break;
                            }
                        }
                    }
                    if (gefunden = 0) cout << "Fahrt existiert nicht." << endl;
                    break;
                }
                case 3: // Alle Fahrten anzeigen
                {  
                    int sortierung;
                    cout << "Alphabetische Ausgabe (0: absteigend, 1: aufsteigend):" << endl;
                    cin >> sortierung;

                    for(Mietwagen w : fahrzeuge) {
                        Mietwagen* fahrzeug = findeFahrzeug(w.getKennzeichen());
                        auto fahrtenbuch = fahrzeug->getFahrtenbuch();
                        if (sortierung = 0) {
                            insertionSortFahrtenAbsteigend(fahrtenbuch);
                        } else if (sortierung = 1) {
                            insertionSortFahrtenAufsteigend(fahrtenbuch);
                        } else {
                            cout << "Ungültige Eingabe." << endl;
                            break;
                        }
                        w.alleFahrtenAnzeigen();
                        cout << "--------------------------" << endl;
                    }
                    break;
                }
                case 4: //Fahrt löschen
                {
                    int fahrtennummer;
                    cout << "Buchungsnummer? ";
                    cin >> fahrtennummer;

                    for (Mietwagen& wagen : fahrzeuge) {
                        if (wagen.nummerPruefen(fahrtennummer)) {
                            wagen.fahrtLoeschen(fahrtennummer);
                            cout << "Fahrt mit Nummer " << fahrtennummer << " wurde gelöscht." << endl;
                            break;
                        }
                    }
                    break;    
                }
                case 5: // Neues Fahrzeug hinzufügen
                {
                    string marke, kennzeichen;
                    int sitze;
                    cout << "Automarke? ";
                    cin >> marke;
                    cout << "KFZ-Kennzeichen? ";
                    cin >> kennzeichen;
                    cout << "Sitze? ";
                    cin >> sitze;

                    Mietwagen neuesFahrzeug(marke, kennzeichen, sitze);
                    addFahrzeug(neuesFahrzeug);
                    break;
                }
                case 6: // Alle Fahrzeuge anzeigen
                {
                    int sortierung;
                    cout << "Alphabetische Ausgabe (0: absteigend, 1: aufsteigend):" << endl;
                    cin >> sortierung;

                    if (sortierung = 0) {
                        insertionSortMietwagenAbsteigend(fahrzeuge);
                    } else if (sortierung = 1) {
                        insertionSortMietwagenAufsteigend(fahrzeuge);
                    } else {
                        cout << "Ungültige Eingabe." << endl;
                        break;
                    }

                    cout << "Alle Fahrzeuge:" << endl;
                    cout << "*****************" << endl;
                    for (Mietwagen w : fahrzeuge) {
                        w.fahrzeugAnzeigen();
                        w.alleFahrtenAnzeigen();
                        cout << "*****************" << endl;
                    }
                    break;
                }
                case 0: //Programm beenden
                {   
                    cout << "Auf Wiedersehen!" << endl;
                    break;
                }
                default: 
                    cout << "Ungültige Auswahl, bitte versuchen Sie es erneut." << endl;
            }
        }
    }

    Mietwagen* findeFahrzeug(string kennzeichen) {
        for (Mietwagen& w : fahrzeuge) {
            if (w.getKennzeichen() == kennzeichen) {
                w.fahrzeugAnzeigen();
                return &w; }
        }
        throw runtime_error("Fahrzeug mit dem angegebenen Kennzeichen wurde nicht gefunden.");
    }

    Mietwagen* mietwagenSuchen(int index) {
        if (index >= 0 && index < fahrzeuge.size()) {
            fahrzeuge[index].fahrzeugAnzeigen();
            return &fahrzeuge[index];
        } 
        throw runtime_error("Fahrzeug mit dem angegebenen Index wurde nicht gefunden.");
    }

    bool pruefeDatum(int abholdatum, int abgabedatum) {
        if (abholdatum > abgabedatum) {
            cout << "Abholdatum kann nicht nach dem Abgabedatum liegen." << endl;
            return false;
        }
        return true;
    }

};

int main() {
    string marke, kennzeichen;
    int sitze;
    cout << "Neues Fahrzeug: " << endl;
    cout << "Automarke? ";
    cin >> marke;
    cout << "KFZ-Kennzeichen? ";
    cin >> kennzeichen;
    cout << "Sitze? ";
    cin >> sitze;
    
    Mietwagen wagen(marke, kennzeichen, sitze);
    Mietwagen wagen2("Porsche", "KA-AS-1012", 2);
    Mietwagen wagen3("Opel", "KA-AS-1013", 4);

    Fahrt testfahrt(1, "Nikola,Tesla", 20251001, 20251002);
    Fahrt testfahrt2(2, "Charles,Darwin", 20250101, 20250212);

    wagen.anmieten(testfahrt);

    Autovermietung KarlsruheCars;

    KarlsruheCars.addFahrzeug(wagen); 
    KarlsruheCars.addFahrzeug(wagen2);
    KarlsruheCars.addFahrzeug(wagen3);

    Mietwagen* w = KarlsruheCars.findeFahrzeug("KA-AS-1012");
    w->anmieten(testfahrt2);

    Mietwagen* w2 = KarlsruheCars.mietwagenSuchen(1);
    w2->anmieten(testfahrt);
  
    KarlsruheCars.dialog(); 

    return 0;
}
