#ifndef Fahrt_H
#define Fahrt_H
#include <string>
#include <vector>
#include "Fahrt.h"

using namespace std;

// Add necessary includes and declarations here

class Fahrt {
private:
    // Private member variables and functions
    string kunde; // Model of the car    
    int nummer;
    int abgabedatum;
    int abholddatum;
    
public:
    Fahrt();
    Fahrt(int n,string k, int ab, int bs); 
    ~Fahrt(); 
    void anzeigen(); 
    int getNummer();
    string getkunde();
    int getabdatum();
    int getzurueckdatum();
};

#endif