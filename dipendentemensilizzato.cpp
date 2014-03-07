#include "dipendentemensilizzato.h"

DipendenteMensilizzato::DipendenteMensilizzato():Dipendente(),
    mensilita(0){}

DipendenteMensilizzato::DipendenteMensilizzato(string n, string c, int tel, double paga)
    :Dipendente(n,c,tel), mensilita(paga){}

double DipendenteMensilizzato::getMensilita() const{
    return mensilita;
}

void DipendenteMensilizzato::setMensilita(double m){
    mensilita=m;
}

bool DipendenteMensilizzato::operator==(const DipendenteMensilizzato& d) const{
    if(Dipendente::operator==(d)){
        if(mensilita==d.mensilita)
            return true;
        else
            return false;
    }else
        return false;
}

DipendenteMensilizzato& DipendenteMensilizzato::operator=(const DipendenteMensilizzato& d){
    Dipendente::operator=(d);
    mensilita=d.mensilita;
    return *this;
}
