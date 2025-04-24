#include "Mietwagen.h"
#include <iostream>


 
Mietwagen::Mietwagen() {
    std::cout << "Neues Fahrzeug:" << std::endl;
    std::cout << "Fahrzeugname eingeben:\n " << std::endl;
   std::cin >> string;

    std::cout << "Nummernschild eingeben:\n " << std::endl;
    std::cin >> kennzeichnen;

    std::cout << "Anzahl der Sitze eingeben: \n" << std::endl;
    std::cin >> sitze;

    std::cout << "Mietwagen erstellt mit:" << std::endl;
    std::cout << "Name: " << string  << std::endl;
    std::cout << "Nummernschild: " << kennzeichnen << std::endl;
    std::cout << "Sitze: " << sitze  << std::endl;
}

Mietwagen::Mietwagen(std::string name, std::string kennz, int sitze) {
   string = name;
   kennzeichnen = kennz;
    sitze = sitze;
}



void Mietwagen::anmieten(Fahrt f) {
    if (verfuegbarkeitPruefen(f)) {
        fahrtenbuch.push_back(f);
       std::cout << "Fahrt wurde erfolgreich gespeichert." << std::endl;

    }
    else {
        std::cout << "Fehler: Die gewunschte Mietdauer uberschneidet sich mit einer bestehenden Fahrt!" << std::endl;
    }
}

void Mietwagen::fahrtAnzeigen(int nummer) {

}

void Mietwagen::alleFahrtenAnzeigen() {
   for (size_t i = 0; i < fahrtenbuch.size(); i++) {
            fahrtenbuch[i].anzeigen();
    }
}

bool Mietwagen::nummerPruefen(int nummer) {
    bool temp=false ;
    for (size_t i = 0; i < fahrtenbuch.size(); i++){
        if (fahrtenbuch[i].getNummer() == nummer)
        {
            std::cout << "Buchnungsnummer ist schon vergeben." << std::endl;

            temp = true;
            fahrtenbuch[i].anzeigen();
            break;

        }
        else
        {
            temp= false;
        }
         
    }
   

    return temp;
}


bool Mietwagen::fahrtLoeschen(int nummer) {
    for (size_t i = 0; i < fahrtenbuch.size(); ++i) {

        if (fahrtenbuch[i].getNummer() == nummer) {

            fahrtenbuch.erase(fahrtenbuch.begin() + i); 
            std::cout << "Fahrt mit Buchungsnummer" << nummer << " erfolgreich geloscht." << std::endl;
            return true; 

        }
    }
    std::cout << "Fahrt mit Buchungsnummer " << nummer << " nicht gefunden." << std::endl;
    return false;

}

bool Mietwagen::verfuegbarkeitPruefen(Fahrt f) {

    for (size_t i = 0; i < fahrtenbuch.size(); ++i) {
        Fahrt &bestehend = fahrtenbuch[i];
        int neueAbholung = f.getabholdatum();
       int neueAbgabe = f.getabgabedatum();
        int vorhandeneAbholung = bestehend.getabholdatum();
        int vorhandeneAbgabe = bestehend.getabgabedatum();




        
        if (vorhandeneAbholung <= neueAbgabe && neueAbgabe <= vorhandeneAbgabe)
            return false;

        if (vorhandeneAbholung <= neueAbholung && neueAbholung <= vorhandeneAbgabe)
            return false;

        if (neueAbholung <= vorhandeneAbholung && vorhandeneAbholung <= neueAbgabe)
            return false;
     
     
    }

    return true;  
}
void Mietwagen::fahrzeugAnzeigen() {

    std::cout << "Marke: " << string <<", ";
    std::cout << "Kennzeichen:  " << kennzeichnen << "\n";
}
std::string  Mietwagen::getstring() {

    return string;
}