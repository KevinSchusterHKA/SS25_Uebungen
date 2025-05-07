#include "Autovermietung.h"
#include <iostream>
using namespace std;

Autovermietung::Autovermietung() {}

Autovermietung::~Autovermietung() {
    for (auto f : fahrzeuge) {
        delete f;
    }
    cout << "Vielen Dank.";
}

Mietwagen* Autovermietung::mietwagenSuchen() {
    int index;
    cout << "Index des Mietwagens: ";
    cin >> index;
    if (index < 0 || index >= fahrzeuge.size()) {
        cout << "Fahrzeug nicht vorhanden.";
        return nullptr;
    }
    return fahrzeuge[index];
}

void Autovermietung::dialog() {
    fahrzeuge.push_back(new Mietwagen());

    int wahl;
    do {
        cout << "\n1: Fahrzeug mieten\n2: Fahrt anzeigen\n3: Alle Fahrten anzeigen\n"
            "4: Fahrt löschen\n5: Fahrzeug hinzufügen\n6: Alle Fahrzeuge ausgeben\n"
            "7: Fahrten sortiert anzeigen\n"
            "0: Programm beenden\n> ";
        cin >> wahl;

        switch (wahl) {
        case 1: {
            Mietwagen* mw = mietwagenSuchen();
            if (mw) mw->anmieten();
            break;
        }
        case 2: {
            Mietwagen* mw = mietwagenSuchen();
            if (mw) mw->fahrtenAnzeigen();
            break;
        }
        case 3: {
            for (auto mw : fahrzeuge) {
                mw->fahrtenAnzeigen();
            }
            break;
        }
        case 4: {
            Mietwagen* mw = mietwagenSuchen();
            if (mw) mw->fahrtLoeschen();
            break;
        }
        case 5:
            fahrzeuge.push_back(new Mietwagen());
            break;
        case 6:
            for (auto mw : fahrzeuge) {
                mw->fahrzeugAnzeigen();
                mw->fahrtenAnzeigen();
            }
            break;
        case 7: {
            Mietwagen* mw = mietwagenSuchen();
            if (mw) mw->fahrtenSortierenUndAnzeigen();
            break;
        }
        case 0:
            break;
        default:
            cout << "Ungültige Eingabe.\n";
        }

    } while (wahl != 0);
}