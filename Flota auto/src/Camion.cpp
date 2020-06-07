#include "Camion.h"

Camion::Camion(string id, string marca,
                       string serie,
                       int an,
                       data* itp,
                       int odometru,
                       int putere,
                       int nrLocuri,
                       data* dataProcurare,
                       string stare,
                       int volum,
                       string nrInmatriculare) : Autoturism(marca, serie, an, itp, odometru, putere, nrLocuri, dataProcurare, stare, nrInmatriculare)
{
    this->volum = volum;
    this->id = id;
}

void Camion::afisare_camion()
{
    cout << "ID: " << this->id << "\n";
    cout << "Tip C:\n";
    this->afisare_auto();
    cout << "\nCapacitate: " << this->volum << "t";
}
//supraincarcarea
ostream& operator <<(ostream& out, const Camion& c)
{
    return c.afisare(out);
}

//functia apelata de <<
ostream& Camion::afisare(ostream& out) const
{
    out << "C;";
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
    out << this->volum << ";";
    out << this->nrInmatriculare << ";\n";
    return out;
}

Camion::~Camion()
{
    //dtor
}
