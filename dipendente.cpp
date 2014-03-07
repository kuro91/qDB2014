#include "dipendente.h"
#include<string>
using std::string;

Dipendente::Dipendente():nome(""), cognome(""), recapito_tel(0){}

Dipendente::Dipendente(string n, string c, int tel):nome(n), cognome(c), recapito_tel(tel){}

Dipendente::~Dipendente(){}

string Dipendente::getNome() const{
    return nome;
}

void Dipendente::setNome(string n){
    nome=n;
}

string Dipendente::getCognome() const{
    return cognome;
}

void Dipendente::setCognome(string c){
    cognome=c;
}

void Dipendente::setRecapitoTel(int num){
    recapito_tel=num;
}

int Dipendente::getRecapitoTel() const{
    return recapito_tel;
}

bool Dipendente::operator==(const Dipendente& d) const{
    return (nome==d.nome && cognome==d.cognome && recapito_tel==d.recapito_tel);
}

Dipendente& Dipendente::operator=(const Dipendente& d){
    nome=d.nome;
    cognome=d.cognome;
    recapito_tel=d.recapito_tel;
    return *this;
}

