#ifndef DIPENDENTEORE_H
#define DIPENDENTEORE_H
#include "dipendente.h"
#include <string>
using std::string;

//sottoclasse concreta propria di Dipendente
class DipendenteOre: public Dipendente{
private:
    int ore_contratto;
    double retribuzione_ora;
public:
    DipendenteOre();
    DipendenteOre(string, string, int, int, double);
    //ovverriding di Dipendente::Retribuzione
    //restituisce la retribuzione giornaliera
    double retribuzione() const;
    //overridind di Dipendente::stampa()
    void print() const;
    //modificare le ore del contratto
    void setOreContratto(int);
    //visualizza le ore del contratto
    int getOreContratto() const;
    //modifica la retribuzione/ora
    void setRetribuzioneOra(double);
    //visualizza la retribuzione/ora
    double getRetribuzioneOra() const;
    //overload operator==, non fa overridind di Dipendente::operator==
    //poiché la lista di parametri è diversa
    bool operator==(const Dipendente&) const;
    //override operator=
    DipendenteOre& operator=(const Dipendente&);
    //override clona()
    DipendenteOre* clona() const;
    //override toString()
    string toString() const;
};

#endif // DIPENDENTEORE_H
