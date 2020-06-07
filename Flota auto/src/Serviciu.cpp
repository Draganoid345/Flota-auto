#include "Serviciu.h"

Serviciu::Serviciu(string id, string marca,
                       string serie,
                       int an,
                       data* itp,
                       int odometru,
                       int putere,
                       int nrLocuri,
                       data* dataProcurare,
                       string stare,
                       string angajat,
                       string nrInmatriculare) : Autoturism(marca, serie, an, itp, odometru, putere, nrLocuri, dataProcurare, stare, nrInmatriculare)
{
    this->angajat = angajat;
    this->id = id;
}

//afisarea
void Serviciu::afisare_serviciu()
{
    cout << "ID: " << this->id << "\n";
    cout << "Tip: S;\n";
    this->afisare_auto();
    cout << "\nAngajat: " << this->angajat << ";";
}

//suppraincarcarea operatorului << pentru a fi folosit la scrierea in fiser
ostream& operator <<(ostream& out, const Serviciu& s)
{
    return s.afisare(out);
}

//insasi functia apelata de operatorul <<
ostream& Serviciu::afisare(ostream& out) const
{
    out << "S;";
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
    out << this->angajat << ";";
    out << this->nrInmatriculare << ";\n";
    return out;
}

Serviciu::~Serviciu()
{
    //dtor
}
