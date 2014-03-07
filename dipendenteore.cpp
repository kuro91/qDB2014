#include "dipendenteore.h"
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::string;
using std::stringstream;

DipendenteOre::DipendenteOre(){}

DipendenteOre::DipendenteOre(string n, string c, int tel, int ore, double paga):
    Dipendente(n,c,tel), ore_contratto(ore), retribuzione_ora(paga){}

double DipendenteOre::retribuzione() const{
    return retribuzione_ora*ore_contratto;
}

int DipendenteOre::getOreContratto() const{
    return ore_contratto;
}

double DipendenteOre::getRetribuzioneOra() const{
    return retribuzione_ora;
}

void DipendenteOre::print() const{
    cout<<"Nome: "<<getNome()<<"\n"<<"Cognome: "<<getCognome()<<"\n"
       <<"Ore da contratto: "<<getOreContratto()<<"\n"<<"Paga oraria: "<<getRetribuzioneOra()<<"\n"
      <<"Retribuzione giornaliera: "<<retribuzione()<<"\n"
     <<"Recapito: "<<getRecapitoTel()<<"\n";
}

bool DipendenteOre::operator==(const Dipendente& d) const{
    const DipendenteOre* dp=dynamic_cast<const DipendenteOre*>(&d);
    if(dp && Dipendente::operator==(*dp)){
        if(ore_contratto==dp->ore_contratto && retribuzione_ora==dp->retribuzione_ora)
            return true;
        else
            return false;
    }else
        return false;
}

DipendenteOre& DipendenteOre::operator=(const Dipendente& d){
    const DipendenteOre* dp=dynamic_cast<const DipendenteOre*>(&d);
    if(dp){
        Dipendente::operator=(*dp);
        ore_contratto=dp->ore_contratto;
        retribuzione_ora=dp->retribuzione_ora;
    }
    return *this;
}

DipendenteOre* DipendenteOre::clona() const{
    return new DipendenteOre(*this);
}


string DipendenteOre::toString() const{
    stringstream s;
    string res;
    s<<"Nome: "<<getNome()<<"\n"<<
            "Cognome: "<<getCognome()<<"\n"<<"Ore da contratto: "<<getOreContratto()<<"\n"<<
            "Paga oraria: "<<getRetribuzioneOra()<<"\n"<<
            "Retribuzione giornaliera: "<<retribuzione()<<"\n"<<
            "Recapito: "<<getRecapitoTel()<<"\n";
    res=s.str();
    return res;


}
