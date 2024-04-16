#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
using namespace std;


class Zmogus {
    protected:
        string vardas, pavarde;
        Zmogus() : vardas(""), pavarde("") {};
        Zmogus(const string &vard, const string &pavard) : vardas(vard), pavarde(pavard) {};  
    public:  
        inline string Get_Vardas() const { return vardas; }
        inline string Get_Pavarde() const { return pavarde; } 
        void SetVardas(string vard) { this->vardas = vard; }
        void SetPavarde(string pav) { this->pavarde = pav; }
};

#endif
