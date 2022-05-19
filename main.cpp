#include <fstream>

using namespace std;

ifstream in("caca.in");
ofstream out("caca.out");

struct nod{
    int info;
    nod * urm;
};

int numarare(nod * p)
{
    int mare=1;
    int rez=0;
    nod * p1 = p;
    nod * up;

    while(p1->urm!=NULL)
    {
        up=p1;
        p1=p1 -> urm;
        int a,b;
        a=up->info;
        b=p1->info;
        if(up->info == p1->info && p1!=up)
        {
            mare++;
        }
        else
        {
            if(mare>rez)
            {
                rez=mare;
                mare=1;
            }
        }
    }
    if(mare>rez)
    {
        rez=mare;
        mare=1;
    }
    return rez;
}

int main()
{
    nod * prim = NULL;
    int x;
    while(in)
    {
        in>>x;
        nod * q = new nod;
        q -> info = x;
        q -> urm = NULL;
        if(prim == NULL)
        {
            prim = q;
        }
        else
        {

            nod * t = prim;
            while(t -> urm != NULL)
            {
                t = t -> urm;
            }
            t -> urm = q;
        }
    }
    out<<numarare(prim);
    /*nod *t=prim;
    while(t->urm!=NULL)
    {
        out<<t->info<<" ";
        t=t->urm;
    }*/
    return 0;
}
