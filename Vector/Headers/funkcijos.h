#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <numeric>
#include <random>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;

class Studentas {
    private:
        string vardas;
        string pavarde;
        vector<int> namu_darbai;
        int egzaminas;
        double mediana;
        double vidurkis;
    public:
        Studentas();
        Studentas(string vard, string pavard);
        inline string Get_Vardas() const { return vardas; }
        inline string Get_Pavarde() const { return pavarde; }
        vector<int> Get_Nd() const { return namu_darbai; }
        int Get_Egzaminas() const { return egzaminas; }
        double Get_Mediana() const { return mediana; }
        double Get_Vidurkis() const { return vidurkis; }
        bool Nd_empty() const { return namu_darbai.empty(); }
        int Nd_dydis() const { return namu_darbai.size(); }
        void nd_rusiavimas() { sort(namu_darbai.begin(), namu_darbai.end()); }
        int Nd_Suma() { return accumulate(namu_darbai.begin(), namu_darbai.end(), 0); }
        int Get_Last_Nd() { return namu_darbai.back(); }
        //istream& readStudent(istream&);
        ~Studentas();

        void SetVardas(string vard) { this->vardas = vard; }
        void SetPavarde(string pav) { this->pavarde = pav; }
        void setEgzaminas(int egz) { this->egzaminas = egz; }
        void SetMediana(double med) { this->mediana = med; }
        void setVidurkis(double vid) { this->vidurkis = vid; }
        void setNd(int nd) { this->namu_darbai.push_back(nd); }
        void DeleteLastNd() { this->namu_darbai.pop_back(); }
        void ClearEverything() { this->vardas.clear(); this->pavarde.clear(); this->namu_darbai.clear(); this->egzaminas = 0; this->mediana = 0.0; this->vidurkis = 0.0; }
        void ND_clear() { this->namu_darbai.clear(); } 
        double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas);
        double medianosSkaiciavimas(const vector<int> &namu_darbai, int nd_kiekis, int egzaminas);

        Studentas(const Studentas &LaikinasStudentas);
        Studentas(Studentas &&LaikinasStudentas) noexcept;
        Studentas& operator=(const Studentas &LaikinasStudentas);
        Studentas& operator=(Studentas &&LaikinasStudentas);
};

extern int norima_isvedimo_vieta;
extern int programos_veikimas;
extern int norimas_rikiavimas;
extern char programos_tesinys;
extern char choice3;

extern vector<string> Vardai;
extern vector<string> Pavardes;
extern vector<Studentas> Lievi;
extern vector<Studentas> Studentai;

bool palygintiPagalVarda(const Studentas &a, const Studentas &b);
bool palygintiPagalPavarde(const Studentas &a, const Studentas &b);
bool palygintiPagalVidurki(const Studentas &a, const Studentas &b);
bool palygintiPagalMediana(const Studentas &a, const Studentas &b);
void PasalintiKietusStudentus(vector<Studentas> &Studentai, int norimas_rikiavimas);
void GeneruotiFaila(int kiekis, int nd_kiekis);
void IsvestiRezultatus(string pavadinimas, const vector<Studentas> &Studentai, int norima_isvedimo_vieta);

#endif
