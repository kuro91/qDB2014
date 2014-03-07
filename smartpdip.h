#ifndef SMARTPDIP_H
#define SMARTPDIP_H
#include "dipendente.h"
#include <iostream>
using std::ostream;

/*
 *DA FARE: capire cosa ci si aspetta che faccia operator=
 * e costr copia
 *operator<< => chiama print
 *
 *
 */

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

#endif // SMARTPDIP_H
