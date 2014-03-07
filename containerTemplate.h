/*
 *@author: Andrea Ongar
 *
 *Prima implementazione della classe Container.
 *ContainerItem rappresenta la collezione, gestita mediante lista concatenata
 *e gestione della memoria attraverso reference counting
 *ItemPointer è una classe di smartpointer, volta a semplificare l'utilizzo del
 *reference counting
 *Iterator è una classe  di iteratori per la collezione
 *NB Container amica con Iterator, e viceversa
 *Container e Iterator amici con print() ma non viceversa
 */
#ifndef CONTAINERTEMPLATE_H
#define CONTAINERTEMPLATE_H

/*
 *DA FARE
 * merge di due contenitori
 *
 *RICORDARE:
 *quando creo SmartVeicolo che contiene un puntatore veicolo*
 *l'assegnazione tra SmartVeicolo DEVE essere profonda
 *altrimenti operator[](Iterator it) crea copie profonde di puntatori a veicolo
 *ma non copia in automatico i veicoli puntati, morale non servirebbe a nulla
 *
 *NB modificare insert per evitare che ci siano inseriti oggetti uguali
 */

#include<iostream>
using std::cout;
using std::ostream;

template <class T> class Container;

template <class T> void print(const Container<T>&);

template <class T>  ostream& operator<<(ostream&,const Container<T>&);

template <class T>
class Container{//classe contenitore: collezione di oggetti
    friend class Iterator;
    friend void print<T>(const Container<T>&);
    friend ostream& operator<< <T>(ostream&, const Container<T>&);
public:
    class ContainerItem;
    class ItemPointer{//puntatori smart per gestione del reference counting
    public:
        ContainerItem* nodo;
        //costruttore a 0 e 1 parametri
        ItemPointer(ContainerItem* p = 0);
        //costruttore di copia
        ItemPointer(const ItemPointer&);
        //distruttore
        ~ItemPointer();
        //assegnazione
        ItemPointer& operator=(const ItemPointer&);
        //operatore di dereferenziazione
        ContainerItem& operator*() const;
        //operatore di accesso a membro
        //per poter fare p->next anziché p.nodo->next
        ContainerItem* operator->() const;
        //operatore di uguaglianza
        bool operator==(const ItemPointer&) const;
        //operatore di disuguaglianza
        bool operator!=(const ItemPointer&) const;
    };
    class ContainerItem{//classe template per la collezione
    public:
        T info;
        ItemPointer next;
        //costruttore di default
        ContainerItem();
        //costruttore a 2 parametri
        //NB next(p) costruttore di copia di ItemPointer
        //grazie alla getsione come smartpointer aumenta di 1 i riferimenti
        //all'oggetto puntato da p
        ContainerItem(const T&, ItemPointer);
        int riferimenti;
    };
    ItemPointer first;
public:
    /*
     *Se c è un Container si vuole che
     *const_iteratore it
     *c[it] ritorni un valore non modificabile
     *iteratore it
     *c[it] ritorni un T&
     *
     *quindi operator[](Iterator) deve creare una copia profonda della lista fino al noto puntato da it
     *in questo modo c[it]=qualcosa, apporta una modifica in una copia profonda
     *
     *NB con l'implementazione successiva
     *se si vuole ottenere il valore
     *c[it] senza modificarlo è doveroso usare un const_iteratore, altrimenti
     *viene creata inutilmente una copia profonda dalla ridefinizione
     *di operator[](iteratore)
     */

    //iteratore
    class Iterator{
        /*
         *Container è dotata di iteratore
         *una possibile implementazione futura potrebbe essere quella
         *di rendere possibile es
         *c["stringa"] per una ricerca nella collezione secondo qualche parametro
         */
        friend class Container<T>;
    private:
        Container::ItemPointer p;
    public:
        //operatore di uguaglianza
        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;
        //operatore ++ prefisso
        Iterator& operator++();
    };

    //const_iteratore
    class const_Iterator{
        /*
         *utilizzato per ottenre oggetti T costanti e non modificabili
         *ad esempio per scorrere semplicemente la lista come in print
         */
        friend class Container<T>;
        //NB amicizia anche con Iteratore se voglio stampare scorrendo la lista
        //perché p è privato e anche dichiarando print amica di Container
        //non è amica di Iterator
        friend void print<T>(const Container<T>&);
    private:
        Container::ItemPointer p;
    public:
        const_Iterator();
        //costruttore di default come convertitore di tipo, in caso un contenitore non const
        //voglia usare const_Iterator, poiché non riuscirebbe a fare overload di begin()
        const_Iterator(const Iterator&);
        bool operator==(const const_Iterator&) const;
        bool operator!=(const const_Iterator&) const;
        //operatore ++ prefisso
        const_Iterator& operator++();
    };

    //controllo se il container è vuoto
    bool isEmpty() const;
    //size
    int size()const;
    //aggiunge un oggetto T in testa alla collezione
    void add(const T&);
    //rimuove un oggetto dalla lista
    void remove(const T&);
    //posizione del nodo nella lista, ritorna un const_iteratore, se 0 allora non c'è l'elemento
    const_Iterator position(const T&) const;

    //controlla se un elemento è presente
    bool isPresent(const T&) const;

    //METODI PER UTILIZZARE L'ITERATORE
    //non sono marchiati const per permettere l'overloading con quelli che sfruttano i cont_Iteratore
    //anche se effettivamente non fa side-effect sul Container
    //inizio della collezione
    Iterator begin();
    //fine della collezione
    Iterator end();
    //operatore di indicizzazione
    T& operator[](Iterator&);

    //METODI PER UTILIZZARE const_Iteratore
    //inizio della collezione
    const_Iterator begin() const;
    //fine della collezione
    const_Iterator end() const;
    //operatore di indicizzazione
    const T& operator[](const const_Iterator&) const;
};

/*METODI DI ITEMPOINTER =================================================================*/

//costruttore a 0 e 1 parametri
template <class T>
Container<T>::ItemPointer::ItemPointer(ContainerItem* p):nodo(p){
    if(nodo)
        nodo->riferimenti++;
}

//costruttore di copia
template <class T>
Container<T>::ItemPointer::ItemPointer(const ItemPointer & ip):nodo(ip.nodo){
    if(nodo)
        nodo->riferimenti++;
}

//distruttore
template <class T>
Container<T>::ItemPointer::~ItemPointer(){
    if(nodo){
        nodo->riferimenti--;
        if(nodo->riferimenti == 0)
            delete nodo;//delete della classe dell'oggetto puntato da nodo
    }
}

//operatore di assegnazione
template <class T>
typename Container<T>::ItemPointer& Container<T>::ItemPointer::operator=(const ItemPointer& ip){
    if(this != &ip){
        ContainerItem* t = nodo;
        nodo = ip.nodo;
        if(nodo)
            nodo->riferimenti++;
        if(t){
            t->riferimenti--;
            if(t->riferimenti == 0)
                delete t; //delete dell'oggetto di tipo T puntato
        }
    }
    return *this;
}

//operatore di derefernziazione
template <class T>
typename Container<T>::ContainerItem& Container<T>::ItemPointer::operator*() const{
    return *nodo;//ottengo un ContainerItem indirizzabile
}

//operatore di accesso a membro
template <class T>
typename Container<T>::ContainerItem* Container<T>::ItemPointer::operator->() const{
    return nodo;
}

//operatore di uguaglianza
template <class T>
bool Container<T>::ItemPointer::operator==(const ItemPointer& ip) const{
    return nodo == ip.nodo;
}

//operatore di disuguaglianza
template <class T>
bool Container<T>::ItemPointer::operator!=(const ItemPointer& ip) const{
    return nodo != ip.nodo;
}


/*METODI DI CONTAINER ITEM=======================================================*/

//costruttore di default
template <class T>
Container<T>::ContainerItem::ContainerItem():next(0), riferimenti(0){}

//costruttore a due parametri
template <class T>
Container<T>::ContainerItem::ContainerItem(const T& t, ItemPointer p):info(t),next(p),riferimenti(0){}


/*METODI DI ITERATOR============================================================*/

template <class T>
bool Container<T>::Iterator::operator==(const Iterator& i) const{
    return p == i.p; //uguaglianza ridefinita tra Itempointer
}

template <class T>
bool Container<T>::Iterator::operator!=(const Iterator& i) const{
    return p != i.p; //disuguaglianza ridefinita tra Itempointer
}

template <class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++(){
    if(p!=0)
        p=p->next;//nessun problema con riferimenti, aggiornato automaticamente
                   //assegnazione tra ItemPointer
    return *this;
}


/*METODI DI CONST_ITERATOR======================================================*/
//costruttore di default
template <class T>
Container<T>::const_Iterator::const_Iterator():p(0){}

//costruttore come convertitore Iterator => const_Iterator poiché
//il tipo di ritorno non basta per overloadare begin(), se in contenitore
//non è costante
template <class T>
Container<T>::const_Iterator::const_Iterator(const Iterator & it){
    p=it.p;
}

//operatore di uguaglianza
template <class T>
bool Container<T>::const_Iterator::operator==(const const_Iterator& i) const{
    return p == i.p; //uguaglianza ridefinita tra Itempointer
}

template <class T>
bool Container<T>::const_Iterator::operator!=(const const_Iterator& i) const{
    return p != i.p; //disuguaglianza ridefinita tra Itempointer
}

template <class T>
typename Container<T>::const_Iterator& Container<T>::const_Iterator::operator++(){
    if(p!=0)
        p=p->next;//nessun problema con riferimenti, aggiornato automaticamente
                   //assegnazione tra ItemPointer
    return *this;
}


/*METODI DI CONTAINER===========================================================*/

//controllo se il container è vuoto
template <class T>
bool Container<T>::isEmpty() const{
    return first == 0;
}
//aggiunge un oggetto T in testa alla collezione
template <class T>
void Container<T>::add(const T& t){
    first = new ContainerItem(t,first);//possibile grazie al cast implicito da ContainerItem* a ItemPointer
                                    //grazie al costruttore come convertitore di tipo
    //anche qui, overloading di operator= per ItemPointer => gestione automatica di riferimenti
}
//rimuove un oggetto dalla lista
template <class T>
void Container<T>::remove(const T& t){
    if(!isEmpty()){
        ItemPointer p = first, prec, q;
        ItemPointer original = first;
        first = 0;
        while(p!=0 && !(p->info == t)){
            q = new ContainerItem(p->info, p->next);
            if(prec == 0)
                first = q;
            else
                prec->next = q;
            prec = q;
            p = p->next;
        }
        if(p == 0){
            first = original;
        }else if(prec == 0){
            first = p->next;
        }else{
            prec->next = p->next;
        }
    }
}

//size
template <class T>
int Container<T>::size()const{
    int cont=0;
    for(const_Iterator it=begin(); it!=end();++it){
        cont++;
    }
    return cont;
}


//position
template <class T>
typename Container<T>::const_Iterator Container<T>::position(const T& t) const{
    bool trovato=false;
    const_Iterator p;
    p.p=0;
    for(Container<T>::const_Iterator it=begin(); it!=end() && !trovato; ++it){
        if(it.p->info == t){
            trovato=true;
            p.p=it.p;
        }
    }
    return p;
}

//isPresent
template <class T>
bool Container<T>::isPresent(const T& t) const{
    const_Iterator p=position(t);
    if(p.p!=0)
        return true;
    else
        return false;
}

//METODI PER UTILIZZARE L'ITERATORE
template <class T>
typename Container<T>::Iterator Container<T>::begin() {
    Iterator it;//costruzione con costruttore di default
    it.p=first;//assegnazione tra Itempointer, gestione automatica di riferimenti
    return it;//interviene costruttore di copia, agisce su riferimenti, quando
                //viene distrutto il temporaneo anonimo quando viene assegnato, riferimenti
                //gestito dal ditruttore ridefinito di ItemPointer
}
//fine della collezione
template <class T>
typename Container<T>::Iterator Container<T>::end() {
    Iterator it;
    it.p=0;
    return it;
}
//operatore di indicizzazione
template <class T>
T& Container<T>::operator[](Iterator& it) {
    //consente di modificare l'oggetto puntato da it
    //controllo il campo riferimenti, se è > 0 creo una
    //copia profonda altrimenti è possibile modificare
    //il campo info dell'oggetto puntato
    ItemPointer r=first, prec=0,q;
    bool trovato=false;
    first=0;
    while(r!=0 && !trovato){
        q=new ContainerItem(r->info, r->next);
        if(prec==0){
            first=q;
            prec=q;
        }else{
            prec->next=q;
            prec=prec->next;
        }

        if(r==it.p){
            trovato=true;
        }
        r=r->next;
    }
    //sposto l'iteratore sull'oggetto nella copia profonda
    it.p=prec;
    return prec->info;
}


//METODI PER UTILIZZARE const_Iteratore
//inizio della collezione
template <class T>
typename Container<T>::const_Iterator Container<T>::begin() const{
    const_Iterator it;//costruzione con costruttore di default
    it.p=first;//assegnazione tra Itempointer, gestione automatica di riferimenti
    return it;//interviene costruttore di copia, agisce su riferimenti, quando
                //viene distrutto il temporaneo anonimo quando viene assegnato, riferimenti
                //gestito dal ditruttore ridefinito di ItemPointer
}
//fine della collezione
template <class T>
typename Container<T>::const_Iterator Container<T>::end() const{
    const_Iterator it;
    it.p=0;
    return it;
}
//operatore di indicizzazione
template <class T>
const T& Container<T>::operator[](const const_Iterator& it) const{
    return it.p->info;//conversione T& => const T&
}

/*FUNZIONE ESTERNA DI STAMPA ====================================================*/
template <class T>
void print(const Container<T>& c){
    for(typename Container<T>::const_Iterator it=c.begin(); it!=c.end();++it){
        cout<<c[it]<<" ";
    }
    cout<<"\n";
}

template <class T>
ostream& operator<<(ostream& os, const Container<T>& c){
    for(typename Container<T>::const_Iterator it=c.begin(); it!=c.end();++it){
        os<<c[it]<<"\n";
    }
    return os;
}

#endif // CONTAINERTEMPLATE_H
