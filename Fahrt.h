#pragma once
#ifndef FAHRT_H
#define FAHRT_H
#include <string>

// Diese Klasse beschreibt eine einzelne Mietfahrt
class Fahrt
{
private:
    int nummer;             // Eindeutige Buchungsnummer
    std::string kunde;      // Kundenname im Format Nachname,Vorname
    int abholdatum;         // Startdatum der Fahrt Format: Zahlen ohne Trennzeichen
    int abgabedatum;        // Enddatum der Fahrt   Format: Zahlen ohne Trennzeichen

public:
    Fahrt(int n, const std::string& k, int ab, int bis);    // Konstruktor
    void anzeigen() const;                                  // Gibt die Fahrtinformationen aus
    int getNummer() const;                                  // Gibt die Buchungsnummer zur�ck
    int getAbholdatum() const;                              // Gibt den Abholtag zur�ck
    int getAbgabedatum() const;                             // Gibt den Abgabetag zur�ck
    std::string getKunde() const;                           // Gibt den Kundennamen zur�ck
};

#endif