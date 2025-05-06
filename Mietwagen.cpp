#include "Mietwagen.h"
#include <iostream>

Mietwagen::Mietwagen() {
	std::cout << "Bitte geben sie die Marke ein.\n";
	std::cin >> this->marke;
	std::cout << "Bitte geben sie das Kennzeichen ein.\n";
	std::cin >> this->kennzeichen;
	std::cout << "Bitte geben sie die Anzahl der Sitze ein.\n";
	std::cin >> this->sitze;
	std::cout << "Es wird ein Fahrtenbuch mit Null eintraegen generiert.\n";
	std::cout << "Mietwagen erstellt: " << this->marke << ", " << this->kennzeichen << ", mit " << this->sitze << " Sitzen.\n";
}

Mietwagen::Mietwagen(std::string m, std::string k, int s, Fahrt f) {
	this->marke = m;
	this->kennzeichen = k;
	this->sitze = s;
	this->fahrtenbuch.push_back(f);
}

std::string Mietwagen::getMarke() {
    return marke;
}

std::string Mietwagen::getKennzeichen() {
    return kennzeichen;
}

void Mietwagen::anmieten(Fahrt F) {
    if (this->verfuegbarkeitPruefen(F))
    {
        this->fahrtenbuch.push_back(F);
        std::cout << "Die Fahrt wurde angelegt.\n";
    }
	else { std::cout << "Der Zeitraum überschneidet sich mit einer anderen Fahrt.\n"; }
}

void Mietwagen::fahrtAnzeigen(int nummer) {
	if (nummer >= this->fahrtenbuch.size())
	{
		std::cout << "Diese Fahrt existiert nicht.\n";
	}
	else
	{
		this->fahrtenbuch[nummer].anzeigen();
	}
}

void Mietwagen::alleFahrtenAnzeigen(void) {
	if (this->fahrtenbuch.empty())
	{
		std::cout << "Mietwagen wurden noch nicht verliehen.\n";
	}
	else
	{
		for (Fahrt var : fahrtenbuch)
		{
			var.anzeigen();
		}
	}
}

bool Mietwagen::nummerPruefen(int nummer) {
	for (Fahrt var : this->fahrtenbuch)
	{
		if (var.getNummer() == nummer) {
			return true;
		}
	}
	return false;
}

bool Mietwagen::fahrtLoeschen() {
	int nummer = 0;
	std::cout << "Bitte gebe die Buchungsnummer zum loeschen ein.\n";
	std::cin >> nummer;
	if (0 <= nummer && nummer < this->fahrtenbuch.size())
	{
		this->fahrtenbuch.erase(this->fahrtenbuch.begin() + nummer);
		return true;
	}
	return false;
}

bool Mietwagen::verfuegbarkeitPruefen(Fahrt f) {
	for (Fahrt varFahrt : this->fahrtenbuch)
	{
		if ((varFahrt.getAbholDatum() <= f.getAbholDatum() && f.getAbholDatum() <= varFahrt.getAbgabeDatum()) ||
			(varFahrt.getAbholDatum() <= f.getAbgabeDatum() && f.getAbgabeDatum() <= varFahrt.getAbgabeDatum())) {
			return false;
		}
	}
	return true;
}

void Mietwagen::fahrzeugAnzeigen() {
	std::cout << "Marke: " << this->marke << std::endl << "Kennzeichen: " << this->kennzeichen << std::endl;
}

void Mietwagen::insertionsortFahrten(int Sortierrichtung) {
	for (int i = 1; i < this->fahrtenbuch.size(); ++i) {
		Fahrt TempFahrt = this->fahrtenbuch[i];
		int j = i - 1;

		// Sortiere basierend auf dem gesamten Namen des Kunden
		while (j >= 0 &&
			((Sortierrichtung == 0 && this->fahrtenbuch[j].getKunde() > TempFahrt.getKunde()) ||		// Aufsteigend
				(Sortierrichtung == 1 && this->fahrtenbuch[j].getKunde() < TempFahrt.getKunde()))) {	// Absteigend
			this->fahrtenbuch[j + 1] = this->fahrtenbuch[j];
			j--;
		}
		this->fahrtenbuch[j + 1] = TempFahrt;
	}

	// Ausgabe nach Sortierung
	for (Fahrt var : this->fahrtenbuch) {
		var.anzeigen();
	}
}