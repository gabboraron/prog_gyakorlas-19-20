#include "enor.h"
#include <iostream>
#include <sstream>

using namespace std;

enor::enor(const string& fname)
{
    x.open(fname.c_str());
    if(x.fail()) throw OpenError;
    cout<<fname<<" file feldolgozasa megkezdodott.\n";
}

void enor::first()
{
    //cout<<"first () " << endl;
    //maxboughtitem = 0;
    next();
}

void enor::next()
{
    //cout<<"next () " << endl;
    read();
    //osszegez();
}

void enor::read()
{
    //cout<<"read () " << endl;
    vasarlas vasarlo;
    string tmp;
    getline(x,tmp);
    istringstream ss(tmp);
    sx = x.fail()? abnorm : norm;

    string tmp2;
    bool isarukod23 = false;
    bool isnewitem = true;
    int c = 1;
    //cout<<endl<<"isnewitem: "<<isnewitem;
    if(sx==norm){
        ss>>vasarlo.time;
        ss>>vasarlo.id;


        while(ss >> tmp2)
        {
            //isarukod23 = false;
            //isnewitem = true;

            vasarlo.things.push_back(tmp2);
            //cout<< tmp2 << " ";
            if(tmp2 == "arukod23") isarukod23 = true;
/*
            for(int i=1; (i<vasarlo.things.size()) && (isnewitem == true); ++i)
            {
                if(vasarlo.things[i] == tmp2)
                    cout<<"vasarlo.things[i]: "<<vasarlo.things[i]<<"tmp2: "<<tmp2;
                    isnewitem = false;
            }
            if(isnewitem)
                c=c+1;
*/
        }

        for(int i=0; (i<vasarlo.things.size()); ++i)
            {
                for(int j=1; (j<i)&& (isnewitem == true); ++j)
                {
                    if(vasarlo.things[i] == vasarlo.things[j])
                        //cout<<"vasarlo.things[i]: "<<vasarlo.things[i]<<"tmp2: "<<tmp2;
                        isnewitem = false;
                }

                if(isnewitem)
                c=c+1;
            }

        if(isarukod23 == false) voltarukod23 = voltarukod23+1;
        //cout<<endl<<"isnewitem: "<<isnewitem<<" maxboughtitem: "<<maxboughtitem<<" c: "<<c<<endl;
        /* max */
        if(maxboughtitem<c)
        {
            MostOfItem.id = vasarlo.id;
            MostOfItem.time = vasarlo.time;
            MostOfItem.things = vasarlo.things;
            maxboughtitem = c;
        }

        /* min */
        if(isfirst)
        {
            isfirst = false;
            minboughtitem = c;
            LessOfItem.id = vasarlo.id;
            LessOfItem.time = vasarlo.time;
            LessOfItem.things = vasarlo.things;
        }else if(minboughtitem > c)
        {
            minboughtitem = c;
            LessOfItem.id = vasarlo.id;
            LessOfItem.time = vasarlo.time;
            LessOfItem.things = vasarlo.things;
        }

       /* cout<<endl<<"vasarlo.time : " <<vasarlo.time << endl;
        cout<<"vasarlo.id : " << vasarlo.id<<endl;
        cout<<"\n______________"<<endl;*/
    }
}

/*void enor::osszegez()
{
    //k�t �sszegz�s
    dx.sum=0;
    dx.jo=true;
    for(int i=0; i<(int)dx.v.size(); ++i)
    {
        int ar;
        if(dx.v[i].tipus=='G') ar=500;
        else if(dx.v[i].tipus=='D') ar=800;
        else ar=1000;
        dx.sum+=ar;
        dx.jo=dx.jo && dx.v[i].tipus=='D';
    }

}

vetites enor::current() const
{
    return dx;
}
*/
bool enor::end() const
{
    if(sx==abnorm)
    {
        cout<<endl<<voltarukod23<<" alkalmommal  nem szerepelt az 'arukod23'"<<endl;
        cout<<"A legtobbet "<<MostOfItem.id<< " vasarolta "<<MostOfItem.time<<"-kor "<< maxboughtitem << " darabot." << endl;
        cout<<"A legkevesebbet "<<LessOfItem.id<< " vasarolta "<<LessOfItem.time<<"-kor "<< minboughtitem << " darabot." << endl;
    }

    return sx==abnorm;
}
/*
std::ostream& operator<<(std::ostream& out, const vetites& z)
{
    for(int i=0; i<(int)z.id.size(); ++i)
    {
        out<<z.id[i]<<" ";
    }
    out<<z.ido<<" ";
    for(int i=0; i<(int)z.v.size(); ++i)
    {
        out<<z.v[i].hely<<" "<<z.v[i].tipus<<" ";
    }
    out<<"sum="<<z.sum<<" "<<z.jo<<endl;
    return out;
}
*/
