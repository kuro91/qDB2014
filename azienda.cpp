#include "azienda.h"

using namespace std;

Azienda::SmartpDip::SmartpDip(Dipendente* p):punt(p){}

Dipendente& Azienda::SmartpDip::operator*(){
    return *punt;
}

const Dipendente& Azienda::SmartpDip::operator*() const{
    return *punt;
}

Dipendente* Azienda::SmartpDip::operator->(){
    return punt;
}

const Dipendente* SmartpDip::operator->() const{
    return punt;
}

bool Azienda::SmartpDip::operator==(const SmartpDip& p) const{
    return *punt==*p;
}

Azienda::SmartpDip::SmartpDip(const SmartpDip & p):punt(p->clona()){}

Azienda::SmartpDip& SmartpDip::operator=(const SmartpDip& p){
    if(this!=&p){
        delete punt;
        punt=p->clona();
    }
    return *this;
}

Azienda::SmartpDip::~SmartpDip(){
    delete punt;
}


//operatore di output ridefinito esternamente per smartdip
ostream& operator<<(ostream& os, const Azienda::SmartpDip& p){
    os<<p->toString();
    return os;
}


Azienda::Azienda():c(new Container<SmartpDip>()){}
