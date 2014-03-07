#ifndef CAPOTURNO_H
#define CAPOTURNO_H
#include <string>
#include "dipendentemensilizzato.h"
using std::string;

//concretizza dipendente e dipendente mensilizzato
class CapoTurno: public DipendenteMensilizzato{
private:
    //bonus per reperibilita al di fuori dell'orario di lavoro
    double bonus_reperibilita;
    //numero di telefono interno all'azienda
    int tel_aziendale;
public:
    CapoTurno();
    CapoTurno(string,string,int,double,double,int);
    //overriding di Dipendente::retribuzione()
    //restituisce la mensilità+bonus
    double retribuzione() const;
    //overriding di Dipendente::print()
    void print() const;
    //visualizzare il bonus
    double getBonus() const;
    //modificare il bonus
    void setBonus(double);
    //visualizzare il telefono aziendale
    int getTelAziendale() const;
    //modificare il telefono aziendale
    void setTelAziendale(int);
    //override operator==
    bool operator==(const Dipendente&) const;
    //override operator=
    CapoTurno& operator=(const Dipendente&);
    //override clona()
    CapoTurno* clona() const;
    //override toString()
    string toString() const;

};

#endif // CAPOTURNO_H
