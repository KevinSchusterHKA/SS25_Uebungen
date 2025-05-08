#include "Mietwagen.h"
#include <iostream>
#include <algorithm>
using namespace std;

Mietwagen::Mietwagen() {
    cout << "Marke: ";
    cin >> marke;
    cout << "Kennzeichen: ";
    cin >> kennzeichen;
    cout << "Anzahl der Sitzplätze: ";
    cin >> sitze;

    cout << "Mietwagen erstellt:\n"
         << "Marke: " << marke << "\n"
         << "Kennzeichen: " << kennzeichen << "\n"
         << "Sitze: " << sitze << endl;
}
Mietwagen::Mietwagen(string m, string k, int s)
    : marke(m), kennzeichen(k), sitze(s) {
    cout << "Mietwagen angelegt: " << marke << " (" << kennzeichen << ")" << endl;
}

void Mietwagen::anmietenDirekt(Fahrt f) {
    fahrtenbuch.push_back(f);
}

void Mietwagen::anmieten() {
    int nummer, abhol, abgabe;
    string kunde;

    cout << "Buchungsnummer: ";
    cin >> nummer;

    if (nummerPruefen(nummer)) {
        cout << "Buchungsnummer existiert bereits!" << endl;
        return;
    }

    cout << "Kunde (Nachname,Vorname): ";
    cin >> kunde;
    cout << "Abholdatum (z.B. 20240501): ";
    cin >> abhol;
    cout << "Abgabedatum (z.B. 20240503): ";
    cin >> abgabe;
    if (abhol > abgabe) {
        cout << "Fehler: Abholdatum liegt nach dem Abgabedatum!" << endl;
        return;
    }

    Fahrt neueFahrt(nummer, kunde, abhol, abgabe);

    if (verfuegbarkeitPruefen(neueFahrt)) {
        fahrtenbuch.push_back(neueFahrt);
        cout << "Fahrt erfolgreich angelegt." << endl;
    } else {
        cout << "Fehler: Der Mietwagen ist in diesem Zeitraum bereits vergeben!" << endl;
    }
    cout << "Fahrt erfolgreich angelegt." << endl;
}

void Mietwagen::alleFahrtenAnzeigen() {
    if (fahrtenbuch.empty()) {
        cout << "Keine Fahrten vorhanden." << endl;
        return;
    }

    for (Fahrt& fahrt : fahrtenbuch) {
        fahrt.anzeigen();
    }
}

void Mietwagen::fahrtAnzeigen(int nummer) {
    for (Fahrt& fahrt : fahrtenbuch) {
        if (fahrt.getNummer() == nummer) {
            fahrt.anzeigen();
            return;
        }
    }
    cout << "Keine Fahrt mit der Nummer " << nummer << " gefunden." << endl;
}

bool Mietwagen::nummerPruefen(int nummer) {
    for (Fahrt& fahrt : fahrtenbuch) {
        if (fahrt.getNummer() == nummer) {
            return true;
        }
    }
    return false;
}

void Mietwagen::fahrtLoeschen(int nummer) {
    for (auto it = fahrtenbuch.begin(); it != fahrtenbuch.end(); ++it) {
        if (it->getNummer() == nummer) {
            fahrtenbuch.erase(it);
            cout << "Fahrt wurde gelöscht." << endl;
            return;
        }
    }
    cout << "Fahrt existiert nicht." << endl;
}

bool Mietwagen::verfuegbarkeitPruefen(Fahrt f) {
    int neuAbhol = f.getAbholdatum();
    int neuAbgabe = f.getAbgabedatum();

    for (Fahrt& bestehend : fahrtenbuch) {
        int altAbhol = bestehend.getAbholdatum();
        int altAbgabe = bestehend.getAbgabedatum();

        if (!(neuAbgabe < altAbhol || neuAbhol > altAbgabe)) {
            return false;
        }
    }

    return true;
}

void Mietwagen::fahrzeugAnzeigen() {
    cout << "Fahrzeug: " << marke << ", Kennzeichen: " << kennzeichen << endl;
}


string Mietwagen::getMarke() {
    return marke;
}

void Mietwagen::sortiereFahrten(bool aufsteigend) {
    std::sort(fahrtenbuch.begin(), fahrtenbuch.end(),
        [aufsteigend](const Fahrt& a, const Fahrt& b) {
            return aufsteigend ? a.getKunde() < b.getKunde()
                               : a.getKunde() > b.getKunde();
        });
}
