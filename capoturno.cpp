#include "capoturno.h"
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::string;
using std::stringstream;

CapoTurno::CapoTurno():DipendenteMensilizzato(),
    bonus_reperibilita(0.0),tel_aziendale(0){}

CapoTurno::CapoTurno(string n, string c, int tel, double m, double b, int tel_a):
    DipendenteMensilizzato(n,c,tel,m), bonus_reperibilita(b), tel_aziendale(tel_a){}

double CapoTurno::retribuzione() const{
    return getMensilita()+bonus_reperibilita;
}

double CapoTurno::getBonus() const{
    return bonus_reperibilita;
}

void CapoTurno::setBonus(double b){
    bonus_reperibilita=b;
}

int CapoTurno::getTelAziendale() const{
    return tel_aziendale;
}

void CapoTurno::setTelAziendale(int t){
    tel_aziendale=t;
}

void CapoTurno::print() const{
    cout<<"Nome: "<<getNome()<<"\n"<<"Cognome: "<<getCognome()<<"\n"
       <<"Mensilita': "<<getMensilita()<<"\n"<<"Bonus: "<<getBonus()<<"\n"
      <<"Retribuzione mensile: "<<retribuzione()<<"\n"
     <<"Recapito: "<<getRecapitoTel()<<"\n"
    <<"Telefono aziendale: "<<getTelAziendale()<<"\n";
}

bool CapoTurno::operator==(const Dipendente& d) const{
    const CapoTurno* cp=dynamic_cast<const CapoTurno*>(&d);
    if(cp && DipendenteMensilizzato::operator==(*cp)){
        if(bonus_reperibilita==cp->bonus_reperibilita && tel_aziendale==cp->tel_aziendale)
            return true;
        else
            return false;
    }else
        return false;
}

CapoTurno& CapoTurno::operator=(const Dipendente& c){
    const CapoTurno* cp=dynamic_cast<const CapoTurno*>(&c);
    if(cp){
        DipendenteMensilizzato::operator=(*cp);
        bonus_reperibilita=cp->bonus_reperibilita;
        tel_aziendale=cp->tel_aziendale;
    }
    return *this;
}

CapoTurno* CapoTurno::clona() const{
    return new CapoTurno(*this);
}

string CapoTurno::toString() const{
    stringstream s;
    string res;
    s<<"Nome: "<<getNome()<<"\n"<<
            "Cognome: "<<getCognome()<<"\n"<<
            "Mensilita': "<<getMensilita()<<"\n"<<
            "Bonus: "<<getBonus()<<"\n"<<
            "Retribuzione mensile: "<<retribuzione()<<"\n"<<
            "Recapito: "<<getRecapitoTel()<<"\n"<<
            "Tel Aziendale: "<<getTelAziendale()<<"\n";
    res=s.str();
    return res;
}
