#include "impiegato.h"
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::string;
using std::stringstream;

Impiegato::Impiegato(): DipendenteMensilizzato(),
    ecdl(false){}

Impiegato::Impiegato(string n, string c, int tel, double paga, bool e):
    DipendenteMensilizzato(n,c,tel,paga), ecdl(e){}


double Impiegato::retribuzione() const{
    return getMensilita();
}

bool Impiegato::hasEcdl() const{
    return ecdl;
}

void Impiegato::setEcdl(bool e){
    ecdl=e;
}

void Impiegato::print() const{
    string x="No";
    if(ecdl)
        x="Si";

    cout<<"Nome: "<<getNome()<<"\n"<<"Cognome: "<<getCognome()<<
          "\n"<<"ECDL: "<<x<<"\n"
      <<"Retribuzione mensile: "<<retribuzione()<<"\n"
     <<"Recapito: "<<getRecapitoTel()<<"\n";
}

bool Impiegato::operator==(const Dipendente& d) const{
    const Impiegato* cp=dynamic_cast<const Impiegato*>(&d);
    if(cp && DipendenteMensilizzato::operator==(*cp)){
        if(ecdl == cp->ecdl)
            return true;
        else
            return false;
    }else
        return false;
}

Impiegato& Impiegato::operator=(const Dipendente& c){
    const Impiegato* cp=dynamic_cast<const Impiegato*>(&c);
    if(cp){
        DipendenteMensilizzato::operator=(*cp);
        ecdl=cp->ecdl;
    }
    return *this;
}

Impiegato* Impiegato::clona() const{
    return new Impiegato(*this);
}

string Impiegato::toString() const{
    stringstream s;
    string res;
    string x="No";
    if(ecdl)
        x="Si";
    s<<"Nome: "<<getNome()<<"\n"<<
            "Cognome: "<<getCognome()<<"\n"<<
            "ECDL"<<x<<"\n"<<
            "Retribuzione mensile: "<<retribuzione()<<"\n"<<
            "Recapito: "<<getRecapitoTel()<<"\n";
    res=s.str();
    return res;
}
