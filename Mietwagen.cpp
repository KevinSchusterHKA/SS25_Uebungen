#include "Mietwagen.h"
#include <iostream>

Mietwagen::Mietwagen() {
    std::cout << "Marke (ohne Leerzeichen): ";
    std::cin >> marke;
    std::cout << "Kennzeichen (ohne Leerzeichen): ";
    std::cin >> kennzeichen;
    std::cout << "Erstellt: " << marke << ", " << kennzeichen << "\n";
}

Mietwagen::Mietwagen(const std::string& marke, const std::string& kennzeichen)
    : marke(marke), kennzeichen(kennzeichen) {
    std::cout << "Automatisch erstellt: " << marke << ", " << kennzeichen << "\n";
}

void Mietwagen::fahrzeugAnzeigen() const {
    std::cout << "Fahrzeug " << marke << " mit KFZ-Kennzeichen " << kennzeichen << "\n";
}

bool Mietwagen::anmieten(const Fahrt& neueFahrt) {
    if (!verfuegbarkeitPruefen(neueFahrt)) {
        std::cout << "Fahrt ueberschneidet sich mit einer bestehenden.\n";
        return false;
    }
    fahrtenbuch.push_back(neueFahrt);
    return true;
}

void Mietwagen::alleFahrtenAnzeigen() const {
    if (fahrtenbuch.empty()) {
        std::cout << "Dieses Fahrzeug hat bisher keine Fahrten.\n";
        return;
    }

    for (const auto& f : fahrtenbuch) {
        f.anzeigen();
    }
}


bool Mietwagen::nummerPruefen(int nummer) const {
    for (const auto& f : fahrtenbuch) {
        if (f.getBuchungsnummer() == nummer) return true;
    }
    return false;
}

bool Mietwagen::fahrtLoeschen(int nummer) {
    for (auto it = fahrtenbuch.begin(); it != fahrtenbuch.end(); ++it) {
        if (it->getBuchungsnummer() == nummer) {
            fahrtenbuch.erase(it);
            return true;
        }
    }
    return false;
}

bool Mietwagen::verfuegbarkeitPruefen(const Fahrt& f) const {
    for (const auto& bestehend : fahrtenbuch) {
        if (!(f.getAbgabedatum() <= bestehend.getAbholdatum() || f.getAbholdatum() >= bestehend.getAbgabedatum()))
            return false;
    }
    return true;
}

void Mietwagen::alleFahrtenSortiertAnzeigen(int richtung) const {
    std::vector<Fahrt> temp = fahrtenbuch;
    for (size_t i = 1; i < temp.size(); ++i) {
        Fahrt key = temp[i];
        int j = i - 1;
        while (j >= 0 && (richtung ? (temp[j].getKunde() > key.getKunde()) : (temp[j].getKunde() < key.getKunde()))) {
            temp[j + 1] = temp[j];
            --j;
        }
        temp[j + 1] = key;
    }

    for (const auto& f : temp) {
        f.anzeigen();
    }
}

std::string Mietwagen::getMarke() const {
    return marke;
}

std::string Mietwagen::getKennzeichen() const {
    return kennzeichen;
}
