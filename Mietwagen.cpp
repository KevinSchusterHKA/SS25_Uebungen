#include "Mietwagen.h"
#include <iostream>

// Der Konstruktor fragt Attributwerte ab und gibt sie aus
Mietwagen::Mietwagen() {
    std::cout << "Marke: "; std::cin >> marke;
    std::cout << "Kennzeichen: "; std::cin >> kennzeichen;
    std::cout << "Sitze: "; std::cin >> sitze;
    std::cout << "Erstellt: " << marke << ", " << kennzeichen << ", Sitze: " << sitze << std::endl;
}

// Fügt, falls verfügbar, eine Fahrt hinzu
void Mietwagen::anmieten(const Fahrt& f)
{
    if (!verfuegbarkeitPruefen(f))
    {
        std::cout << "Fahrtzeitraum ueberschneidet sich mit existierender Fahrt.\n";
        return;
    }
    fahrtenbuch.push_back(f);
    std::cout << "Fahrt erfolgreich angelegt.\n";
}

// Gibt eine spezifische Fahrt anhand ihrer Nummer aus
void Mietwagen::fahrtAnzeigen(int nummer) const
{
    for (const auto& f : fahrtenbuch)
    {
        if (f.getNummer() == nummer)
        {
            f.anzeigen();
            return;
        }
    }
    std::cout << "Fahrt nicht gefunden.\n";
}

// Gibt alle Fahrten aus, sortiert nach Kundennamen (Insertionsort)
void Mietwagen::alleFahrtenAnzeigen(bool absteigend) const
{
    if (fahrtenbuch.empty())
    {
        std::cout << "Keine Fahrten vorhanden.\n";
        return;
    }
    std::vector<Fahrt> sortiert = fahrtenbuch;
    for (int i = 1; i < sortiert.size(); ++i)
    {
        Fahrt key = sortiert[i];
        int j = i - 1;

        // Insertionsort abhängig von Sortierrichtung
        while (j >= 0 && (absteigend ? sortiert[j].getKunde() < key.getKunde() : sortiert[j].getKunde() > key.getKunde()))
        {
            sortiert[j + 1] = sortiert[j];
            --j;
        }
        sortiert[j + 1] = key;
    }
    for (const auto& f : sortiert)
    {
        f.anzeigen();
    }
}

// Prüft, ob eine Buchungsnummer bereits existiert
bool Mietwagen::nummerPruefen(int nummer) const
{
    for (const auto& f : fahrtenbuch)
    {
        if (f.getNummer() == nummer) return true;
    }
    return false;
}

// Entfernt eine Fahrt aus dem Fahrtenbuch
bool Mietwagen::fahrtLoeschen(int nummer)
{
    for (auto it = fahrtenbuch.begin(); it != fahrtenbuch.end(); ++it)
    {
        if (it->getNummer() == nummer)
        {
            fahrtenbuch.erase(it);
            std::cout << "Fahrt " << nummer << " gelöscht.\n";
            return true;
        }
    }
    std::cout << "Fahrt nicht gefunden.\n";
    return false;
}

// Prüft, ob die neue Fahrt sich mit einer bestehenden überschneidet
bool Mietwagen::verfuegbarkeitPruefen(const Fahrt& f) const
{
    for (const auto& existing : fahrtenbuch)
    {
        if (!(f.getAbgabedatum() < existing.getAbholdatum() || f.getAbholdatum() > existing.getAbgabedatum()))
        {
            return false;
        }
    }
    return true;
}

// Zeigt die Fahrzeugdaten an
void Mietwagen::fahrzeugAnzeigen() const
{
    std::cout << "Fahrzeug: " << marke << " (" << kennzeichen << "), Sitze: " << sitze << std::endl;
}

// Getter für Marke
std::string Mietwagen::getMarke() const
{
    return marke;
}


