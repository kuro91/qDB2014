#ifndef DIPENDENTEMENSILIZZATO_H
#define DIPENDENTEMENSILIZZATO_H
#include "dipendente.h"
#include <string>
using std::string;

//sottoclasse astratta di Dipendente
class DipendenteMensilizzato: public Dipendente{
private:
    double mensilita;

public:
    DipendenteMensilizzato();
    DipendenteMensilizzato(string,string,int,double);
    double getMensilita() const;
    void setMensilita(double);
    //overloading operator==
    bool operator==(const DipendenteMensilizzato&) const;
    //overloading operator=
    DipendenteMensilizzato& operator=(const DipendenteMensilizzato&);
};

#endif // DIPENDENTEMENSILIZZATO_H
