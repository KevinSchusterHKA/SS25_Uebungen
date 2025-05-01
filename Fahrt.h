#pragma once
#include <string>
using namespace std;

class Fahrt {
private:
	int nummer;
	string kunde;
	int abholddatum;
	int abgabedatum;
public:
	Fahrt(int n, string k, int ab, int bis);	//uberlagerung konstruktor

	void anzeigen();
	int getNummer();
	int getAbholddatum();
	int getAbgabedatum();
	string getKunde();
};