#pragma once
#ifndef MIETWAGEN_H
#define MIETWAGEN_H
#include <string>
#include <vector>
#include "Fahrt.h"

// Die Klasse Mietwagen verwaltet Fahrten eines bestimmten Fahrzeugs
class Mietwagen
{
private:
    std::string marke;                  // Automarke
    std::string kennzeichen;            // Kennzeichen
    int sitze;                          // Sitzanzahl
    std::vector<Fahrt> fahrtenbuch;     // Fahrten dieses Wagens

public:
    Mietwagen();                                                // Konstruktor mit Attributabfrage
    void anmieten(const Fahrt& f);                              // Neue Fahrt anlegen
    void fahrtAnzeigen(int nummer) const;                       // Einzelne Fahrt anzeigen
    void alleFahrtenAnzeigen(bool absteigend = false) const;    // Alle Fahrten anzeigen
    bool nummerPruefen(int nummer) const;                       // Prüfen, ob Buchungsnummer vorhanden ist
    bool fahrtLoeschen(int nummer);                             // Fahrt im Fahrtenbuch löschen
    bool verfuegbarkeitPruefen(const Fahrt& f) const;           // Prüfen ob Fahrzeug verfügbar ist
    void fahrzeugAnzeigen() const;                              // Anzeigen der Fahrzeugdaten
    std::string getMarke() const;                               // zurückgeben der Marke
};

#endif