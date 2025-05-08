#include "Mietwagen.h"
#include <iostream>
#include "Fahrt.h"
using namespace std;

Mietwagen::Mietwagen(){
    cout << "Fahrzeug mieten" << endl;

    cout<<"Neues Fahrzeug:\n"<<endl;

    cout<<"Automarke?";
    
    cin>>marke;

    cout<<"KFZ-Kennzeichen?";
    
    cin>>kennzeichen;
    cout<<"Sitze";
    
    cin>>sitze;

    // marke="Unkonw";
    // sitze=0;
    // kennzeichen="";
    cout<<"Fahrzeug "<<marke<<" mit KFZ-Kennzeicchen "<<kennzeichen<<" und "<<sitze<<" Sitzen wurde aufgenommen"<<endl;
} // Constructor
// Mietwagen::Mietwagen(string marke, string kennzeichen,int sitze){
//     this->marke=marke;
//     this->kennzeichen=kennzeichen;
//     this->sitze=sitze;
//     cout<<"Fahrzeug "<<marke<<" mit KFZ-Kennzeicchen "<<kennzeichen<<" und "<<sitze<<" Sitzen wurde aufgenommen";
// }
Mietwagen::~Mietwagen(){} // Destructor

void Mietwagen::anmieten(Fahrt f){
    this->fahrtenbuch.push_back(f);
    //output success
    cout<<"Fahrt "<<f.getNummer()<<" erfolgreich angelegt."<<endl;
} // Function to rent the car,
void Mietwagen::fahrtAnzeigen (int nummer){
    for (Fahrt f:this->fahrtenbuch){
        if (f.getNummer()==nummer){
            cout<<"Nr. "<<f.getNummer()<<" : Kunde "<< f.getkunde()<<" holt Fahrzeug am "<< f.getabdatum()<<"ab und bringt es am "<<f.getzurueckdatum()<<" zurueck"<<endl;
            return;
        }
    }
    cout<<"Fahrt existiert nicht"<<endl;
    return;
}

void Mietwagen::alleFahrtenAnzeigen(){
        if (this->fahrtenbuch.empty()){
            cout<<"Mietwagen wurde noch nicht verliehen"<<endl;
        }
        else {
            for (Fahrt f:this->fahrtenbuch){
                cout<<"Nr. "<<f.getNummer()<<" : Kunde "<< f.getkunde()<<" holt Fahrzeug am "<< f.getabdatum()<<"ab und bringt es am "<<f.getzurueckdatum()<<" zurueck"<<endl;
                cout<<"---------------------------------------------------------"<<endl;
            }  
        }
    }
    void Mietwagen::alleFahrtensortAnzeigen(int order){
        if (this->fahrtenbuch.empty()){
            cout<<"Mietwagen wurde noch nicht verliehen"<<endl;
        }
        else {
            vector<Fahrt> orderedfahrtenbuch=sortbykundeNr(order);
            for (Fahrt f:orderedfahrtenbuch){
                cout<<"Nr. "<<f.getNummer()<<" : Kunde "<< f.getkunde()<<" holt Fahrzeug am "<< f.getabdatum()<<"ab und bringt es am "<<f.getzurueckdatum()<<" zurueck"<<endl;
                cout<<"---------------------------------------------------------"<<endl;
            }  
        }
    }
bool Mietwagen::nummerPruefen(int nummer){
    for (Fahrt f:this->fahrtenbuch){
        if (f.getNummer()==nummer)
        return true;}
    return false;
}

bool Mietwagen::fahrtLoeschen(int nummer){
    for (int i=0;i<this->fahrtenbuch.size();i++){
        if (this->fahrtenbuch[i].getNummer()==nummer){
                this->fahrtenbuch.erase(this->fahrtenbuch.begin()+i);
            return true;
        }
    }
    return false;
}

bool Mietwagen::verfuegbarkeitPruefen(Fahrt f){
    // if available true else false
    for (Fahrt fb:this->fahrtenbuch){
        if (fb.getabdatum()<=f.getabdatum()&&fb.getzurueckdatum()>=f.getabdatum())
        return false;
        else if (fb.getabdatum()<=f.getzurueckdatum()&&fb.getzurueckdatum()>=f.getzurueckdatum())
        return false;
        else if (f.getabdatum()<=fb.getabdatum()&&f.getzurueckdatum()>=fb.getabdatum())
        return false;  
    }
    return true;
}

void Mietwagen::fahrzeugAnzeigen(){
    cout << "->Fahrzeug : " << this->marke << ",mit Kennzeichen: " << this->kennzeichen << endl;
}

vector<Fahrt> Mietwagen::sortbykundeNr(int order){
    //sort KundeNr.
    vector<Fahrt> orderedfahrtenbuch=this->fahrtenbuch;
    if (order){
    for (int i = 1; i < orderedfahrtenbuch.size(); ++i) {
        Fahrt f = orderedfahrtenbuch[i];
        int j = i - 1;
        while (j >= 0 && f.getNummer() < orderedfahrtenbuch[j].getNummer()) {
            orderedfahrtenbuch[j + 1] = orderedfahrtenbuch[j];
                j--;
        }
        orderedfahrtenbuch[j + 1] = f;
    }
    }
    else{
        for (int i = 1; i < orderedfahrtenbuch.size(); ++i) {
            Fahrt f = orderedfahrtenbuch[i];
            int j = i - 1;
            while (j >= 0 && f.getNummer() > orderedfahrtenbuch[j].getNummer()) {
                orderedfahrtenbuch[j + 1] = orderedfahrtenbuch[j];
                    j--;
            }
            orderedfahrtenbuch[j + 1] = f;
        }
    }
    return orderedfahrtenbuch;
}

string Mietwagen::getmarke(){
    return this->marke;
}