#ifndef MIETWAGEN_H
#define MIETWAGEN_H
#include <string>
#include <vector>
#include "Fahrt.h"

using namespace std;
// Add necessary includes and declarations here

class Mietwagen {
private:
    // Private member variables and functions
    string marke; // Model of the car    
    vector<Fahrt> fahrtenbuch; // Vector to store trips
    int sitze;
    string kennzeichen;
public:
    Mietwagen(); // Constructor
    Mietwagen(string marke, string kennzeichen,int sitze);
    ~Mietwagen(); // Destructor
    void anmieten(Fahrt f); // Function to rent the car,
    void fahrtAnzeigen (int nummer);
    void alleFahrtenAnzeigen();
    void alleFahrtensortAnzeigen(int order);
    bool nummerPruefen(int nummer);
    bool fahrtLoeschen(int nummer);
    bool verfuegbarkeitPruefen(Fahrt f);
    void fahrzeugAnzeigen();
    string getmarke();
    vector<Fahrt> sortbykundeNr(int order);

    // Add member functions and variables here
};

#endif // MIETWAGEN_H