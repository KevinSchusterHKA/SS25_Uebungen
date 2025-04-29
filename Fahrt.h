#pragma once
#include <string>
#include "iostream"
class Fahrt {
private:
	int nummer, abholdatum,abgabedatum;
	std::string kunde;

public:
	Fahrt(int n, std::string k, int ab, int bis);
	void anzeigen();
	int getNummer();
	int getAbholdatum();
	int getAbgabedatum();
	bool verfuegbarkeitPruefen(Fahrt f);
};