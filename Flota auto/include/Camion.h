#ifndef CAMION_H
#define CAMION_H
#include "Autoturism.h"

class Camion : public Autoturism
{
    public:
        Camion(string id = "", string marca = "",
                string serie = "",
                int an = -1,
                data* itp = nullptr,
                int odometru = 0,
                int putere = 0,
                int nrLocuri = 0,
                data* dataProcurare = nullptr,
                string stare = "",
                int volum = 0,
                string nrInmatriculare = "");
        virtual ~Camion();
        void afisare_camion();
        string getID()
        {
            return this->id;
        };
        friend ostream& operator << (ostream& out, const Camion& c);
        ostream& afisare(ostream&) const;

    protected:
        int volum;
        string id;

    private:
};

#endif // CAMION_H
