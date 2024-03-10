#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <numeric>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

struct Studentokai {
    string vardas;
    string pavarde;
    list<int> namu_darbai;
    int egzaminas;
    double mediana;
    double vidurkis;
};

extern int norima_isvedimo_vieta;
extern int programos_veikimas;
extern int norimas_rikiavimas;
extern char programos_tesinys;
extern char choice3;

extern list<string> Vardai;
extern list<string> Pavardes;
extern list<Studentokai> Kieti;
extern list<Studentokai> Lievi;


double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas);
double medianosSkaiciavimas(const list<int> &namu_darbai, int nd_kiekis, int egzaminas);
bool palygintiPagalVarda(const Studentokai &a, const Studentokai &b);
bool palygintiPagalPavarde(const Studentokai &a, const Studentokai &b);
bool palygintiPagalVidurki(const Studentokai &a, const Studentokai &b);
bool palygintiPagalMediana(const Studentokai &a, const Studentokai &b);
void GeneruotiFaila(int kiekis, int nd_kiekis);
void IsvestiRezultatus(string pavadinimas, const list<Studentokai> &Studentai, int norima_isvedimo_vieta);

#endif
