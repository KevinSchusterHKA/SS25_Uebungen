#include "Mietwagen.h"
#include <iostream>

using namespace std;

Fahrt::Fahrt(){}
Fahrt::Fahrt(int n,string k, int ab, int bs){
    this->nummer=n;
    this->kunde=k;
    this->abgabedatum=ab;
    this->abholddatum=bs;

}
Fahrt::~Fahrt(){}

int Fahrt::getNummer(){
    return this->nummer;
}
string Fahrt::getkunde(){
    return this->kunde;}
int Fahrt::getabdatum(){
    return this->abgabedatum;
}
int Fahrt::getzurueckdatum(){
    return this->abholddatum;
}