#include <fstream>

using namespace std;

ifstream in("caca.in");
ofstream out("caca.out");

struct nod{
    int info;
    nod * urm;
};

void stergePrimul(nod * & p)
{
    nod * t = p;
    p = p->urm;
    delete t;
}

int numarare(nod * p)
{
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
        if(up->info == p1->info )
        {
            rez++;
        }
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
    stergePrimul(prim);
    /// afisare lista
    nod *t=prim;
    while(t->urm!=NULL)
    {
        out<<t->info<<" ";
        t=t->urm;
    }
    return 0;
}
