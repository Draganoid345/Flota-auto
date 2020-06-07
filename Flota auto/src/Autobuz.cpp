#include "Autobuz.h"

Autobuz::Autobuz(string id, string marca,
                       string serie,
                       int an,
                       data* itp,
                       int odometru,
                       int putere,
                       int nrLocuri,
                       data* dataProcurare,
                       string stare,
                       int volumBagaj,
                       string nrInmatriculare) : Autoturism(marca, serie, an, itp, odometru, putere, nrLocuri, dataProcurare, stare, nrInmatriculare)
{
    this->volumBagaj = volumBagaj;
    this->id = id;
}

void Autobuz::afisare_autobuz()
{
    cout << "ID: " << this->id << "\n";
    cout << "Tip A:\n";
    this->afisare_auto();
    cout << "\nVolumul bagajului: " << this->volumBagaj << "m3";
}

ostream& operator <<(ostream& out, const Autobuz& a)
{
    return a.afisare(out);
}

ostream& Autobuz::afisare(ostream& out) const
{
    out << "A;";
    out << this->marca <<   ";";
    out << this->serie << ";";
    out << this->an << ";";
    out << this->itp.zi << ";";
    out << this->itp.luna << ";";
    out << this->itp.an << ";";
    out << this->odometru << ";";
    out << this->putere << ";";
    out << this->nrLocuri << ";";
    out << this->dataProcurare.zi << ";";
    out << this->dataProcurare.luna << ";";
    out << this->dataProcurare.an << ";";
    out << this->stare << ";";
    out << this->volumBagaj << ";";
    out << this->nrInmatriculare << ";\n";

    return out;
}

Autobuz::~Autobuz()
{
    //dtor
}
