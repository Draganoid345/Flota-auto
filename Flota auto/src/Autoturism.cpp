#include "Autoturism.h"

//constructor
Autoturism::Autoturism(string marca,
                       string serie,
                       int an,
                       data* itp,
                       int odometru,
                       int putere,
                       int nrLocuri,
                       data* dataProcurare,
                       string stare,
                       string nrInmatriculare)
{
    this->marca = marca;
    this->serie = serie;
    this->an = an;
    this->itp.zi = itp->zi;
    this->itp.luna = itp->luna;
    this->itp.an = itp->an;
    this->odometru = odometru;
    this->putere = putere;
    this->nrLocuri = nrLocuri;
    this->dataProcurare.zi = dataProcurare->zi;
    this->dataProcurare.luna = dataProcurare->luna;
    this->dataProcurare.an = dataProcurare->an;
    this->stare = stare;
    this->nrInmatriculare = nrInmatriculare;
}

//afisare
void Autoturism::afisare_auto()
{
    cout << "Marca: ";
    cout << this->marca;
    cout << ";\nSeria: ";
    cout << this->serie;
    cout << ";\nAn: " << this->an;
    cout << ";\nNumar inmatriculare: " << this->nrInmatriculare;
    cout << ";\nITP: ";
    cout << setw(2) << this->itp.zi << "/" << setw(2) << this->itp.luna << "/" << setw(4) << this->itp.an;
    cout << ";\nOdometru: ";
    cout << this->odometru;
    cout << "km;\nPutere: ";
    cout << this->putere << "CP";
    cout << ";\nData procurare: ";
    cout << setw(2) << this->dataProcurare.zi << "/" << setw(2) << this->dataProcurare.luna << "/" << setw(4) << this->dataProcurare.an;
    cout << ";\nStare: ";
    cout << this->stare << ";";
}

//functie dummy pentru a fi folosita de clasele derivate
ostream& operator << (ostream& out, const Autoturism& a)
{
    return a.afisare(out);
}

//functie dummy
ostream& Autoturism::afisare(ostream& out) const
{
    out << "Afisare din autoturism\n";
    return out;
}

//returneaza data itp
data Autoturism::getData()
{
    return this->itp;
}

//returneaza anul in care a fost produsa masina
int Autoturism::getAn()
{
    return this->an;
}

int Autoturism::getLocuri()
{
    return this->nrLocuri;
}


//returneaza un numar corespunzator starii
int Autoturism::getStare()
{
    if(this->stare == "depozit")
        return 0;
    if(this->stare == "reparatie")
        return 1;
    if(this->stare == "serviciu")
        return 2;
    return -1;
}

Autoturism::~Autoturism()
{
    //dtor
}
