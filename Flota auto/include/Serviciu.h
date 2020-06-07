#ifndef SERVICIU_H
#define SERVICIU_H
#include "Autoturism.h"

class Serviciu : public Autoturism
{
    public:
        Serviciu(string id = "", string marca = "",
                string serie = "",
                int an = -1,
                data* itp = nullptr,
                int odometru = 0,
                int putere = 0,
                int nrLocuri = 0,
                data* dataProcurare = nullptr,
                string stare = "",
                string angajat = "",
                string nrInmatriculare = "");
        virtual ~Serviciu();
        friend ostream& operator << (ostream& out, const Serviciu& s);
        ostream& afisare(ostream&) const;
        void afisare_serviciu();
        string getID()
        {
            return this->id;
        };

    protected:
        string angajat;
        string id;
    private:
};

#endif // SERVICIU_H
