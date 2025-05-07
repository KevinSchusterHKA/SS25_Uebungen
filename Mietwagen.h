#pragma once
#include <vector>
#include <string>
#include "Fahrt.h"

class Mietwagen {
private:
    std::string marke;
    std::string kennzeichen;
    std::vector<Fahrt> fahrtenbuch;  // Vector mit Objekten, nicht Zeigern

public:
    Mietwagen();  // Benutzereingabe über cin
    Mietwagen(const std::string& marke, const std::string& kennzeichen);  // Automatisch aus Datei

    void fahrzeugAnzeigen() const;

    bool anmieten(const Fahrt& neueFahrt);

    void alleFahrtenAnzeigen() const;

    bool nummerPruefen(int nummer) const;

    bool fahrtLoeschen(int nummer);

    bool verfuegbarkeitPruefen(const Fahrt& f) const;

    void alleFahrtenSortiertAnzeigen(int richtung) const;

    std::string getMarke() const;
    std::string getKennzeichen() const;
};
