#include <iostream>
#include <vector>
#include <string>
#include "Fahrt.cpp"
#include "Mietwagen.cpp"

using namespace std;

// Insertionsort für Mietwagen
void insertionSortMietwagenAufsteigend(vector<Mietwagen>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        Mietwagen key = vec[i];
        int j = i;

        // Vergleiche key mit vorherigen Elementen und verschiebe größere
        while (j > 0 && vec[j - 1].getMarke() > key.getMarke()) {
            vec[j] = vec[j - 1];
            j -= 1;
        }
        vec[j] = key;
    }
}

void insertionSortMietwagenAbsteigend(vector<Mietwagen>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        Mietwagen key = vec[i];
        int j = i;

        // Alle Strings, die alphabetisch *vor* dem key kommen, werden nach rechts verschoben
        while (j > 0 && vec[j - 1].getMarke() < key.getMarke()) {
            vec[j] = vec[j - 1];
            j -= 1;
        }
        vec[j] = key;
    }
}

// Insertionsort für Fahrten
void insertionSortFahrtenAufsteigend(vector<Fahrt>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        Fahrt key = vec[i];
        int j = i;

        // Vergleiche key mit vorherigen Elementen und verschiebe größere
        while (j > 0 && vec[j - 1].getKunde() > key.getKunde()) {
            vec[j] = vec[j - 1];
            j -= 1;
        }
        vec[j] = key;
    }
}

void insertionSortFahrtenAbsteigend(vector<Fahrt>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        Fahrt key = vec[i];
        int j = i;

        // Alle Strings, die alphabetisch *vor* dem key kommen, werden nach rechts verschoben
        while (j > 0 && vec[j - 1].getKunde() < key.getKunde()) {
            vec[j] = vec[j - 1];
            j -= 1;
        }
        vec[j].getKunde() = key.getKunde();
    }
}

