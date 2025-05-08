#include "Autovermietung.h"
#include "mietwagen.h"
#include "Fahrt.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Zufallsstartwert

    Autovermietung vermietung;

    // --- Automatisch vorbereitete Daten ---
    Mietwagen* w1 = new Mietwagen("Peugeot", "KA-MH-1019", 5);
    Mietwagen* w2 = new Mietwagen("Citroën", "KA-MH-1020", 5);
    Mietwagen* w3 = new Mietwagen("Renault", "KA-MH-1021", 5);

    w1->anmietenDirekt(Fahrt(1, "Leonardo,daVinci", 20250501, 20250503));
    w2->anmietenDirekt(Fahrt(2, "Pablo,Picasso",    20250502, 20250504));
    w3->anmietenDirekt(Fahrt(3, "Vincent,vanGogh",  20250503, 20250505));

    // Fahrzeuge zur Autovermietung hinzufügen
    vermietung.addFahrzeug(w1);
    vermietung.addFahrzeug(w2);
    vermietung.addFahrzeug(w3);

    // --- Start Benutzerinterface ---
    vermietung.dialog();
    return 0;
}
