#include "Vermietung.h"
#include "Mietwagen.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


Vermietung::Vermietung(string name)
{
    Name = name;
}


void Vermietung::addFahrzeug(Mietwagen* fahrzeug)
{
    Fuhrpark.push_back(fahrzeug);
}

int Vermietung::getFahrzeug(string kennzeichen)
{
    int i = 0;
    bool valid = false;
    for (i; i < Fuhrpark.size() && !valid; i++)
    {
        valid = kennzeichen == (Fuhrpark.at(i))->getKennzeichen();
    }
    return valid ? i - 1 : -1;
}

void Vermietung::dialog()
{
    string in;
    string Marke;
    string Kennzeichen;
    string Kunde;
    int Sitze = 0;
    int Beginn = 0;
    int Ende = 0;
    int BNr = 0;
    int dir = 0;
    while(Fuhrpark.size() == 0)
    {
        try
        {
            cout << "Fahrzeug anlegen:\nMarke: ";
            cin >> Marke;
            cout << "Kennzeichen: ";
            cin >> Kennzeichen;
            cout << "Anzahl Sitze: ";
            cin >> in;
            Sitze = stoi(in)>0 ? stoi(in) : 4;
            addFahrzeug(new Mietwagen(Marke, Kennzeichen, Sitze));
            cout << "Fahrzeug erfolgreich hinzugefuegt\n";
            Fuhrpark.at(getFahrzeug(Kennzeichen))->printFahrzeug();
        }
        catch (exception)
        {
            cout << "Invalid Entry\n";
        }
    }
    while (Fuhrpark.size() >= 1)
    {
        cout << "\n0: Fahrzeug mieten\n1: Fahrt anzeigen\n2: Alle Fahrten eines Fahrzeugs anzeigen\n3: Fahrt loeschen\n4: Fahrzeug hinzufuegen\n5: Alle Fahrten anzeigen\ne: Exit\n";

        cin >> in;

        if (in == "e")
        {
            cout << "\nExiting\n\n";
            break;
        }
        try {
            switch (stoi(in))
            {
            case 0:
                cout << "\nKennzeichen eingeben\n";
                cin >> Kennzeichen;
                if (getFahrzeug(Kennzeichen) == -1)
                {
                    cout << "Kein Fahrzeug mit diesem Kennzeichen";
                    break;
                }
                Fuhrpark.at(getFahrzeug(Kennzeichen))->printFahrzeug();
                cout << "Buchungsnummer: ";
                cin >> in;
                BNr = stoi(in) > 0 ? stoi(in) : 0;
                if (!BNr) 
                {
                    cout << "Invalid Entry";
                    break;
                }
                if (Fuhrpark.at(getFahrzeug(Kennzeichen))->bnrPruefen(BNr) != -1)
                {
                    cout << "Buchungsnummer bereits vergeben\n";
                    Fuhrpark.at(getFahrzeug(Kennzeichen))->fahrtAnzeigen(BNr);
                    break;
                }
                cout << "Beginn: ";
                cin >> in;
                Beginn = stoi(in);
                cout << "Ende: ";
                cin >> in;
                Ende = stoi(in);
                cout << "Kunde: ";
                cin >> Kunde;
                Fuhrpark.at(getFahrzeug(Kennzeichen))->anmieten(Fahrt(Beginn, Ende, BNr, Kunde));
                //cout << "Buchung mit Buchungsnummer \"" << BNr << "\" erfolgreich\n";
                break;

            case 1:
                cout << "\nKennzeichen eingeben\n";
                cin >> Kennzeichen;
                if (getFahrzeug(Kennzeichen) == -1)
                {
                    cout << "Kein Fahrzeug mit diesem Kennzeichen";
                    break;
                }
                Fuhrpark.at(getFahrzeug(Kennzeichen))->printFahrzeug();
                cout << "Buchungsnummer: ";
                cin >> in;
                BNr = stoi(in);
                Fuhrpark.at(getFahrzeug(Kennzeichen))->fahrtAnzeigen(BNr);
                break;

            case 2:
                cout << "\nKennzeichen eingeben\n";
                cin >> Kennzeichen;
                if (getFahrzeug(Kennzeichen) == -1)
                {
                    cout << "Kein Fahrzeug mit diesem Kennzeichen";
                    break;
                }
                cout << "0: Aufsteigend\n1: Absteigend\n";
                cin >> in;
                dir = stoi(in);
                Fuhrpark.at(getFahrzeug(Kennzeichen))->printFahrzeug();
                Fuhrpark.at(getFahrzeug(Kennzeichen))->alleFahrtenAnzeigen(dir);
                break;

            case 3:
                cout << "\nKennzeichen eingeben\n";
                cin >> Kennzeichen;
                if (getFahrzeug(Kennzeichen) == -1)
                {
                    cout << "Kein Fahrzeug mit diesem Kennzeichen";
                    break;
                }
                Fuhrpark.at(getFahrzeug(Kennzeichen))->printFahrzeug();
                cout << "Buchungsnummer: ";
                cin >> in;
                BNr = stoi(in);
                if (!Fuhrpark.at(getFahrzeug(Kennzeichen))->fahrtLoeschen(BNr))
                {
                    cout << "Buchungsnummer nicht vorhanden\n";
                    break;
                }
                cout << "Fahrt mit Buchungsnummer \"" << BNr << "\" geloescht";
                break;

            case 4:
                cout << "Fahrzeug anlegen:\nMarke: ";
                cin >> Marke;
                cout << "Kennzeichen: ";
                cin >> Kennzeichen;
                if (getFahrzeug(Kennzeichen) != -1)
                {
                    cout << "Kennzeichen bereits vorhanden\n";
                    Fuhrpark.at(getFahrzeug(Kennzeichen))->printFahrzeug();
                    break;
                }
                cout << "Anzahl Sitze: ";
                cin >> in;
                Sitze = stoi(in)>0 ? stoi(in) : 4;
                addFahrzeug(new Mietwagen(Marke, Kennzeichen, Sitze));
                cout << "Fahrzeug erfolgreich hinzugefuegt\n";
                Fuhrpark.at(getFahrzeug(Kennzeichen))->printFahrzeug();
                break;

            case 5:
                cout << "0: Aufsteigend\n1: Absteigend\n";
                cin >> in;
                dir = stoi(in);
                Fuhrpark.at(0)->insertionSort(Fuhrpark);
                if (dir)
                {
                    for (int i = Fuhrpark.size(); i > 0; i--)
                    {
                        Fuhrpark.at(i - 1)->printFahrzeug();
                        Fuhrpark.at(i - 1)->alleFahrtenAnzeigen(dir);
                    }
                }
                else
                {
                    for (int i = 0; i < Fuhrpark.size(); i++)
                    {
                        Fuhrpark.at(i)->printFahrzeug();
                        Fuhrpark.at(i)->alleFahrtenAnzeigen(dir);
                    }
                }
                break;

            default:
                cout << "Invalid Entry";
                break;
            }
        }
        catch (exception) {
            cout << "Invalid Entry";
        }
    }
}