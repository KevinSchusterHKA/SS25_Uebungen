// Autovermietung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include "Autovermietung.h"
#include <iostream>


autovermietung::autovermietung() {

    std::vector<std::string> automarken = { "Volvo", "Mercedes", "Audi" };
    std::vector<std::string> kennzeichen = { "KA-HM-1014", "KA-HM-1015", "KA-HM-1016" };
    std::vector<std::string> Kunde = { "Mats Hummels", "James Bond", "Helmut Kohl" };

    for (int i = 0; i < 3; ++i) {
        Mietwagen* fahrzeug = new Mietwagen(automarken[i], kennzeichen[i], 5);

        Fahrt f(i + 1000, Kunde[i], 20230501+i, 20230510+i);   

        fahrzeuge.push_back(fahrzeug);

        fahrzeuge[i]->anmieten(f);
    }









    //Mietwagen* fahrzeug = new Mietwagen();   //before Q4 b) ||ohne test datei zu benutzen
    //fahrzeuge.push_back(fahrzeug);        

}

 


autovermietung::~autovermietung() {
    for (size_t i = 0; i < fahrzeuge.size(); ++i) {
        delete fahrzeuge[i];
    }
    std::cout << "Vielen Dank!" << std::endl;
}

std::vector<std::pair<int, Mietwagen*>> autovermietung::sortiereFahrzeuge(bool aufsteigend) {
    std::vector<std::pair<int, Mietwagen*>> tempcheck;

    for (size_t l = 0; l < fahrzeuge.size(); ++l) {
        tempcheck.push_back({ static_cast<int>(l), fahrzeuge[l] });
    }

    for (size_t i = 1; i < tempcheck.size(); ++i) {
        std::pair<int, Mietwagen*> swap = tempcheck[i];
        int j = i - 1;

        while (j >= 0 && ((aufsteigend && tempcheck[j].second->getstring() > swap.second->getstring()) ||(!aufsteigend && tempcheck[j].second->getstring() < swap.second->getstring()))) {
            tempcheck[j + 1] = tempcheck[j];
            j--;
        }

        tempcheck[j + 1] = swap;   
    }
    return tempcheck;
}




void Mietwagen::sortiereFahrten(bool aufsteigend) {
    for (size_t i = 1; i < Mietwagen::fahrtenbuch.size(); ++i) {
        Fahrt alphabet = fahrtenbuch[i];
        int j = i - 1;

        while (j >= 0 &&
            ((aufsteigend && fahrtenbuch[j].getkunde() > alphabet.getkunde()) ||  (!aufsteigend && fahrtenbuch[j].getkunde() < alphabet.getkunde()))) {
            fahrtenbuch[j + 1] = fahrtenbuch[j];
            j--;
        }
        fahrtenbuch[j + 1] = alphabet;
    }
}

int autovermietung::mietwagenSuchen() {
  int index;
  bool checkflags=true;
  do
  {
      std::cout << "Welches Fahrzeug (Indexnummer)? ";
      std::cin >> index;
      if (index < 0 || index >= fahrzeuge.size()) {
          std::cout << "Ungultiger Fahrzeugindex.\n";

      }
      else {
          checkflags = false;
      }

  } while (checkflags);

        fahrzeuge[index]->fahrzeugAnzeigen();
    return index;
}
 

void autovermietung::dialog() {
    bool flags = true;
    int auswahl = 0;
    int buchungsnummer, abholdatum, abgabedatum;
    std::string kunde;
    int fahrzeugIndex;
    bool temp;
    std::vector<std::pair<int, Mietwagen*>> sortfahrzeuge;
    do {
        std::cout << "\n|||||||-Autovermietung Menu-|||||||\n";
        std::cout << "1: Fahrzeug mieten\n";
        std::cout << "2: Fahrt anzeigen\n";
        std::cout << "3: Alle Fahrten anzeigen\n";
        std::cout << "4: Fahrt loeschen\n";
        std::cout << "5: Fahrzeug hinzufuegen\n";
        std::cout << "6: Alle Fahrzeuge ausgeben\n";
        std::cout << "0: Programm beenden\n";
        std::cout << "Auswahl: ";
        std::cin >> auswahl;

        switch (auswahl) {
        case 0:
            flags = false;
            break;

        case 1:
            fahrzeugIndex = mietwagenSuchen();

            std::cout << "Buchungsnummer: ";
            std::cin >> buchungsnummer;

            if (!fahrzeuge[fahrzeugIndex]->nummerPruefen(buchungsnummer)) {
                std::cout << "Kunde eingeben (Nachname,Vorname): ";
                std::cin >> kunde;

                std::cout << "Abholdatum eingeben (yyyymmdd): ";
                std::cin >> abholdatum;

                std::cout << "Abgabedatum eingeben (yyyymmdd): ";
                std::cin >> abgabedatum;

                if (abholdatum >= abgabedatum) {
                    std::cout << "Fehler: Das Abholdatum muss vor dem Abgabedatum liegen.\n";
                }
                else {
                    Fahrt f(buchungsnummer, kunde, abholdatum, abgabedatum);
                    fahrzeuge[fahrzeugIndex]->anmieten(f);
                }
            }
            else {
                std::cout << "Buchungsnummer existiert bereits!\n";
            }
            break;

        case 2:

            fahrzeugIndex = mietwagenSuchen();

            std::cout << "Buchungsnummer der Fahrt: ";
            std::cin >> buchungsnummer;
           temp = fahrzeuge[fahrzeugIndex]->nummerPruefen(buchungsnummer);
            if (!temp) {
                std::cout << "Fahrt nicht gefunden.\n";
            }
            else {
                fahrzeuge[fahrzeugIndex]->fahrtAnzeigen(buchungsnummer);
            }
            break;

        case 3:
            fahrzeugIndex = mietwagenSuchen();

            int richtunga;
            std::cout << "Alphabetisch nach Kunde sortieren? (1 = aufsteigend, 0 = absteigend): ";
            std::cin >> richtunga;

            fahrzeuge[fahrzeugIndex]->sortiereFahrten(richtunga);

            std::cout << "Alle Fahrten anzeigen:\n";
            fahrzeuge[fahrzeugIndex]->alleFahrtenAnzeigen();
            break;

        case 4:
            fahrzeugIndex = mietwagenSuchen();

            std::cout << "Bitte Buchungsnummer eingeben: ";
            std::cin >> buchungsnummer;
            fahrzeuge[fahrzeugIndex]->fahrtLoeschen(buchungsnummer);
            break;

        case 5: {
            Mietwagen* neuesFahrzeug = new Mietwagen();
            fahrzeuge.push_back(neuesFahrzeug);
           std::cout << "Neue Fahrzeug hinzugefugt, Aktuelle Gesamtanzahl: " << fahrzeuge.size() << "\n";
            break;
        }

        case 6:
            int richtung;
            std::cout << "Alphabetisch sortieren? (1 = aufsteigend,0 = absteigend): ";
            std::cin >> richtung;
            sortfahrzeuge = sortiereFahrzeuge(richtung);

            std::cout << "Liste aller Fahrzeuge:\n";
            for (size_t i = 0; i < sortfahrzeuge.size(); ++i) {
                std::cout << "Fahrzeug " << sortfahrzeuge[i].first << "-->";
                sortfahrzeuge[i].second->fahrzeugAnzeigen();
                sortfahrzeuge[i].second->alleFahrtenAnzeigen();
            }
            break;

        default:
            std::cout << "Ungultige Eingabe."<< auswahl << " Bitte erneut versuchen.\n";
            break;
        }

    } while (flags);
}





int main()
{
    autovermietung dialogcall;
    dialogcall.dialog();

}


// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
