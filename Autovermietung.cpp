#include "Autovermietung.h"
#include <iostream>
#include <algorithm>

Autovermietung::Autovermietung() {
    ladeDatenAusDatei("Inputdaten.txt");
}

Autovermietung::~Autovermietung() {
    for (Mietwagen* mw : fahrzeuge)
        delete mw;
    std::cout << "Vielen Dank.\n";
}

void Autovermietung::ladeDatenAusDatei(const std::string& dateiname) {
    std::ifstream infile(dateiname);
    if (!infile.is_open()) {
        std::cerr << "Datei konnte nicht geöffnet werden.\n";
        return;
    }



    std::string zeile;
    std::vector<std::string> automarken;
    std::vector<std::string> kennzeichen;
    std::string abschnitt = "";

    while (std::getline(infile, zeile)) {
        if (zeile.empty()) continue;

        if (zeile == "Kunden" || zeile == "Automarken" || zeile == "Kennzeichen") {
            abschnitt = zeile;
            continue;
        }

        if (abschnitt == "Kunden") {
            std::istringstream iss(zeile);
            std::string vorname, nachname;
            iss >> vorname >> nachname;
            kunden.push_back(nachname + "," + vorname);
        }
        else if (abschnitt == "Automarken") {
            automarken.push_back(zeile);
        }
        else if (abschnitt == "Kennzeichen") {
            kennzeichen.push_back(zeile);
        }
    }

    infile.close();

    size_t n = std::min(automarken.size(), kennzeichen.size());
    for (size_t i = 0; i < n; ++i) {
        fahrzeuge.push_back(new Mietwagen(automarken[i], kennzeichen[i]));
    }

    std::cout << n << " Fahrzeuge wurden aus der Datei geladen.\n";
}

void Autovermietung::dialog() {
    int auswahl;
    do {
        std::cout << "\n1: Fahrzeug mieten\n"
                     "2: Fahrt anzeigen\n"
                     "3: Alle Fahrten anzeigen\n"
                     "4: Fahrt loeschen\n"
                     "5: Fahrzeug hinzufuegen\n"
                     "6: Alle Fahrzeuge ausgeben\n"
                     "0: Programm beenden\n"
                     "Ihre Auswahl: ";
        std::cin >> auswahl;

        int index, buchungsnummer, abholdatum, abgabedatum;
        std::string kunde;
        Mietwagen* mw = nullptr;

        switch (auswahl) {
            case 1:
                alleFahrzeugeMitIndexAusgeben();
                std::cout << "Index des Fahrzeugs: "; std::cin >> index;
                mw = mietwagenSuchen(index);
                if (!mw) break;
            
                std::cout << "Buchungsnummer: "; std::cin >> buchungsnummer;
            
                if (mw->nummerPruefen(buchungsnummer)) {
                    std::cout << "Buchungsnummer bereits vorhanden!\n"; break;
                }
            
                std::cout << "Bekannte Kunden:\n";
                for (const auto& k : kunden) std::cout << "- " << k << "\n";
            
                int kundenwahl;
                std::cout << "Neuen Kunden anlegen (1) oder bestehenden auswaehlen (2)? ";
                std::cin >> kundenwahl;
                std::cin.ignore(); // Eingabepuffer leeren!
            
                if (kundenwahl == 1) {
                    std::string vorname, nachname;
                    std::cout << "Vorname: "; std::getline(std::cin, vorname);
                    std::cout << "Nachname: "; std::getline(std::cin, nachname);
                    kunde = nachname + "," + vorname;
                    kunden.push_back(kunde);
                    std::cout << "Neuer Kunde angelegt: " << kunde << "\n";
                }
                else if (kundenwahl == 2) {
                    std::cout << "Kunde (Nachname,Vorname): ";
                    std::getline(std::cin, kunde);
                    if (std::find(kunden.begin(), kunden.end(), kunde) == kunden.end()) {
                        std::cout << "Unbekannter Kunde!\n"; break;
                    }
                }
                else {
                    std::cout << "Ungueltige Auswahl!\n"; break;
                }
            
                std::cout << "Abholdatum: "; std::cin >> abholdatum;
                std::cout << "Abgabedatum: "; std::cin >> abgabedatum;
            
                if (abholdatum >= abgabedatum) {
                    std::cout << "Ungueltige Datumsangaben!\n"; break;
                }
            
                if (mw->anmieten(Fahrt(buchungsnummer, kunde, abholdatum, abgabedatum)))
                    std::cout << "Fahrt erfolgreich angelegt.\n";
            break;
        
            case 2:
                alleFahrzeugeMitIndexAusgeben();
                std::cout << "Index des Fahrzeugs: "; std::cin >> index;
                mw = mietwagenSuchen(index);
                if (mw) mw->alleFahrtenAnzeigen();
                break;

            case 3:
                std::cout << "Alphabetische Ausgabe (0: absteigend, 1: aufsteigend): ";
                int richtung; 
                std::cin >> richtung;
                if (richtung != 0 && richtung != 1) {
                    std::cout << "Ungueltige Eingabe! Bitte 0 oder 1 waehlen.\n";
                    break;
                }
                for (auto f : fahrzeuge)
                    f->alleFahrtenSortiertAnzeigen(richtung);
                break;

            case 4:
                alleFahrzeugeMitIndexAusgeben();
                std::cout << "Index des Fahrzeugs: "; std::cin >> index;
                mw = mietwagenSuchen(index);
                if (mw) {
                    std::cout << "Buchungsnummer der zu loeschenden Fahrt: ";
                    std::cin >> buchungsnummer;
                    if (mw->fahrtLoeschen(buchungsnummer))
                        std::cout << "Fahrt geloescht.\n";
                    else
                        std::cout << "Fahrt nicht gefunden!\n";
                }
                break;

            case 5:
                fahrzeuge.push_back(new Mietwagen());
                break;

            case 6:
                std::cout << "Alphabetische Ausgabe (0: absteigend, 1: aufsteigend): ";
                int sortRichtung; 
                std::cin >> sortRichtung;
                if (sortRichtung != 0 && sortRichtung != 1) {
                    std::cout << "Ungueltige Eingabe! Bitte 0 oder 1 waehlen.\n";
                    break;
                }
                fahrzeugeSortiertAusgeben(sortRichtung);
                break;

            case 0:
                std::cout << "Programm wird beendet.\n";
                break;

            default:
                std::cout << "Ungueltige Eingabe!\n";
        }

    } while (auswahl != 0);
}

Mietwagen* Autovermietung::mietwagenSuchen(int index) {
    if (index >= 0 && index < fahrzeuge.size()) {
        fahrzeuge[index]->fahrzeugAnzeigen();
        return fahrzeuge[index];
    }
    std::cout << "Mietwagen nicht gefunden!\n";
    return nullptr;
}

void Autovermietung::fahrzeugeSortiertAusgeben(int richtung) {
    std::vector<Mietwagen*> temp = fahrzeuge;
    for (size_t i = 1; i < temp.size(); ++i) {
        Mietwagen* key = temp[i];
        int j = i - 1;
        while (j >= 0 && (richtung ? (temp[j]->getMarke() > key->getMarke()) : (temp[j]->getMarke() < key->getMarke()))) {
            temp[j + 1] = temp[j];
            --j;
        }
        temp[j + 1] = key;
    }

    for (Mietwagen* mw : temp) {
        std::cout << "\n";
        mw->fahrzeugAnzeigen();
        mw->alleFahrtenAnzeigen();
    }
}
void Autovermietung::alleFahrzeugeMitIndexAusgeben() const {
    std::cout << "Verfuegbare Fahrzeuge:\n";
    for (size_t i = 0; i < fahrzeuge.size(); ++i) {
        std::cout << "[" << i << "] "
                    << fahrzeuge[i]->getMarke() << " - "
                    << fahrzeuge[i]->getKennzeichen() << "\n";
    }
}