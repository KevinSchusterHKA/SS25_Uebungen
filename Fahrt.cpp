#include "Fahrt.h"
#include <iostream>
#include <string>

Fahrt::Fahrt(int beginn, int ende, int bnr, string kunde)
{
	Beginn = beginn;
	Ende = ende;
	BNr = bnr;
	Kunde = kunde;
}


void Fahrt::anzeigen()
{
	cout << "Buchungsnummer: " << BNr << "\nKunde: " << Kunde.c_str() << "\nZeitraum: " << Beginn << " - " << Ende << "\n";
}

int Fahrt::getBNr()
{
	return BNr;
}

int Fahrt::getBeginn()
{
	return Beginn;
}

int Fahrt::getEnde()
{
	return Ende;
}