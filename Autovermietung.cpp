#include <iostream>
#include "Autovermietung.h"
#include "Mietwagen.h"
#include <cstdlib>

using namespace std;

Autovermietung::Autovermietung(){}
Autovermietung::~Autovermietung(){
    while(!this->fahrzeuge.empty()){
        delete this->fahrzeuge.back();
        this->fahrzeuge.pop_back();
    }
    cout<<"Vielen Danke"<<endl;
}
void Autovermietung::dialog(){
    Mietwagen* fahrzeug=new Mietwagen();
    this->fahrzeuge.push_back(fahrzeug);

    //main loop
    int command = -1;
    //while (command!=1&&command!=2&&command!=3&&command!=0&&command!=4){
    while (true){
        cout << "1: Fahrzeug mieten\n"<<
                 "2: Fahrt anzeigen\n"<<
                 "3: Alle Fahrten anzeigen\n"<<
                 "4: Fahrt loeschen\n"<<
                 "5: Fahrzeug hinzufuegen\n"<<
                 "6: Alle Fahrzeuge ausgeben\n"<<
                 "0: Programm beenden" << endl;
    
        cin >> command;

    
        // cout<<"Eingabefehler\n"<<
        // "Bitte erneut eingeben\n"<<
        // "1: Fahrzeug mieten\n"
        // "2: Fahrt anzeigen\n"
        //  "3: Alle Fahrten anzeigen\n"
        //  "4: Fahrt loeschen\n"
        //  "0: Programm beenden" << endl;
        // cin >> command;
    
    // string marke;
    // string kennzeichen;
    // int sitze;
        string kunde; // Model of the car    
        int nummer;
        int abgabedatum;
        int abholddatum;

        switch (command){
        case 1:{
            Mietwagen* p = mietwagenSuchen();
            if (p) p->fahrzeugAnzeigen();
            else
            {cout<<"input falsh"<<endl;
                break;}


            cout<<"Buchungsnummer?";
            cin>>nummer;
            cout<<"Kunde (Nachname, Vorname)?";
            cin>>kunde;
            cout<<"Abholdatum (yyyymmdd)?";
            cin>>abholddatum;
            cout<<"Abgabedatum (yyyymmdd)?";
            cin>>abgabedatum;
            if (abholddatum<=abgabedatum){
                Fahrt f=Fahrt(nummer,kunde, abholddatum, abgabedatum);
                
                // cout << "Fahrzeug mieten" << endl;

                // cout<<"Neues Fahrzeug:\n"<<endl;

                // cout<<"Automarke?";
                
                // cin>>marke;

                // cout<<"KFZ-Kennzeichen?";
                
                // cin>>kennzeichen;
                // cout<<"Sitze";
                
                // cin>>sitze;

                
                //Mietwagen *p=new Mietwagen(marke,kennzeichen,sitze);
                //m.anmieten();

                // if this wagen can be rent, from fahrzeuge

                //input renter information

                


                // put f into fahrtenbuch
                if (!p->nummerPruefen(nummer)){
                    if (p->verfuegbarkeitPruefen(f))
                        p->anmieten(f);
                    else
                        cout<<"Buchung wegen Ueberschneidung nicht erfolgt!"<<endl;
                    }
                else
                    
                    cout<<"Buchungsnummer ist schon vergeben, bitte neu eingeben!"<<endl;

                }
                else{
                    cout<<"Fehler: Abholdatum muss vor Abgabedatum liegen.\n"<<endl;
                }
                break;
            }
            case 2:{
                Mietwagen* p = mietwagenSuchen();
                if (p) p->fahrzeugAnzeigen();
                cout << "Fahrt anzeigen" << endl;
                cout<<"Buchungsnummer?";
                int bnr;
                cin>>bnr;
                p->fahrtAnzeigen(bnr);
                break;}
            case 3:{
                Mietwagen* p = mietwagenSuchen();
                if (p) p->fahrzeugAnzeigen();
                cout << "Alle Fahrten anzeigen" << endl;
                p->alleFahrtenAnzeigen();
                break;}
            case 4:{
                Mietwagen* p = mietwagenSuchen();
                if (p) p->fahrzeugAnzeigen();
                cout << "Fahrt loeschen" << endl;
                cout<<"Buchungsnummer?";
                int bnr;
                cin>>bnr;

                if (!p->fahrtLoeschen(bnr))
                    cout<<"Buchungsnummer existiert nicht, bitte neu eingeben!"<<endl;
                else
                    cout<<"Buchungsnummer"<< bnr<<" wurde geloescht"<<endl;
                
                break;}
            case 5:{
                Mietwagen* neuwagen=new Mietwagen();
                this->fahrzeuge.push_back(neuwagen);
                cout << "Fahrzeug hinzugefügt.\n";
                break;
            }
            case 6:{
                cout << "Alphabetische Ausgabe (0: absteigend, 1: aufsteigend):";
                int order;
                cin >> order;
                
                fahrzeugeAnzeigen(order);
                break;
            }
            case 0:
                exit(0);
            default:
            cout<<"Eingabefehler\n"<<"Bitte erneut eingeben"<<endl;
            }
    }
}

Mietwagen* Autovermietung::mietwagenSuchen() {
    int index;
    cout << "Welches Fahrzeug (indexNr)? ";
    cin >> index;

    if (index < 0 || index >= this->fahrzeuge.size()) {
        cout << "Fahrzeug nicht gefunden!\n";
    } else {
        this->fahrzeuge[index]->fahrzeugAnzeigen();
        return fahrzeuge[index];
    }
}


vector<Mietwagen*> Autovermietung::sortbymarke(int order) {
    //sort fahrzeuge
    vector<Mietwagen*> orderedfahrzeuge=this->fahrzeuge;
    if (order){
    for (int i = 1; i < orderedfahrzeuge.size(); ++i) {
        Mietwagen* m = orderedfahrzeuge[i];
        int j = i - 1;
        while (j >= 0 && m->getmarke() < orderedfahrzeuge[j]->getmarke()) {
                orderedfahrzeuge[j + 1] = orderedfahrzeuge[j];
                j--;
        }
        orderedfahrzeuge[j + 1] = m;
    }
    }
    else{
        for (int i = 1; i < orderedfahrzeuge.size(); ++i) {
            Mietwagen* m = orderedfahrzeuge[i];
            int j = i - 1;
            while (j >= 0 && m->getmarke() > orderedfahrzeuge[j]->getmarke()) {
                    orderedfahrzeuge[j + 1] = orderedfahrzeuge[j];
                    j--;
            }
            orderedfahrzeuge[j + 1] = m;
        }
    }
    return orderedfahrzeuge;
}

void Autovermietung::fahrzeugeAnzeigen(int order) {
    if (fahrzeuge.empty()) {
        cout << "Keine Fahrzeuge vorhanden.\n";
        return;
    }
    vector<Mietwagen*> orderedfahrzeuge=sortbymarke(order);
    for (int i= 0; i < orderedfahrzeuge.size(); i++) {
        cout << "******************************\n";
        orderedfahrzeuge[i]->fahrzeugAnzeigen();
        orderedfahrzeuge[i]->alleFahrtensortAnzeigen(order);//unsort
    }
}