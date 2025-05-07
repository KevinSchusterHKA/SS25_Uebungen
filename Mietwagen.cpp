#include "Mietwagen.h"
#include <iostream>
#include <algorithm>
using namespace std;

Mietwagen::Mietwagen() {
    cout << "Fahrzeugmarke: ";
    cin >> marke;
    cout << "Kennzeichen: ";
    cin >> kennzeichen;
    cout << "Sitze: ";
    cin >> sitze;
    cout << "Fahrzeug erzeugt: " << marke << " mit KFZ-Kennzeichen " << kennzeichen << " und " << sitze << " Sitzen" << endl;
}

void Mietwagen::anmieten() {
    int nummer, abhol, abgabe;
    string kunde;

    cout << "Buchungsnummer: ";
    cin >> nummer;
    if (nummerPruefen(nummer)) {
        cout << "Fehler: Nummer bereits vorhanden.";
        return;
    }

    cout << "Kunde (Nachname,Vorname): ";
    cin >> kunde;
    cout << "Abholdatum (yyyymmdd): ";
    cin >> abhol;
    cout << "Abgabedatum (yyyymmdd): ";
    cin >> abgabe;

    if (abhol > abgabe) {
        cout << "Fehler: Abholdatum liegt nach Abgabedatum.";
        return;
    }

    Fahrt neueFahrt(nummer, kunde, abhol, abgabe);
    if (!verfuegbarkeitPruefen(neueFahrt)) {
        cout << "Fehler: Zeitraum überschneidet sich mit einer bestehenden Fahrt.";
        return;
    }

    fahrtenbuch.push_back(neueFahrt);
    cout << "Fahrt erfolgreich angelegt.";
}

void Mietwagen::fahrtenAnzeigen() const {
    for (const auto& f : fahrtenbuch) {
        f.anzeigen();
    }
}

bool Mietwagen::nummerPruefen(int nummer) const {
    for (const auto& f : fahrtenbuch) {
        if (f.getBuchungsnummer() == nummer) {
            return true;
        }
    }
    return false;
}

bool Mietwagen::fahrtLoeschen() {
    int nummer;
    cout << "Buchungsnummer der Fahrt löschen: ";
    cin >> nummer;

    for (size_t i = 0; i < fahrtenbuch.size(); ++i) {
        if (fahrtenbuch[i].getBuchungsnummer() == nummer) {
            fahrtenbuch.erase(fahrtenbuch.begin() + i);
            cout << "Fahrt gelöscht.";
            return true;
        }
    }

    cout << "Fehler: Nummer nicht gefunden.";
    return false;
}

void Mietwagen::fahrzeugAnzeigen() const {
    cout << "Fahrzeug: " << marke << " - " << kennzeichen << " (" << sitze << " Sitze)" << endl;
}

bool Mietwagen::verfuegbarkeitPruefen(const Fahrt& neueFahrt) const {
    for (const auto& f : fahrtenbuch) {
        if (!(neueFahrt.getAbgabedatum() < f.getAbholdatum() || neueFahrt.getAbholdatum() > f.getAbgabedatum())) {
            return false;
        }
    }
    return true;
}

void Mietwagen::fahrtenSortierenUndAnzeigen() const {
    if (fahrtenbuch.empty()) {
        cout << "Keine Fahrten vorhanden.";
        return;
    }
    int wahl2;

    cout << "\nAlphabetische Ausgabe (0:A-Z, 1:Z-A): ";
    cin >> wahl2;

    vector<Fahrt> sortiert = fahrtenbuch;

    switch (wahl2) {
    case 0: {
        sort(sortiert.begin(), sortiert.end(),
            [](const Fahrt& a, const Fahrt& b) {
                return a.getKunde() < b.getKunde();
            });
        break;
    }
    case 1: {
        sort(sortiert.begin(), sortiert.end(),
            [](const Fahrt& a, const Fahrt& b) {
                return b.getKunde() < a.getKunde();
            });
        break;
    }

    default:
        cout << "Ungültige Eingabe.\n";
    }

    cout << "Fahrten:";
    for (const auto& f : sortiert) {
        f.anzeigen();
    }

}
