#include "Fahrt.h"

Fahrt::Fahrt(int n, std::string k, int ab, int bis):nummer(n), kunde(k), abholdatum(ab), abgabedatum(bis) {

}
void Fahrt::anzeigen() {
	std::cout	<< "Kundennummer: " << this->nummer 
				<< " ,Kunde: " << this->kunde 
				<< " ,Abholdatum: " << this->abholdatum 
				<< " ,Abgabedatum: " << this->abgabedatum << std::endl;
}
int Fahrt::getNummer(){	return this->nummer;}
int Fahrt::getAbholdatum(){ return this->abholdatum; }
int Fahrt::getAbgabedatum(){ return this->abgabedatum; }
std::string Fahrt::getKunde() { return this->kunde; }
