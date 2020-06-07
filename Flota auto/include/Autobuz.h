#ifndef AUTOBUZ_H
#define AUTOBUZ_H
#include "Autoturism.h"


class Autobuz : public Autoturism
{
    public:
        Autobuz(string id = "", string marca = "",
                string serie = "",
                int an = -1,
                data* itp = nullptr,
                int odometru = 0,
                int putere = 0,
                int nrLocuri = 0,
                data* dataProcurare = nullptr,
                string stare = "",
                int volumBagaj = 0,
                string nrInmatriculare = "");
        virtual ~Autobuz();
        void afisare_autobuz();
        string getID()
        {
            return this->id;
        };
        friend ostream& operator << (ostream& out, const Autobuz& a);
        ostream& afisare(ostream&) const;

    protected:
        int volumBagaj;
        string id;

    private:
};

#endif // AUTOBUZ_H
