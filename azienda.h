#ifndef AZIENDA_H
#define AZIENDA_H
#include "containerTemplate.h"
#include "dipendente.h"

/*
 *classe che utilizza il container e mette a disposizione le funzioni di ricerca e modifica
 *e eliminazione e inserimento
 *NB cancellare smartdip.h e .cpp se questo funziona*/

class Azienda{
private:
    class SmartpDip{
        friend ostream& operator<<(ostream&, const SmartpDip&);
        //operatore di output esterno, chiama punt->toString()
        //e lo mette in un ostream
    private:
        Dipendente* punt;
    public:
        SmartpDip(Dipendente* p);
        //dereferenziazione per SmartpDip
        Dipendente& operator*();
        //dereferenziazione per SmartpDip costanti
        const Dipendente& operator*() const;
        //accesso a membro
        Dipendente* operator->();
        const Dipendente* operator->() const;
        //overloading di ==
        /*
         *uso typeid(*punt)==typeid(*p)
         *per determinare se hanno lo stesso tipo dinamico
         *in caso affermativo sfrutto == virtuale e polimorfismo
         *di punt
         */
        bool operator==(const SmartpDip&) const;
        //overloading di =
        /*
         *uso typeid(*punt)==typeid(*p)
         *per determinare se hanno lo stesso tipo dinamico
         *in caso affermativo sfrutto = virtuale e polimorfismo
         *di punt
         */
        //copia profonda
        SmartpDip(const SmartpDip&);
        //assegnazione profonda
        SmartpDip& operator=(const SmartpDip&);
        //overloading distruttore
        ~SmartpDip();
    };

    Container<SmartpDip>* c;
public:
    Azienda();
};

#endif // AZIENDA_H
