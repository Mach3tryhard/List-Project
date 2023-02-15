#include <bits/stdc++.h>

using namespace std;

struct Catalog{
    string nume,prenume;
    int nrom,nmate,ninfo;
    Catalog * urm;
};

int n;

///1/6
void creare(Catalog*& f)
{
    string a1,b1;
    int a,b,c;
    Catalog* p = new Catalog;
    cin>>a1>>b1>>a>>b>>c;
    p->nume=a1;p->prenume=b1;p->nrom=a;p->nmate=b;p->ninfo=c;
    f = p;
    for (int i = 0; i < n-1; i++)
    {
        cin>>a1>>b1>>a>>b>>c;
        Catalog* n = new Catalog;
        n->nume= a1;n->prenume=b1;n->nrom=a;n->nmate=b;n->ninfo=c;
        p->urm = n;
        p = n;
    }
    p->urm = NULL;
}

///2/6
void afisare(Catalog* n)
{
    cout<<'\n';
    while(n!=NULL)
    {
        cout<<n->nume<<' '<<n->prenume<<' '<<n->nrom<<' '<<n->nmate<<' '<<n->ninfo<<'\n';
        n=n->urm;
    }
    cout<<'\n';
}

///3/6
void verificare(Catalog * prim)
{
    int x;
    cin>>x;
    while(prim!=NULL && prim->urm!=NULL)
    {
        if(prim->ninfo==x || prim->nrom==x || prim->nmate==x)
        {
            cout<<prim->nume<<' '<<prim->prenume<<" are nota "<<x<<" in catalog."<<'\n';
        }
        prim=prim->urm;
    }
    if(prim->ninfo==x || prim->nrom==x || prim->nmate==x)
    {
        cout<<prim->nume<<' '<<prim->prenume<<" are nota "<<x<<" in catalog."<<'\n';
    }
}

///4/6
void adaugare(Catalog *& prim)
{
    string a1,b1;
    int a,b,c;
    cin>>a1>>b1>>a>>b>>c;
    Catalog *x=new Catalog;
    x->nume=a1;
    x->prenume=b1;
    x->nrom=a;
    x->nmate=b;
    x->ninfo=c;
    x->urm=NULL;
    if(prim==NULL)
    {
        prim=x;
    }
    else
    {
        Catalog *y=prim;
        while(y->urm!=NULL)
            y=y->urm;
        y->urm=x;
    }
}

///5/6
void stergere(Catalog *& prim)
{
    int poz;
    cin>>poz;
    if(poz==1)
    {
        ///pozitia 1
        Catalog *aux=prim;
        prim=prim->urm;
        delete aux;
    }
    else
    {
        Catalog* p=new Catalog;
        p=prim;
        int i=1;
        while(p!=NULL && p->urm!=NULL && poz>i+1)
        {
            p=p->urm;
            i++;
        }
        ///caz cand este ultimul element
        if(p->urm->urm==NULL)
        {
            Catalog* aux=p->urm;
            delete aux;
            p->urm=NULL;
        }
        ///caz cand este element random
        else
        {
            Catalog* aux=p->urm;
            delete aux;
            p->urm=p->urm->urm;
        }
    }
}

///6/6
void inserare(Catalog*& prim)
{
    string a1, b1, x, y;
    int a, b, c;
    Catalog* n = new Catalog;
    Catalog* p = prim;
    cin >> a1 >> b1 >> a >> b >> c;  
    n->nume = a1;n->prenume = b1;n->nrom = a;n->nmate = b;n->ninfo = c;
    x = n->nume;
    n->urm = NULL;
    bool d = false;
    while (p->urm != NULL && d==false)
    {
        y = p->urm->nume;
        if (x<y)
        {
            if (p->urm != NULL)
            {
                n->urm = p->urm;
                p->urm = n;
            }
            d = true;
        }
        p = p->urm;
    }
}

int main()
{
    bool endapp=false;
    Catalog* lista=new Catalog;
    cout<<"Introduceti numarul de elevi pusi in catalog:"<<'\n';
    cin>>n;
    cout<<"Introduceti datele elevilor in forma:Nume,Prenume,nota romana,nota matematica,nota informatica:"<<'\n';
    creare(lista);
    cout<<"Folositi help pentru o lista cu comenzi!"<<'\n';
    string reading;
    while(endapp==false)
    {
        cin>>reading;
        if(reading=="help")
        {
            cout<<"Pentru afisarea catalogului folositi -> afisare"<<'\n'<<"Pentru verificarea elevilor cu o anumita nota folositi -> verificare"<<'\n';
            cout<<"Pentru adaugarea la finalul catalogului folositi -> adaugare"<<'\n'<<"Pentru stergerea unei anumite pozitii folositi -> stergere"<<'\n';
            cout<<"Pentru inserare in catalog in mod alfabetic folositi -> inserare"<<'\n'<<"Pentru terminarea programului folositi -> iesi"<<'\n';
        }
        if(reading=="afisare")
        {
            afisare(lista);
        }
        if(reading=="verificare")
        {
            cout<<"Introduceti nota care trebuie verificata:";
            verificare(lista);
        }
        if(reading=="adaugare")
        {
            cout<<"Introduceti datele unui elev nou:";
            adaugare(lista);
        }
        if(reading=="stergere")
        {
            cout<<"Introduceti pozitia care trebuie stearsa:";
            stergere(lista);
        }
        if(reading=="inserare")
        {
            cout<<"Introduceti datele unui elev nou:";
            inserare(lista);
        }
        if(reading=="iesi")
        {
            endapp=true;
        }
    }
    return 0;
}
