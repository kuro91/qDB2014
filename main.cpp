#include <iostream>
#include <containerTemplate.h>
#include "dipendenteore.h"
#include "capoturno.h"
#include "dipendente.h"
#include "smartpdip.h"
using namespace std;

int main()
{


    SmartpDip smtp=new CapoTurno("Mario","Rotti",1234,1500.0,200.0,33478);

    Container<SmartpDip>* c2 = new Container<SmartpDip> ();
    c2->add(smtp);
    c2->add(new CapoTurno("Marcio","Rosi",1234,1500.0,200.0,33478));
    c2->add(new DipendenteOre("Filippo","Cachi",1234,7,5.6));

    //
    //(*c2)[ittt]->print();
    //++ittt;
    //(*c2)[ittt]->print();


    cout<<*c2<<"\n";

    SmartpDip smtpx=new CapoTurno("Anorio","Rotti",1234,1500.0,200.0,33478);
    if(smtpx==smtp)
        cout<<"uguali \n";
    Container<SmartpDip>::const_Iterator ittt=c2->position(smtp);
    cout<<"PROVA POSITION() \n";
    if(c2->isPresent(smtp))
        cout<<"c'è \n";
    else
        cout<<"non c'è \n";
    //cout<<(*c2)[ittt]<<"\n";

    /*cout<<"prova costruttore copia \n";
    SmartpDip copia = smtp;
    copia->print();*/

    //test reference counting
    /*
    Container<SmartpDip> c4=*c2;
    //Container<SmartpDip>::Iterator it2=c2->begin();

    cout<<"c2 dopo rimozione \n";
    cout<<*c2<<"\n";
    cout<<"c4 dopo rimozione in c2 \n";
    cout<<c4<<"\n";
    */

    cout<<"CON IT2 \n";

    Container<SmartpDip>::Iterator it2=c2->begin();
    cout<<(*c2)[it2]->getNome()<<"\n";
    cout<<(*c2)[it2]->getNome()<<"\n";
   // cout<<(*c2)<<"\n";

    /*
    ++it2;
    cout<<(*c2)[it2]<<"\n";
    c2->remove(smtp);
    cout<<*c2;
    cout<<"CON ITE const \n";
    Container<SmartpDip>::const_Iterator ite=c2->begin();
    cout<<(*c2)[ite]->getNome()<<(*c2)[ite]->getCognome()<<"\n";

    cout<<"FOR \n";
    Container<SmartpDip>* c3=new Container<SmartpDip>();
    for (Container<SmartpDip>::Iterator it3=c2->begin(); it3!=c2->end(); ++it3){
        cout<<"iterazione \n";
        if((*c2)[it3]->getNome()=="Marcio" && (*c2)[it3]->getCognome()=="Rosi"){
            cout<<"trovato \n";
            c3->add((*c2)[it3]);
        }else{
            cout<<(*c2)[it3]<<"\n";

        }
    }

    cout<<"C: \n"<<*c3<<"\n";
    Container<SmartpDip>::Iterator it4=c2->begin();
    (*c3)[it4]=new CapoTurno("Mario","Rotti",1234,1500.0,200.0,33478);
    cout<<*c3<<"\n";*/

    return 0;
}

