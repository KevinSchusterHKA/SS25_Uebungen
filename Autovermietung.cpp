#include "Autovermietung.h"
#include <iostream>

// Konstruktor: Initial kann ein Mietwagen angelegt werden, dies passiert aber in dialog()

Autovermietung::Autovermietung()
{
    Mietwagen* f = new Mietwagen();
    fahrzeuge.push_back(f);
}
// Destruktor: gibt alle dynamisch erzeugten Mietwagenobjekte frei
Autovermietung::~Autovermietung()
{
    for (auto f : fahrzeuge)
    {
        delete f;
    }
    std::cout << "Vielen Dank.\n";
}

// Prüft, ob ein Mietwagen mit diesem Index existiert und gibt ihn zurück
Mietwagen* Autovermietung::mietwagenSuchen(int index) const {
    if (index < 0 || index >= fahrzeuge.size())
    {
        std::cout << "Fehler: Mietwagen mit Index " << index << " existiert nicht.\n";
        return nullptr;
    }
    fahrzeuge[index]->fahrzeugAnzeigen();
    return fahrzeuge[index];
}

void Autovermietung::dialog()
{
    int auswahl;
    do {
        std::cout << "\n--- Autovermietung Menue ---\n"
            << "1: Fahrzeug mieten\n"
            << "2: Fahrt anzeigen\n"
            << "3: Alle Fahrten anzeigen\n"
            << "4: Fahrt loeschen\n"
            << "5: Fahrzeug hinzufuegen\n"
            << "6: Alle Fahrzeuge ausgeben\n"
            << "0: Programm beenden\n"
            << "Auswahl: ";
        std::cin >> auswahl;

        // Switch Case
        switch (auswahl)
        {

        case 1:     // Fahrt anlegen
        {
            int index;
            std::cout << "Fahrzeug-Index: "; std::cin >> index;
            Mietwagen* fz = mietwagenSuchen(index);
            if (!fz) break;

            int nummer, ab, bis;
            std::string kunde;
            std::cout << "Buchungsnummer: "; std::cin >> nummer;
            if (fz->nummerPruefen(nummer))
            {
                std::cout << "Fehler: Nummer existiert bereits.\n";
                break;
            }
            std::cout << "Kunde (Nachname,Vorname): "; std::cin >> kunde;
            std::cout << "Abholdatum: "; std::cin >> ab;
            std::cout << "Abgabedatum: "; std::cin >> bis;
            if (ab > bis)
            {
                std::cout << "Fehler: Abholdatum > Abgabedatum.\n";
                break;
            }
            Fahrt f(nummer, kunde, ab, bis);
            fz->anmieten(f);
            break;
        }

        case 2:
        {       // Einzelne Fahrt anzeigen
            int index, nr;
            std::cout << "Fahrzeug-Index: "; std::cin >> index;
            Mietwagen* fz = mietwagenSuchen(index);
            if (fz)
            {
                std::cout << "Fahrtnummer: "; std::cin >> nr;
                fz->fahrtAnzeigen(nr);
            }
            break;
        }

        case 3:
        {       // Alle Fahrten anzeigen und sortieren
            int index;
            bool absteigend;
            std::cout << "Fahrzeug-Index: "; std::cin >> index;
            Mietwagen* fz = mietwagenSuchen(index);
            if (fz)
            {
                std::cout << "Aufsteigend (0) oder Absteigend (1)? "; std::cin >> absteigend;
                fz->alleFahrtenAnzeigen(absteigend);
            }
            break;
        }

        case 4:
        {       // Fahrt löschen
            int index, nr;
            std::cout << "Fahrzeug-Index: "; std::cin >> index;
            Mietwagen* fz = mietwagenSuchen(index);
            if (fz) {
                std::cout << "Buchungsnummer löschen: "; std::cin >> nr;
                fz->fahrtLoeschen(nr);
            }
            break;
        }

        case 5:
        {       // Neues Fahrzeug hinzufügen
            Mietwagen* fz = new Mietwagen();
            fahrzeuge.push_back(fz);
            break;
        }

        case 6:
        {       // Alle Fahrzeuge anzeigen und sortieren
            bool absteigend;
            std::cout << "Fahrzeuge nach Marke sortieren? Aufsteigend (0) oder Absteigend (1)? ";
            std::cin >> absteigend;
            std::vector<Mietwagen*> sortiert = fahrzeuge;
            // Insertionsort nach Marke
            for (int i = 1; i < sortiert.size(); ++i)
            {
                Mietwagen* key = sortiert[i];
                int j = i - 1;
                while (j >= 0 && (absteigend ? sortiert[j]->getMarke() < key->getMarke() : sortiert[j]->getMarke() > key->getMarke()))
                {
                    sortiert[j + 1] = sortiert[j];
                    --j;
                }
                sortiert[j + 1] = key;
            }
            for (size_t i = 0; i < sortiert.size(); ++i)
            {
                std::cout << "\nFahrzeug #" << i << ":\n";
                sortiert[i]->fahrzeugAnzeigen();
                sortiert[i]->alleFahrtenAnzeigen();
            }
            break;
        }

        case 0:
            break;

        default:
            std::cout << "Ungültige Eingabe.\n";
            break;
        }

    }

    while (auswahl != 0);

}