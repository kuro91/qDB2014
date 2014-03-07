#include "smartpdip.h"
#include <typeinfo>
using namespace std;

SmartpDip::SmartpDip(Dipendente* p):punt(p){}

Dipendente& SmartpDip::operator*(){
    return *punt;
}

const Dipendente& SmartpDip::operator*() const{
    return *punt;
}

Dipendente* SmartpDip::operator->(){
    return punt;
}

const Dipendente* SmartpDip::operator->() const{
    return punt;
}

bool SmartpDip::operator==(const SmartpDip& p) const{
    return *punt==*p;
}

SmartpDip::SmartpDip(const SmartpDip & p):punt(p->clona()){}

SmartpDip& SmartpDip::operator=(const SmartpDip& p){
    if(this!=&p){
        delete punt;
        punt=p->clona();
    }
    return *this;
}

SmartpDip::~SmartpDip(){
    delete punt;
}


//operatore di output ridefinito esternamente
ostream& operator<<(ostream& os, const SmartpDip& p){
    os<<p->toString();
    return os;
}
