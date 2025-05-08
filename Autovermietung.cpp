#include "Autovermietung.h"
#include <iostream>
using namespace std;

Autovermietung::Autovermietung() {
    // aktuell nichts notwendig
}
Autovermietung::~Autovermietung() {
    for (Mietwagen* wagen : fahrzeuge) {
        delete wagen;
    }
    cout << "Vielen Dank" << endl;
}


void Autovermietung::dialog() {
    int auswahl;

    do {
        cout << "\n--- Menü ---" << endl;
        cout << "1: Fahrzeug mieten" << endl;
        cout << "2: Fahrt anzeigen" << endl;
        cout << "3: Alle Fahrten anzeigen" << endl;
        cout << "4: Fahrt löschen" << endl;
        cout << "5: Fahrzeug hinzufügen" << endl;
        cout << "6: Alle Fahrzeuge ausgeben" << endl;
        cout << "0: Programm beenden" << endl;
        cout << "Auswahl: ";
        cin >> auswahl;

        switch (auswahl) {
            case 1: {
                Mietwagen* mw = mietwagenSuchen();
                if (mw != nullptr) {
                    mw->fahrzeugAnzeigen();
                    mw->anmieten();
                }
                break;
            }

            case 2: {
                Mietwagen* mw = mietwagenSuchen();
                if (mw != nullptr) {
                    mw->fahrzeugAnzeigen();
                    int nummer;
                    cout << "Fahrtnummer eingeben: ";
                    cin >> nummer;
                    mw->fahrtAnzeigen(nummer);
                }
                break;
            }

            case 3: {
                Mietwagen* mw = mietwagenSuchen();
                if (mw != nullptr) {
                    (*mw).fahrzeugAnzeigen();

                    int sortWahl;
                    cout << "Sortieren nach Name (1 = aufsteigend, 2 = absteigend)? ";
                    cin >> sortWahl;
                    bool aufsteigend = (sortWahl == 1);

                    (*mw).sortiereFahrten(aufsteigend);
                    (*mw).alleFahrtenAnzeigen();
                }
                break;
            }

            case 4: {
                Mietwagen* mw = mietwagenSuchen();
                if (mw != nullptr) {
                    mw->fahrzeugAnzeigen();
                    int nummer;
                    cout << "Buchungsnummer der zu löschenden Fahrt: ";
                    cin >> nummer;
                    mw->fahrtLoeschen(nummer);
                }
                break;
            }

            case 5: {
                Mietwagen* neuesFahrzeug = new Mietwagen();
                fahrzeuge.push_back(neuesFahrzeug);
                cout << "Neues Fahrzeug wurde hinzugefügt." << endl;
                break;
            }
            case 6: {
                if (fahrzeuge.empty()) {
                    cout << "Keine Fahrzeuge vorhanden." << endl;
                } else {
                    int sortWahl;
                    cout << "Sortieren nach Marke (1 = aufsteigend, 2 = absteigend)? ";
                    cin >> sortWahl;
                    bool aufsteigend = (sortWahl == 1);

                    sortiereFahrzeuge(aufsteigend);

                    for (Mietwagen* fahrzeug : fahrzeuge) {
                        (*fahrzeug).fahrzeugAnzeigen();
                        (*fahrzeug).alleFahrtenAnzeigen();
                        cout << "-----------------------------" << endl;
                    }
                }
                break;
            }

            case 0:
                cout << "Programm wird beendet." << endl;
                break;

            default:
                cout << "Ungültige Eingabe. Bitte 0–5 wählen." << endl;
        }
    } while (auswahl != 0);
}

Mietwagen* Autovermietung::mietwagenSuchen() {
    if (fahrzeuge.empty()) {
        cout << "Keine Fahrzeuge vorhanden!" << endl;
        return nullptr;
    }

    cout << "\nVerfügbare Fahrzeuge:" << endl;
    for (size_t i = 0; i < fahrzeuge.size(); ++i) {
        cout << i << ": ";
        fahrzeuge[i]->fahrzeugAnzeigen();
    }

    cout << "Bitte Fahrzeugindex wählen: ";
    int index;
    cin >> index;

    if (index < 0 || index >= static_cast<int>(fahrzeuge.size())) {
        cout << "Ungültiger Index!" << endl;
        return nullptr;
    }

    return fahrzeuge[index];
}
#include <algorithm>  // ganz oben

void Autovermietung::sortiereFahrzeuge(bool aufsteigend) {
    std::sort(fahrzeuge.begin(), fahrzeuge.end(),
        [aufsteigend](Mietwagen* erster, Mietwagen* zweiter) {
            return aufsteigend
                ? (*erster).getMarke() < (*zweiter).getMarke()
                : (*erster).getMarke() > (*zweiter).getMarke();
        });
}
void Autovermietung::addFahrzeug(Mietwagen* wagen) {
    fahrzeuge.push_back(wagen);
}


