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
    Mietwagen* fahrzeug = new Mietwagen();  // dynamisch erzeugt
    fahrzeuge.push_back(fahrzeug);          // Zeiger speichern

    int auswahl;

    do {
        cout << "\n--- Menü ---" << endl;
        cout << "1: Fahrzeug mieten" << endl;
        cout << "2: Fahrt anzeigen" << endl;
        cout << "3: Alle Fahrten anzeigen" << endl;
        cout << "4: Fahrt löschen" << endl;
        cout << "0: Programm beenden" << endl;
        cout << "Auswahl: ";
        cin >> auswahl;

        switch (auswahl) {
            case 1:
                (*fahrzeug).anmieten();  // statt fahrzeug->anmieten();
                break;

            case 2: {
                int nummer;
                cout << "Fahrtnummer eingeben: ";
                cin >> nummer;
                (*fahrzeug).fahrtAnzeigen(nummer);
                break;
            }

            case 3:
                (*fahrzeug).alleFahrtenAnzeigen();
                break;

            case 4: {
                int nummer;
                cout << "Buchungsnummer der zu löschenden Fahrt: ";
                cin >> nummer;
                (*fahrzeug).fahrtLoeschen(nummer);
                break;
            }
            case 0:
                cout << "Programm wird beendet." << endl;
                break;

            default:
                cout << "Ungültige Eingabe. Bitte 0–3 wählen." << endl;
        }
    } while (auswahl != 0);
}
