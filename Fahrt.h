#pragma once
#include<iostream>
#include<string>
class Fahrt
{
private:
	int nummer = 0;
	std::string kunde = "";
	int abholdatum = 0;
	int abgabedatum = 0;
public:
	Fahrt(int n, std::string k, int ab, int bis);
	Fahrt() { ; }
	void anzeigen();
	std::string getKunde();
	int getNummer();
	int getAbholdatum();
	int getAbgabedatum();
};

