#include <fstream>

using namespace std;

ifstream in("caca.in");
ofstream out("caca.out");

struct Nod
{
    int info;
    Nod *leg;
};

void FInserareKX(Nod * &head, int k, int x)
{
    if(head==NULL)
    {

    }
    if(k<=1)
    {
        Nod * t = new Nod;
        t->info=x;
        t->leg=head;
        head=t;
        return;
    }
    int nr=2;
    Nod * p1 = head;
    while(p1->leg!=NULL)
    {
        if(k==nr)
        {
            Nod * t = new  Nod;
            t->info = x;
            t->leg=p1->leg;
            p1->leg=t;
            p1=p1 -> leg;
        }
        p1=p1 -> leg;
        nr++;
    }
    if(nr<=k)
    {
        k=nr-1;
        nr=2;
        Nod * p1 = head;
        while(p1->leg!=NULL)
        {
            if(k==nr)
            {
                Nod * t = new  Nod;
                t->info = x;
                t->leg=p1->leg;
                p1->leg=t;
                p1=p1 -> leg;
            }
            p1=p1 -> leg;
            nr++;
        }
    }
}

void FAdaugaInainte(Nod * &head)
{
    Nod * p1 = head;
    if(p1->info%2==1)
    {
        Nod * t = new Nod;
        t -> info = p1->info*2;
        t -> leg = head;
        head = t;
    }
    while(p1->leg!=NULL)
    {
        int a=p1->leg->info;
        if((p1->leg)->info%2==1)
        {
            Nod * t = new  Nod;
            t->info = p1->leg->info*2;
            t->leg=p1->leg;
            p1->leg=t;
            p1=p1 -> leg;
        }
        p1=p1 -> leg;
    }
}

int main()
{
    Nod * prim = NULL;
    int x,k,nr;
    in>>k>>x;
    while(in)
    {
        in>>nr;
        Nod * q = new Nod;
        q -> info = nr;
        q -> leg = NULL;
        if(prim == NULL)
        {
            prim = q;
        }
        else
        {

            Nod * t = prim;
            while(t -> leg != NULL)
            {
                t = t -> leg;
            }
            t -> leg = q;
        }
    }
    FInserareKX(prim,k,x);
    Nod *t=prim;
    while(t->leg!=NULL)
    {
        out<<t->info<<" ";
        t=t->leg;
    }
    return 0;
}
