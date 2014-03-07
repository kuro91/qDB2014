#ifndef DIPENDENTE_H
#define DIPENDENTE_H
#include<string>
using std::string;


//Classe Base Astratta
class Dipendente{
private:
    string nome;
    string cognome;
    int recapito_tel;
public:
    Dipendente();
    Dipendente(string, string, int);
    string getNome() const;
    void setNome(string);
    string getCognome() const;
    void setCognome(string);
    int getRecapitoTel() const;
    void setRecapitoTel(int);
    //retribuzione ritorna la mensilità per ogni sottotipo di dipendente
    //va overridata e definita nelle sottoclassi
    //ad esempio per operaio è compenso/ora * ore del contratto
    //per impiegato è la retribuzione mensile stessa
    virtual double retribuzione() const=0;
    //funzione di stampa
    virtual void print() const=0;
    //virtualizazione del distruttore
    virtual ~Dipendente();
    //virtualizzazione pura dell'operatore di uguaglianza
    /*nelle classi derivate non va fatto l'overriding,
    *ma un overloading per cambiare il parametro formale
    *in questo modo ad esempio
    *DipendenteOre d, e; Dipendente* p=&d
    * *p==e => binding statico, esiste == in Dipendente, è virtuale, perciò usa quello
    *del tipo dinamico, che viene overridato*/
    virtual bool operator==(const Dipendente&) const;
    //virtualizzazione operatore di assegnazione
    //spiegazione simile a operator=
    virtual Dipendente& operator=(const Dipendente&);
    //metodo che sopperisce l'impossibile copia profonda virtuale
    virtual Dipendente* clona() const =0;
    //metodo virtuale toString(), ritorna una stringa formattata contenente
    //la conversione dei campi dati del Dipendente
    virtual string toString() const =0;
};

#endif // DIPENDENTE_H
