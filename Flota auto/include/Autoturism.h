#ifndef AUTOTURISM_H
#define AUTOTURISM_H
#include <bits/stdc++.h>
using namespace std;


struct data //structura pentru a salva data la itp si data procurarii
{
    int zi;
    int luna;
    int an;
};

class Autoturism
{
    public:
        Autoturism(string marca = "",
                   string serie = "",
                   int an = -1,
                   data* itp = nullptr,
                   int odometru = 0,
                   int putere = 0,
                   int nrLocuri = 0,
                   data* dataProcurare = nullptr,
                   string stare = "",
                   string nrInmatriculare = "");
        void afisare_auto();
        friend ostream& operator <<(ostream& out, const Autoturism& a);
        virtual ostream& afisare(ostream& out) const;
        data getData();
        int getAn();
        int getStare();
        int getLocuri();
        virtual ~Autoturism();

    protected:
        int an;                 //anul masinii
        data dataProcurare;     //data in care firma a procurat masina
        data itp;               //Inspectia Tehnica Periodica
        string marca;           //marca masinii
        string serie;           //seria masinii
        int odometru;           //distanta parcursa de masina (km)
        int putere;             //puterea motorului (cai putere)
        string stare;           //starea actuala a masinii
        int nrLocuri;           //numarul de locuri;
        string nrInmatriculare;  //numar inmatriculare

    private:
};

#endif // AUTOTURISM_H
