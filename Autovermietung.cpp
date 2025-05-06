#include "Autovermietung.h"
#include <iostream>
 
Autovermietung::Autovermietung() {

}

Autovermietung::~Autovermietung() {
    for (Mietwagen* fahrzeug : this->fahrzeuge) {
        delete fahrzeug;
    }
}


void Autovermietung::dialog() {

    Mietwagen* fahrzeug = new Mietwagen("Seat", "KA-ST-1014", 5, { 0,"Bill Gates",20250101,20250131 });
    this->fahrzeuge.push_back(fahrzeug);
    fahrzeug = new Mietwagen("Opel", "KA-ST-1015", 4, { 1,"Steve Jobs",20250101,20250131 });
    this->fahrzeuge.push_back(fahrzeug);
    fahrzeug = new Mietwagen("VW", "KA-ST-1016", 5, { 2,"Harald Schmidt",20250101,20250131 });
    this->fahrzeuge.push_back(fahrzeug);
    
    int auswahl, AutoAuswahl, t;
    int sort = 0;
    int Buchungsnummer = 0;
    std::string kundenName = "";
    std::vector<Mietwagen*> TempWagen;
    int abholDatum = 0, abgabeDatum = 0;


    do {
        std::cout << "\n\n";
        std::cout << "Hauptmenue:\n";
        std::cout << "1: Fahrzeug mieten\n";
        std::cout << "2: Fahrt anzeigen\n";
        std::cout << "3: Alle Fahrten anzeigen\n";
        std::cout << "4: Fahrt loeschen\n";
        std::cout << "5: Fahrzeug hinzufuegen\n";
        std::cout << "6: Alle Fahrzeuge ausgeben\n";
        std::cout << "0: Programm beenden\n\n";
        std::cout << "Bitte treffen Sie eine Auswahl:\n";

        while (true) {
            std::cin >> auswahl;
            if (std::cin.fail()) {
                std::cin.clear(); // Fehlerflag zurücksetzen
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
                std::cout << "Ungueltige Eingabe. Bitte geben Sie eine Zahl ein.\n";
            }
            else {break;}
        }


        switch (auswahl) {
        case 1://Fahrzeug mieten

            AutoAuswahl = this->mietwagenSuchen();
            std::cout << "Bitte geben sie die Buchungsnummer ein.\n";
            std::cin >> Buchungsnummer;
            if (this->fahrzeuge[AutoAuswahl]->nummerPruefen(Buchungsnummer))
            {
                std::cout << "Die Buchungnummer " << Buchungsnummer << " ist bereits vergeben.\n";
                continue;
            }


            std::cout << "Geben Sie bitte den Nachnamen und Vornamen im Format (Nachname,Vorname) ein:\n";
            std::cin >> kundenName;
            do
            {
                std::cout << "Bitte geben sie das Abholdatum ein im Format: JJJJMMTT\n";
                std::cin >> abholDatum;
                std::cout << "Bitte geben sie das Abgabedatum ein im Format: JJJJMMTT\n";
                std::cin >> abgabeDatum;

                if ((abholDatum - abgabeDatum) > 0)
                {
                    std::cout << "Abholdatum ist nach dem Abgabedatum, aendern sie ihre Eingaben.\n";
                }
            } while ((abholDatum - abgabeDatum) > 0);

            this->fahrzeuge[AutoAuswahl]->anmieten({ Buchungsnummer, kundenName, abholDatum, abgabeDatum });
            break;

        case 2://Fahrt anzeigen

            AutoAuswahl = this->mietwagenSuchen();
            std::cout << "Welche Fahrt willst du sehen?\n";
            std::cin >> t;
            this->fahrzeuge[AutoAuswahl]->fahrtAnzeigen(t);
            break;

        case 3://alle Fahrten anzeigen

            std::cout << "Sollen die Fahrten in alphabetischer Reihenfolge aufwaerts (0) oder abwaerts (1) angezeigt werden.\n";
            std::cin >> sort;
            AutoAuswahl = this->mietwagenSuchen();
            this->fahrzeuge[AutoAuswahl]->insertionsortFahrten(sort);
            break;

        case 4://Fahrt entfernen

            AutoAuswahl = this->mietwagenSuchen();
            if (this->fahrzeuge[AutoAuswahl]->fahrtLoeschen())
            {
                std::cout << "Die Fahrt wurde entfernt.\n";
            }
            else
            {
                std::cout << "Die Fahrt gibt es nicht.\n";
            }
            break;

        case 5://Fahrzeug hinzufügen

            fahrzeug = new Mietwagen;
            this->fahrzeuge.push_back(fahrzeug);
            break;

        case 6://Alle Fahrzeuge ausgeben

            std::cout << "Sollen die Fahrzeuge und Fahrten in alphabetischer Reihenfolge aufwaerts (0) oder abwaerts (1) angezeigt werden.\n";
            std::cin >> sort;
            TempWagen = this->fahrzeuge;
            for (int i = 1; i < TempWagen.size(); ++i)
            {
                Mietwagen* Temp = TempWagen[i];
                int j = i - 1;

                while (j >= 0 && ((sort == 0) && ((TempWagen[j]->getMarke().at(0)) > (Temp->getMarke().at(0))) ||
                    ((sort == 1) && ((TempWagen[j]->getMarke().at(0)) < (Temp->getMarke().at(0))))))
                {
                    TempWagen[j + 1] = TempWagen[j];
                    j--;
                }
                TempWagen[j + 1] = Temp;
            }

            for (Mietwagen* var : TempWagen)
            {
                var->fahrzeugAnzeigen();
                var->insertionsortFahrten(sort);
                std::cout << "\n\n";
            }
            break;

        case 0:

            std::cout << "Programm wird beendet.\n";
            break;

        default:

            std::cout << "Ungueltige Eingabe. Bitte versuchen Sie es erneut.\n";
            break;

        }
    } while (auswahl != 0);
}



int Autovermietung::mietwagenSuchen() {

    int auswahl = 0;
    std::cout << "Bitte waehle ein Auto:\n";

    do
    {
        std::cin >> auswahl;
        if (((0 <= auswahl) && (auswahl <= (this->fahrzeuge.size() - 1))))
        {
            this->fahrzeuge[auswahl]->fahrzeugAnzeigen();
        }
        else
        {
            std::cout << "Dieses Fahrzeug existiert nicht.\n";
        }
    } while (!((0 <= auswahl) && (auswahl <= (this->fahrzeuge.size() - 1))));

    return auswahl;
}
