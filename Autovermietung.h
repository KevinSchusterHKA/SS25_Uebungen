#pragma once
#ifndef AUTOVERMIETUNG_H
#define AUTOVERMIETUNG_H

#include <vector>
#include "Mietwagen.h"

// Klasse der Autovermietung verwaltet die Sammlung der Mietwagen
// und bietet über die Methode dialog() ein Benutzermenü zur Interaktion
class Autovermietung
{
private:
    std::vector<Mietwagen*> fahrzeuge;  // Der Vector speichert einen Zeiger auf die Mietwagenobjekte

public:
    Autovermietung();                               // Konstruktor
    ~Autovermietung();                              // Destruktor zur Speicherfreigabe
    void dialog();                                  // Startet das Benutzerdialog Menü
    Mietwagen* mietwagenSuchen(int index) const;    // Sucht die Mietwagen anhand ihres Index
};

#endif
