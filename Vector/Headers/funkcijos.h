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
        Studentas() : egzaminas(0), mediana(0), vidurkis(0) {};
        Studentas(istream &is);
        inline string Vardas() const { return vardas; }
        inline string Pavarde() const { return pavarde; }
        vector<int> Get_Nd() const { return namu_darbai; }
        int Get_Egzaminas() const { return egzaminas; }
        double Get_Mediana() const { return mediana; }
        double Get_Vidurkis() const { return vidurkis; }
        istream& readStudent(istream&);

        void SetVardas(string vard) { vardas = vard; }
        void SetPavarde(string pav) { pavarde = pav; }
        void setNd(vector<int> nd) { namu_darbai = nd;}
        void setEgzaminas(int egz) { egzaminas = egz; }
        void SetMediana(double med) { mediana = med; }
        void setVidurkis(double vid) { vidurkis = vid; }
};

extern int norima_isvedimo_vieta;
extern int programos_veikimas;
extern int norimas_rikiavimas;
extern char programos_tesinys;
extern char choice3;

extern vector<string> Vardai;
extern vector<string> Pavardes;
extern vector<Studentas> Kieti;
extern vector<Studentas> Lievi;
extern vector<Studentas> Studentai;


double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas);
double medianosSkaiciavimas(const vector<int> &namu_darbai, int nd_kiekis, int egzaminas);
bool palygintiPagalVarda(const Studentas &a, const Studentas &b);
bool palygintiPagalPavarde(const Studentas &a, const Studentas &b);
bool palygintiPagalVidurki(const Studentas &a, const Studentas &b);
bool palygintiPagalMediana(const Studentas &a, const Studentas &b);
void PasalintiKietusStudentus(vector<Studentas> &Studentai, int norimas_rikiavimas);
void GeneruotiFaila(int kiekis, int nd_kiekis);
void IsvestiRezultatus(string pavadinimas, const vector<Studentas> &Studentai, int norima_isvedimo_vieta);

#endif
