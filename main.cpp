#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    cout << endl << "feladat itt: http://people.inf.elte.hu/gt/prog/hf2_CE.pdf" << endl;
    cout << "feldat megoldasa: szamlalasba agyazott linker" << endl;
    cout << "Amikor nem vasaroltak 'arukod23' -at(mindet) | es mikor vettek a legtobb arut - ki mikor hanyfelet?"<< endl;
    cout << "egyedi felsorolo hasznalata" << endl << endl;

    string fname;
    bool hiba;
    do{
        try{
            hiba=false;
            cout<<"Add meg a fajl nevet: ";
            cin>>fname;
            enor t(fname);
            //k�t �sszegz�s
            bool l=false;
            //for(t.first(); !t.end(); t.next())
            //Ha az ures fajlra hibat kell jelezni
            vasarlas MostOfItem;

            t.first();
            if(t.end())
            {
                cout<<"Ures a fajl, nem lehet feldolgozni!\n";
                hiba=true;
                break;
            }
            for(;!t.end(); t.next())
            {
                //vetites q=t.current();
                //cout<<"*****"<<q;
                /*cout<<q.ido<<" "<<q.id[q.id.size()-1]<<" "<<q.sum;
                if(q.jo) cout<<" (csak diak)\n"; else cout<<endl;
                l= l || q.jo;*/
            }
            /*if(l)
                cout<<"Volt olyan vetites, amelyikre csak diakok valtottak jegyet\n";
            else
                cout<<"Nem volt olyan vetites, amelyikre csak diakok valtottak jegyet\n";
            */
        }catch(enor::enorerror err)
        {
            if(err==enor::OpenError)
            {
                cerr<<fname<<" nem nyithato meg!\n";
                hiba=true;
            }
        }
    }while(hiba);

    return 0;
}
