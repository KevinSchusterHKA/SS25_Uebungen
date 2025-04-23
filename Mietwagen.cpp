#include "Mietwagen.h"

Mietwagen::Mietwagen() {
	std::cout << "Neuer Mietwagen wird erstellt" << std::endl;
	std::cout << "Bitte geben sie die Marke ein." << std::endl;
	std::cin >> this->marke;
	std::cout << "Bitte geben sie das Kennzeichen ein." << std::endl;
	std::cin >> this->kennzeichen;
	std::cout << "Bitte geben sie die Anzahl der Sitze ein." << std::endl;
	std::cin >> this->sitze;
	std::cout << "Es wird ein Fahrtenbuch mit Null eintraegen generiert." << std::endl;
	std::cout << "Das Fahrzeug mit der Marke:" << this->marke << ",dem Kennzeichen: " 
		<< this->kennzeichen << ", und der Anzahl an Sitzen:" << this->sitze 
		<< " wurde angelegt." << std::endl;
}
Mietwagen::Mietwagen(std::string m, std::string k, int s, Fahrt f) {
	this->marke = m;
	this->kennzeichen = k;
	this->sitze = s;
	this->fahrtenbuch.push_back(f);
}

void Mietwagen::anmieten(Fahrt F) {
	if (this->verfuegbarkeitPruefen(F))
	{
		this->fahrtenbuch.push_back(F);
		std::cout << "Die Fahrt wurde erfolgreich angelegt" << std::endl;
	}
	else
	{
		std::cout << "Der Zeitraum überschneidet sich mit einer anderen Fahrt."<< std::endl;
	}
	
}
void Mietwagen::fahrtAnzeigen(int nummer) {
	if (nummer > this->fahrtenbuch.size())
	{
		std::cout << "Diese Fahrt gibt es nicht." << std::endl;
	}
	else
	{
		this->fahrtenbuch[nummer].anzeigen();
	}
}
void Mietwagen::alleFahrtenAnzeigen(void) {
	if (this->fahrtenbuch.empty())
	{
		std::cout << "Mietwagen wurden noch nicht verliehen." << std::endl;
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
	std::cout << "Bitte gebe die Buchungsnummer zum loeschen ein." << std::endl;
	std::cin >> nummer;
	try
	{
		this->fahrtenbuch.erase(this->fahrtenbuch.begin() + nummer);		
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}
bool Mietwagen::verfuegbarkeitPruefen(Fahrt f) {
	for (Fahrt varFahrt:this->fahrtenbuch)
	{
		if ((varFahrt.getAbholdatum() <= f.getAbholdatum() && f.getAbholdatum() <= varFahrt.getAbgabedatum()) ||
			(varFahrt.getAbholdatum() <= f.getAbgabedatum() && f.getAbgabedatum() <= varFahrt.getAbgabedatum())) {
			return false;
		}
	}
	return true;
}
void Mietwagen::fahrzeugAnzeigen() {
	std::cout << "Marke: " << this->marke << std::endl << "Kennzeichen: " << this->kennzeichen << std::endl;
}

void Mietwagen::insertionsortFahrten(int Sortierrichtung) {	
	std::vector<Fahrt> TempFahrtenbuch = this->fahrtenbuch;
	for (int i=1;i< TempFahrtenbuch.size();++i)
	{
		Fahrt TempFahrt = TempFahrtenbuch[i];
		int j = i - 1;
		while (j >= 0 &&	((Sortierrichtung == 0) && ((TempFahrtenbuch[j].getKunde().at(0)) > (TempFahrt.getKunde().at(0))) ||
							((Sortierrichtung == 1) && ((TempFahrtenbuch[j].getKunde().at(0)) < (TempFahrt.getKunde().at(0))))))
		{
			TempFahrtenbuch[j + 1] = TempFahrtenbuch[j];
			j--;
		}
		TempFahrtenbuch[j + 1] = TempFahrt;
	}

	for (Fahrt var: TempFahrtenbuch)
	{
		var.anzeigen();
	}
}

std::string Mietwagen::getMarke() { return this->marke; }
std::string Mietwagen::getKennzeichen() { return this->kennzeichen; }