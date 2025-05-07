#include <iostream>
#include "Autovermietung.h"

int main() {
    std::cout << "Willkommen bei Karlsruhe Cars!" << std::endl;

    // Erstelle das zentrale Verwaltungsobjekt
    Autovermietung autovermietung;

    // Starte das Dialog-Menü
    autovermietung.dialog();

    return 0;
}
