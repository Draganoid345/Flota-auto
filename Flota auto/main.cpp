#include <bits/stdc++.h>
#include "Autoturism.h"
#include "Camion.h"
#include "Serviciu.h"
#include "Autobuz.h"

using namespace std;

//vectori globali in care pastram obiectele
vector<Serviciu> S;
vector<Autobuz> A;
vector<Camion> C;

//niste contori cu ajutorul carora formam ID-uri
int idA = 0, idS = 0, idC = 0;

//numarul de zile corespunzator lunii
const int zile[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


//functie care numara numarul de ani bisecti pana la data d
int anBisect(data d)
{
    int ani = d.an;
    if(d.luna <= 2)
        ani--;

    return ani / 4 - ani / 100 + ani / 400;
}

//functie care calculeaza numarul de zile dintre doua dati
int durata(data d1, data d2)
{
    int n1 = d1.an*365 + d1.zi;

    for(int i = 0; i < d1.luna - 1; i++)
        n1 += zile[i];
    n1 += anBisect(d1);

    int n2 = d2.an*365 + d2.zi;

    for(int i = 0; i < d2.luna - 1; i++)
        n2 += zile[i];
    n2 += anBisect(d2);

    return (n2 - n1);
}


//incarcarea datelor din fisier in cei 3 vectori
void upload()
{
    //deschidem fisierul cu ifstream
    ifstream fin;
    fin.open("flota.txt");

    int entries; //numarul de obiecte;
    fin >> entries;
    fin.ignore();

    for(int i = 0; i < entries; i++)
    {
        string line;        //linia citita
        getline(fin, line);


        //stringstream pentru a divide segmentele;
        stringstream ss_citire(line);
        string token;

        vector<string> tokens; // vector in care pastram fiecare segment / token

        while(getline(ss_citire, token, ';')) //split dupa ;
        {
            tokens.push_back(token);
//            cout << token << "\n";
        }

        if(tokens[0] == "S") //daca tipul este masina de Serviciu
        {
            idS++;
            string id = "S" + to_string(idS); //cream un id

            // variabila in care pastram data itp
            data data_itp;
            data_itp.zi = stoi(tokens[4]);
            data_itp.luna = stoi(tokens[5]);
            data_itp.an = stoi(tokens[6]);

            // pastram data procurarii
            data data_procurare;
            data_procurare.zi = stoi(tokens[10]);
            data_procurare.luna = stoi(tokens[11]);
            data_procurare.an = stoi(tokens[12]);

            // inseram obiectul in tabloul respectiv
            S.push_back(Serviciu(id, tokens[1],
                                       tokens[2],
                                       stoi(tokens[3]),
                                       &data_itp,
                                       stoi(tokens[7]),
                                       stoi(tokens[8]),
                                       stoi(tokens[9]),
                                       &data_procurare,
                                       tokens[13],
                                       tokens[14],
                                       tokens[15]));

        }

        if(tokens[0] == "C") // daca tipul este Camion
        {
            idC++;
            string id = "C" + to_string(idC);

            data data_itp;
            data_itp.zi = stoi(tokens[4]);
            data_itp.luna = stoi(tokens[5]);
            data_itp.an = stoi(tokens[6]);

            data data_procurare;
            data_procurare.zi = stoi(tokens[10]);
            data_procurare.luna = stoi(tokens[11]);
            data_procurare.an = stoi(tokens[12]);


            C.push_back(Camion(id, tokens[1],
                                       tokens[2],
                                       stoi(tokens[3]),
                                       &data_itp,
                                       stoi(tokens[7]),
                                       stoi(tokens[8]),
                                       stoi(tokens[9]),
                                       &data_procurare,
                                       tokens[13],
                                       stoi(tokens[14]),
                                       tokens[15]));
        }

        if(tokens[0] == "A") // daca tipul este Autobuz
        {
            idA++;
            string id = "A" + to_string(idA);

            data data_itp;
            data_itp.zi = stoi(tokens[4]);
            data_itp.luna = stoi(tokens[5]);
            data_itp.an = stoi(tokens[6]);

            data data_procurare;
            data_procurare.zi = stoi(tokens[10]);
            data_procurare.luna = stoi(tokens[11]);
            data_procurare.an = stoi(tokens[12]);



            A.push_back(Autobuz(id, tokens[1],
                                       tokens[2],
                                       stoi(tokens[3]),
                                       &data_itp,
                                       stoi(tokens[7]),
                                       stoi(tokens[8]),
                                       stoi(tokens[9]),
                                       &data_procurare,
                                       tokens[13],
                                       stoi(tokens[14]),
                                       tokens[15]));
        }

    }
    fin.close(); // inchidem fisierul

}

void afisareA() // afisarea autobuzelor
{
    cout << "=========================================================================\n";
    if(A.size() == 0)
        cout << "Nu sunt autobuze in flota\n";
    else
    {
        for(auto i = A.begin(); i != A.end(); i++)
        {
            i->afisare_autobuz();
            cout << "\n";
            cout << "-------------------------------------------------------------------------\n";
        }
    }
}

void afisareC() // afisare camioanelor
{
    cout << "=========================================================================\n";
    if(C.size() == 0)
        cout << "Nu sunt camioane in flota\n";
    else
    {
        for(auto i = C.begin(); i != C.end(); i++)
        {
            i->afisare_camion();
            cout << "\n";
            cout << "-------------------------------------------------------------------------\n";
        }
    }
}

void afisareS() // afisarea masinilor de serviciu
{
    cout << "=========================================================================\n";
    if(S.size() == 0)
        cout << "Nu sunt masini de serviciu in flota\n";
    else
    {
        for(auto i = S.begin(); i != S.end(); i++)
        {
            i->afisare_serviciu();
            cout << "\n";
            cout << "-------------------------------------------------------------------------\n";
        }
    }
}

void afisareID()
{
    string id;
    cout << "Introduceti ID-ul:\n";
    cin >> id;

    if(id[0] == 'A')
    {
        bool nu_am_gasit = true;
        for(auto i = A.begin(); i != A.end(); i++)
            if(i->getID() == id)
            {
                i->afisare_autobuz();
                cout << "\n";
                nu_am_gasit = false;
            }
        if(nu_am_gasit)
            cout << "Nu este autoturism cu asa ID!\n";
    }

    if(id[0] == 'S')
    {
        bool nu_am_gasit = true;
        for(auto i = S.begin(); i != S.end(); i++)
            if(i->getID() == id)
            {
                i->afisare_serviciu();
                cout << "\n";
                nu_am_gasit = false;
            }
        if(nu_am_gasit)
            cout << "Nu este autoturism cu asa ID!\n";
    }

    if(id[0] == 'C')
    {
        bool nu_am_gasit = true;
        for(auto i = C.begin(); i != C.end(); i++)
            if(i->getID() == id)
            {
                i->afisare_camion();
                cout << "\n";
                nu_am_gasit = false;
            }
        if(nu_am_gasit)
            cout << "Nu este autoturism cu asa ID!\n";
    }
}

void afisare() //afisarea tuturor autoturismelor
{
    afisareS();
    afisareA();
    afisareC();
}

void adaugaS() // adaugare masina de serviciu
{
    int an;                 //anul masinii
    data dataProcurare;     //data in care firma a procurat masina
    data itp;               //Inspectia Tehnica Periodica
    string marca;           //marca masinii
    string serie;           //seria masinii
    int odometru;           //distanta parcursa de masina (km)
    int putere;             //puterea motorului (cai putere)
    string stare;         //locatia actuala a masinii
    int nrLocuri;           //numarul de locuri;
    string angajat;
    string nrInmatriculare;
    cout << "Marca:\n";
    cin.ignore();
    getline(cin, marca);
    cout << "Serie:\n";
    getline(cin, serie);
    cout << "An:\n";
    cin >> an;
    cout << "ITP\n";
    cout << "Zi:\n";
    cin >> itp.zi;
    if(itp.zi > 31 || itp.zi < 1)
    {
        cout << "Zi invalida!\n";
        return;
    }
    cout << "Luna:\n";
    cin >> itp.luna;
    if(itp.luna < 1 || itp.luna > 12)
    {
        cout << "Luna invalida!\n";
        return;
    }
    cout << "An:\n";
    cin >> itp.an;
    cout << "Numar inmatriculare (B123VUM):\n";
    cin >> nrInmatriculare;
    cout << "Odometru (numar intreg)\n";
    cin >> odometru;
    cout << "Putere (numar intreg):\n";
    cin >> putere;
    cout << "Numar de locuri:\n";
    cin >> nrLocuri;
    cout << "Data procurarii:\n";
    cout << "Zi:\n";
    cin >> dataProcurare.zi;
    if(dataProcurare.zi > 31 || dataProcurare.zi < 1)
    {
        cout << "Zi invalida!\n";
        return;
    }
    cout << "Luna:\n";
    cin >> dataProcurare.luna;
    if(dataProcurare.luna < 1 || dataProcurare.luna > 12)
    {
        cout << "Luna invalida!\n";
        return;
    }
    cout << "An:\n";
    cin >> dataProcurare.an;
    cout << "Stare (depozit / reparatie / serviciu):\n";
    cin >> stare;
    cout << "Angajatul responsabil:\n";
    cin.ignore();
    getline(cin, angajat);

    idS++;
    string id = "S" + to_string(idS);
    S.push_back(Serviciu(id, marca, serie, an, &itp, odometru, putere, nrLocuri, &dataProcurare, stare, angajat, nrInmatriculare));
}

void adaugaA() // adaugare autobuz
{
    int an;                 //anul masinii
    data dataProcurare;     //data in care firma a procurat masina
    data itp;               //Inspectia Tehnica Periodica
    string marca;           //marca masinii
    string serie;           //seria masinii
    int odometru;           //distanta parcursa de masina (km)
    int putere;             //puterea motorului (cai putere)
    string stare;         //locatia actuala a masinii
    int nrLocuri;           //numarul de locuri;
    int volumBagaj;
    string nrInmatriculare;
    cout << "Marca:\n";
    cin.ignore();
    getline(cin, marca);
    cout << "Serie:\n";
    getline(cin, serie);
    cout << "An:\n";
    cin >> an;
    cout << "ITP\n";
    cout << "Zi:\n";
    cin >> itp.zi;
    if(itp.zi > 31 || itp.zi < 1)
    {
        cout << "Zi invalida!\n";
        return;
    }
    cout << "Luna:\n";
    cin >> itp.luna;
    if(itp.luna < 1 || itp.luna > 12)
    {
        cout << "Luna invalida!\n";
        return;
    }
    cout << "An:\n";
    cin >> itp.an;
    cout << "Numar inmatriculare (B123VUM):\n";
    cin >> nrInmatriculare;
    cout << "Odometru (numar intreg)\n";
    cin >> odometru;
    cout << "Putere (numar intreg):\n";
    cin >> putere;
    cout << "Numar de locuri:\n";
    cin >> nrLocuri;
    cout << "Data procurarii:\n";
    cout << "Zi:\n";
    cin >> dataProcurare.zi;
    if(dataProcurare.zi > 31 || dataProcurare.zi < 1)
    {
        cout << "Zi invalida!\n";
        return;
    }
    cout << "Luna:\n";
    cin >> dataProcurare.luna;
    if(dataProcurare.luna < 1 || dataProcurare.luna > 12)
    {
        cout << "Luna invalida!\n";
        return;
    }
    cout << "An:\n";
    cin >> dataProcurare.an;
    cout << "Stare (depozit / reparatie / serviciu):\n";
    cin >> stare;
    cout << "Volumul portbagajului (numar intreg):\n";
    cin >> volumBagaj;

    idA++;
    string id = "A" + to_string(idA);

    A.push_back(Autobuz(id, marca, serie, an, &itp, odometru, putere, nrLocuri, &dataProcurare, stare, volumBagaj, nrInmatriculare));
}

void adaugaC() // adaugare camion
{
    int an;                 //anul masinii
    data dataProcurare;     //data in care firma a procurat masina
    data itp;               //Inspectia Tehnica Periodica
    string marca;           //marca masinii
    string serie;           //seria masinii
    int odometru;           //distanta parcursa de masina (km)
    int putere;             //puterea motorului (cai putere)
    string stare;         //locatia actuala a masinii
    int nrLocuri;           //numarul de locuri;
    int volum;
    string nrInmatriculare;
    cout << "Marca:\n";
    cin.ignore();
    getline(cin, marca);
    cout << "Serie:\n";
    getline(cin, serie);
    cout << "An:\n";
    cin >> an;
    cout << "ITP\n";
    cout << "Zi:\n";
    cin >> itp.zi;
    if(itp.zi > 31 || itp.zi < 1)
    {
        cout << "Zi invalida!\n";
        return;
    }
    cout << "Luna:\n";
    cin >> itp.luna;
    if(itp.luna < 1 || itp.luna > 12)
    {
        cout << "Luna invalida!\n";
        return;
    }
    cout << "An:\n";
    cin >> itp.an;
    cout << "Numar inmatriculare (B123VUM):\n";
    cin >> nrInmatriculare;
    cout << "Odometru (numar intreg)\n";
    cin >> odometru;
    cout << "Putere (numar intreg):\n";
    cin >> putere;
    cout << "Numar de locuri:\n";
    cin >> nrLocuri;
    cout << "Data procurarii:\n";
    cout << "Zi:\n";
    cin >> dataProcurare.zi;
    if(dataProcurare.zi > 31 || dataProcurare.zi < 1)
    {
        cout << "Zi invalida!\n";
        return;
    }
    cout << "Luna:\n";
    cin >> dataProcurare.luna;
    if(dataProcurare.luna < 1 || dataProcurare.luna > 12)
    {
        cout << "Luna invalida!\n";
        return;
    }
    cout << "An:\n";
    cin >> dataProcurare.an;
    cout << "Stare (depozit / reparatie / serviciu):\n";
    cin >> stare;
    cout << "Capacitate, tone (numar intreg):\n";
    cin >> volum;

    idC++;
    string id = "C" + to_string(idC);

    C.push_back(Camion(id, marca, serie, an, &itp, odometru, putere, nrLocuri, &dataProcurare, stare, volum, nrInmatriculare));
}

void adauga() // adaugarea unei masini
{
    string tip;
    cout << "=========================================================================\n";
    cout << "Tipul autoturismului:\n";
    cout << "S : masina de serviciu\n";
    cout << "A : autobuz\n";
    cout << "C : camion\n";
    cout << "=========================================================================\n";
    cin >> tip;
    if(tip == "S") adaugaS();
    else if(tip == "A") adaugaA();
    else if(tip == "C") adaugaC();
    else cout << "Tip invalid\n";
}

// sterge o masina de serviciu
void stergeS(string id)
{
    for(auto m = S.begin(); m != S.end(); m++)
    {
        if(m->getID() == id)
        {
            S.erase(S.begin() + distance(S.begin(), m));
            return;
        }
    }
    cout << "Nu exista masina de serviciu cu asa ID\n";
}

//sterge un autobuz
void stergeA(string id)
{
    for(auto m = A.begin(); m != A.end(); m++)
    {
        if(m->getID() == id)
        {
            A.erase(A.begin() + distance(A.begin(), m));
            return;
        }
    }
    cout << "Nu exista autobuz cu asa ID\n";
}

//sterge un camion
void stergeC(string id)
{
    for(auto m = C.begin(); m != C.end(); m++)
    {
        if(m->getID() == id)
        {
            C.erase(C.begin() + distance(C.begin(), m));
            return;
        }
    }
    cout << "Nu exista camion cu asa ID\n";
}


void sterge() // stergerea unei masini din flota
{
    string id;
    cout << "ID-ul autoturismului ce doriti sa il eliminati:\n";
    cin >> id;
    if(id[0] == 'S') stergeS(id);
    else if(id[0] == 'A') stergeA(id);
    else if(id[0] == 'C') stergeC(id);
    else cout << "ID invalid\n";
}

void expira() //afisarea masinilor cu ITP care expira in luna curenta
{
    int zile_expira = 730;
    data azi;
    azi.an = 2020;
    azi.luna = 6;
    azi.zi = 5;
    bool flag = true; // daca nu sunt masini de afisat, spunem asta
    //afisam pe rand masinile de fiecare tip
    for(auto i = S.begin(); i != S.end(); i++)
    {
        if(zile_expira < durata(i->getData(), azi))
        {
            flag = false;
            i->afisare_serviciu();
            cout << "\n";
            cout << "-------------------------------------------------------------------------\n";
        }
    }

    for(auto i = A.begin(); i != A.end(); i++)
    {
        if(zile_expira < durata(i->getData(), azi))
        {
            flag = false;
            i->afisare_autobuz();
            cout << "\n";
            cout << "-------------------------------------------------------------------------\n";
        }
    }

    for(auto i = C.begin(); i != C.end(); i++)
    {
        if(zile_expira < durata(i->getData(), azi))
        {
            flag = false;
            i->afisare_camion();
            cout << "\n";
            cout << "-------------------------------------------------------------------------\n";
        }
    }

    if(flag)
        cout << "Nu sunt masini cu ITP expirat.\n";

}

void vechime() // statistica vechimii tuturor autoturismelor
{
    map<int, int> anul_numar;
    for(Serviciu s : S)
    {
        if(anul_numar.find(s.getAn()) == anul_numar.end())
        {
            anul_numar[s.getAn()] = 1;
        }
        else
        {
            anul_numar[s.getAn()]++;
        }
    }

    for(Autobuz a : A)
    {
        if(anul_numar.find(a.getAn()) == anul_numar.end())
        {
            anul_numar[a.getAn()] = 1;
        }
        else
        {
            anul_numar[a.getAn()]++;
        }
    }

    for(Camion c : C)
    {
        if(anul_numar.find(c.getAn()) == anul_numar.end())
        {
            anul_numar[c.getAn()] = 1;
        }
        else
        {
            anul_numar[c.getAn()]++;
        }
    }

    cout << "Numarul autoturismelor dupa an:\n";
    for(auto i = anul_numar.begin(); i != anul_numar.end(); i++)
    {
        cout << i->first << " : " << i->second << "\n";
    }

}

//vechimea masinilor de serviciu
void vechimeS()
{
    map<int, int> anul_numar;
    for(Serviciu s : S)
    {
        if(anul_numar.find(s.getAn()) == anul_numar.end())
        {
            anul_numar[s.getAn()] = 1;
        }
        else
        {
            anul_numar[s.getAn()]++;
        }
    }

    cout << "Numarul masinilor de serviciu dupa an:\n";
    for(auto i = anul_numar.begin(); i != anul_numar.end(); i++)
    {
        cout << i->first << " : " << i->second << "\n";
    }
}

//vechimea autobuzelor
void vechimeA()
{
    map<int, int> anul_numar;
    for(Autobuz a : A)
    {
        if(anul_numar.find(a.getAn()) == anul_numar.end())
        {
            anul_numar[a.getAn()] = 1;
        }
        else
        {
            anul_numar[a.getAn()]++;
        }
    }

    cout << "Numarul autobuzelor dupa an:\n";
    for(auto i = anul_numar.begin(); i != anul_numar.end(); i++)
    {
        cout << i->first << " : " << i->second << "\n";
    }
}

//vechimea camioanelor
void vechimeC()
{
    map<int, int> anul_numar;
    for(Camion c : C)
    {
        if(anul_numar.find(c.getAn()) == anul_numar.end())
        {
            anul_numar[c.getAn()] = 1;
        }
        else
        {
            anul_numar[c.getAn()]++;
        }
    }

    cout << "Numarul camioanelor dupa an:\n";
    for(auto i = anul_numar.begin(); i != anul_numar.end(); i++)
    {
        cout << i->first << " : " << i->second << "\n";
    }
}

//starea autoturismelor
void stare()
{
    map<int, int> stare_numar;
    for(Serviciu s : S)
    {
        if(stare_numar.find(s.getStare()) == stare_numar.end())
            stare_numar[s.getStare()] = 1;
        else
            stare_numar[s.getStare()]++;
    }
    for(Autobuz a : A)
    {
        if(stare_numar.find(a.getStare()) == stare_numar.end())
            stare_numar[a.getStare()] = 1;
        else
            stare_numar[a.getStare()]++;
    }
    for(Camion c : C)
    {
        if(stare_numar.find(c.getStare()) == stare_numar.end())
            stare_numar[c.getStare()] = 1;
        else
            stare_numar[c.getStare()]++;
    }

    cout << "Statistica starii autoturismelor\n";
    for(auto i = stare_numar.begin(); i != stare_numar.end(); i++)
    {
        if(i->first == 0) cout << "Depozit : ";
        else if(i->first == 1) cout << "Reparatie : ";
        else if(i->first == 2) cout << "Serviciu : ";
        else cout << "Stare invalida : ";
        cout << i->second << "\n";
    }

}

void autobuze()
{
    map<int, int> locuri_numar;
    for(Autobuz a : A)
    {
        if(locuri_numar.find(a.getLocuri()) == locuri_numar.end())
            locuri_numar[a.getLocuri()] = 1;
        else
            locuri_numar[a.getLocuri()]++;
    }

    cout << "Statistica autobuzelor dupa numarul de locuri:\n";
    for(auto i = locuri_numar.begin(); i != locuri_numar.end(); i++)
    {
        cout << i->first << " locuri : " << i->second << "\n";
    }
}

void statistica() // functia principala a statisticilor
{
    string stat = "";
    cout << "=========================================================================\n";
    cout << "Tipul statisticii:\n";
    cout << "vechime  : afiseaza anul si cate autoturisme sunt din acel an\n";
    cout << "vechimeS : afiseaza anul si cate masini de serviciu sunt din acel an\n";
    cout << "vechimeA : afiseaza anul si cate autobuze sunt din acel an\n";
    cout << "vechimeC : afiseaza anul si cate camioane sunt din acel an\n";
    cout << "stare    : afiseaza starea masinii si numarul\n";
    cout << "autobuze : afiseaza numarul autobuzelor dupa numarul de locuri\n";
    cout << "=========================================================================\n";
    cin >> stat;

    if(stat == "vechime") vechime();
    else if(stat == "vechimeS") vechimeS();
    else if(stat == "vechimeA") vechimeA();
    else if(stat == "vechimeC") vechimeC();
    else if(stat == "stare") stare();
    else if(stat == "autobuze") autobuze();
    else cout << "Comanda invalida\n";

}

void save()
{
    ofstream fout_buffer;
    fout_buffer.open("flota.txt");

    int entries = S.size() + A.size() + C.size();
    fout_buffer << entries << "\n";
    for(auto i = S.begin(); i != S.end(); i++)
        fout_buffer << *i;
    for(auto i = A.begin(); i != A.end(); i++)
        fout_buffer << *i;
    for(auto i = C.begin(); i != C.end(); i++)
        fout_buffer << *i;
    fout_buffer.close();
}

void exit_no_save()
{

}

void exit()
{
    save();
}


int main()
{
    upload(); //incarcarea datelor din fisierul flota.txt

    string state = "";
    while(state != "exit" && state != "exit_no_save")
    {
        cout << "=========================================================================\n";
        cout << "afisare      : afisarea autoturismelor din flota\n";
        cout << "afisareS     : afisare autoturisme de serviciu\n";
        cout << "afisareC     : afisare camioane\n";
        cout << "afisareA     : afisare autobuze\n";
        cout << "afisareID    : afisarea autoturismului dupa ID\n";
        cout << "adauga       : adaugarea unui autoturism in flota\n";
        cout << "sterge       : casarea unui autoturism\n";
        cout << "expira       : afisarea autoturismelor a caror ITP expira in luna curenta\n";
        cout << "statistica   : meniul de statistici\n";
        cout << "save         : salvarea modificarilor in fisier\n";
        cout << "exit         : salvarea modificarilor si inchiderea aplicatiei\n";
        cout << "exit_no_save : inchiderea aplicatiei fara a salva modificarile\n";
        cout << "=========================================================================\n";
        cin >> state;


        if(state == "afisare")  afisare();
        else if(state == "afisareS") afisareS();
        else if(state == "afisareC") afisareC();
        else if(state == "afisareA") afisareA();
        else if(state == "adauga") adauga();
        else if(state == "sterge") sterge();
        else if(state == "expira") expira();
        else if(state == "statistica") statistica();
        else if(state == "save") save();
        else if(state == "exit_no_save") exit_no_save();
        else if(state == "afisareID") afisareID();
        else if(state == "exit") exit();
        else cout << "Comanda invalida\n";

    }

    return 0;
}
