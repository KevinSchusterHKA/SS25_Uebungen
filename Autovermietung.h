#pragma once

#include"Mietwagen.h"
class Autovermietung
{
private:
	std::vector <Mietwagen*> Fahrzeuge;
public:
	Autovermietung();
	~Autovermietung();
	void dialog();
    int mietwagenSuchen(void);
};

Autovermietung::Autovermietung() {

}
Autovermietung::~Autovermietung() {
    for (Mietwagen* Fahrzeug : this->Fahrzeuge) {
        delete Fahrzeug;
    }
    std::cout << "Vielen Dank" << std::endl;

}
void Autovermietung::dialog() {
    Mietwagen* fahrzeug = new Mietwagen("Nissan", "KA-GC-1020", 2, {0,"Lionel Messi",20250101,20250202});
    this->Fahrzeuge.push_back(fahrzeug);
    fahrzeug = new Mietwagen("Hyundai", "KA-GC-1021", 4, { 1,"Serena Williams",20250101,20250202 });
    this->Fahrzeuge.push_back(fahrzeug);
    fahrzeug = new Mietwagen("Kia", "KA-GC-1022", 5, { 2,"Michael Jordan",20250101,20250202 });
    this->Fahrzeuge.push_back(fahrzeug);
    enum Auswahl {
        Beenden, FahrzeugMieten, FahrtAnzeigen, AlleFahrtenAnzeigen, FahrtLoeschen, FahrzeugHinzufuegen, AlleFahrzeugeAusgeben
    };
    int auswahl;
    int AutoAuswahl;
    int Sortierrichtung = 0;
    int temp;
    int Buchungsnummer = 0;
    std::string kundenName = "";
    std::vector<Mietwagen*> TempWagen;
    int abholDatum = 0,abgabeDatum = 0;


    do {
        std::cout << "Menue:\n";
        std::cout << "1: Fahrzeug mieten\n";
        std::cout << "2: Fahrt anzeigen\n";
        std::cout << "3: Alle Fahrten anzeigen\n";
        std::cout << "4: Fahrt loeschen\n";
        std::cout << "5: Fahrzeug hinzufuegen\n";
        std::cout << "6: Alle Fahrzeuge ausgeben\n";
        std::cout << "0: Programm beenden\n";
        std::cout << "Bitte waehlen Sie eine Option:\n";
        while (true)
        {
            std::cin >> auswahl;
            if (std::cin.fail())
			{
				std::cin.clear(); // Fehlerflag zurücksetzen
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
				std::cout << "Ungueltige Eingabe. Bitte geben Sie eine Zahl ein." << std::endl;
			}
			else
			{
				break; // Gültige Eingabe, Schleife verlassen
			}

        }

        switch (auswahl) {
        case FahrzeugMieten:
            AutoAuswahl = this->mietwagenSuchen();
            std::cout << "Bitte geben sie die Buchungsnummer ein." << std::endl;
            std::cin >> Buchungsnummer;
            if (this->Fahrzeuge[AutoAuswahl]->nummerPruefen(Buchungsnummer))
            {
                std::cout << "Die Buchungnummer " << Buchungsnummer << " gibt es schon." << std::endl;
                continue;
            }


            std::cout << "Bitte geben sie folgende Daten in Reihenfolge ohne" << std::endl << "Leerzeichen und mit Kommas getrennt ein:" << std::endl << "Nachname,Vorname" << std::endl;
            std::cin >> kundenName;
            do
            {
                std::cout << "Bitte geben sie das Abholdatum ein im Format: yyyymmdd" << std::endl;
                std::cin >> abholDatum;
                std::cout << "Bitte geben sie das Abgabedatum ein im Format: yyyymmdd" << std::endl;
                std::cin >> abgabeDatum;

                if ((abholDatum - abgabeDatum) > 0)
                {
                    std::cout << "Abholdatum ist nach dem Abgabedatum, aendern sie ihre Eingaben." << std::endl;
                }
            } while ((abholDatum - abgabeDatum) > 0);

            this->Fahrzeuge[AutoAuswahl]->anmieten({Buchungsnummer, kundenName, abholDatum, abgabeDatum});
            break;
        case FahrtAnzeigen:
            AutoAuswahl = this->mietwagenSuchen();
            std::cout << "Welche Fahrt willst du sehen?" << std::endl;
            std::cin >> temp;
            this->Fahrzeuge[AutoAuswahl]->fahrtAnzeigen(temp);
            break;
        case AlleFahrtenAnzeigen:
            std::cout << "Sollen die Fahrten in alphabetischer Reihenfolge aufwaerts (0) oder abwaerts (1) angezeigt werden." << std::endl;
            std::cin >> Sortierrichtung;
            AutoAuswahl = this->mietwagenSuchen();
            this->Fahrzeuge[AutoAuswahl]->insertionsortFahrten(Sortierrichtung);
            
            break;
        case Beenden:
            std::cout << "Programm wird beendet." << std::endl;
            break;
        case FahrtLoeschen:

            AutoAuswahl = this->mietwagenSuchen();
            if (this->Fahrzeuge[AutoAuswahl]->fahrtLoeschen())
            {
                std::cout << "Die Fahrt wurde geloescht." << std::endl;
            }
            else
            {
                std::cout << "Die Fahrt gibt es nicht." << std::endl;
            }
            break;
        case FahrzeugHinzufuegen:
            fahrzeug = new Mietwagen;
            this->Fahrzeuge.push_back(fahrzeug);

            break;
        case AlleFahrzeugeAusgeben:

                std::cout << "Sollen die Fahrzeuge und Fahrten in alphabetischer Reihenfolge aufwaerts (0) oder abwaerts (1) angezeigt werden." << std::endl;
                std::cin >> Sortierrichtung;
                TempWagen = this->Fahrzeuge;
                for (int i = 1; i < TempWagen.size(); ++i)
                {
                    Mietwagen* Temp = TempWagen[i];
                    int j = i - 1;

                    while (j >= 0 &&    ((Sortierrichtung == 0) && ((TempWagen[j]->getMarke().at(0)) > (Temp->getMarke().at(0))) ||
                                        ((Sortierrichtung == 1) && ((TempWagen[j]->getMarke().at(0)) < (Temp->getMarke().at(0))))))
                    {
                        TempWagen[j + 1] = TempWagen[j];
                        j--;
                    }
                    TempWagen[j + 1] = Temp;
                }

                for (Mietwagen* var : TempWagen)
                {
                    var->fahrzeugAnzeigen();
                    var->insertionsortFahrten(Sortierrichtung);
                    //var->fahrzeugAnzeigen();
                    //var->alleFahrtenAnzeigen();
                    std::cout << ".............................................." << std::endl;
                    std::cout << ".............................................." << std::endl;
                }
            break;
        default:
            std::cout << "Ungueltige Eingabe. Bitte versuchen Sie es erneut." << std::endl;
            break;
        }
    } while (auswahl != 0);
}



int Autovermietung::mietwagenSuchen(void) {
    int auswahl = 0;

    std::cout << "Bitte waehle ein Auto:" << std::endl;

    do
    {
        std::cin >> auswahl;
        if (((0 <= auswahl) && (auswahl<=(this->Fahrzeuge.size() - 1))))
        {
            this->Fahrzeuge[auswahl]->fahrzeugAnzeigen();
        }
        else
        {
            std::cout << "Dieses Fahrzeug existiert nicht." << std::endl;

        }
    } while (!(( 0 <= auswahl) && (auswahl<=(this->Fahrzeuge.size()-1) )));
    
    return auswahl;
}
