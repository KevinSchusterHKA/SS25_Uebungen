#pragma once
#include<vector>
#include<string>
#include<iostream>

#include"Fahrt.h"
class Mietwagen
{
private:
	std::string marke = "";
	std::string kennzeichen = "";
	int sitze = 0;
	std::vector<Fahrt> fahrtenbuch;
public:
	Mietwagen();
	Mietwagen(std::string m, std::string k,int s,Fahrt f);//um Test werte schnell einzuladen
	void anmieten(Fahrt F);
	void fahrtAnzeigen(int nummer);
	void alleFahrtenAnzeigen(void);
	bool nummerPruefen(int nummer);
	bool fahrtLoeschen();
	bool verfuegbarkeitPruefen(Fahrt f);
	void fahrzeugAnzeigen();
	void insertionsortFahrten(int Sortierrichtung);
	std::string getMarke();
	std::string getKennzeichen();
};

