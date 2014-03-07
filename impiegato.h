#ifndef IMPIEGATO_H
#define IMPIEGATO_H
#include "dipendentemensilizzato.h"
#include <string>
using std::string;

class Impiegato: public DipendenteMensilizzato{
private:
    //campo booleano che indica il posseso di ecdl
    bool ecdl;
public:
    Impiegato();
    Impiegato(string,string,int,double,bool);
    //overriding di Dipendente::retribuzione()
    //restituisce la mensilità
    double retribuzione() const;
    //overriding di Dipendente::print()
    void print() const;
    //indica se in possesso di ecdl
    bool hasEcdl() const;
    //modifica il possesso di ecdl
    void setEcdl(bool);
    //override operator==
    bool operator==(const Dipendente&) const;
    //override operator=
    Impiegato& operator=(const Dipendente&);
    //override clona()
    Impiegato* clona() const;
    //override toString()
    string toString() const;
};

#endif // IMPIEGATO_H
