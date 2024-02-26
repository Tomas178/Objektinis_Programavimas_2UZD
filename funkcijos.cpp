#include "funkcijos.h"
#include <algorithm>
#include <numeric>

double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas){
    if(nd_kiekis > 0)
        return 0.4*nd_suma/nd_kiekis + 0.6*egzaminas;
    else
        return 0.6*egzaminas;
}

double medianosSkaiciavimas(const std::vector<int>& namu_darbai, int nd_kiekis, int egzaminas){
    if(nd_kiekis % 2 == 0 && nd_kiekis > 0)
        return (namu_darbai[nd_kiekis/2-1] + namu_darbai[nd_kiekis/2])/2.0*0.4 + 0.6*egzaminas;
    else if(nd_kiekis % 2 != 0 && nd_kiekis > 0)
        return namu_darbai[nd_kiekis/2]*0.4 + 0.6*egzaminas;
    else 
        return 0.6*egzaminas;
}

bool palygintiPagalVarda(const Studentokai &a, const Studentokai &b) {
    return a.vardas < b.vardas;
}

bool palygintiPagalPavarde(const Studentokai &a, const Studentokai &b) {
    return a.pavarde < b.pavarde;
}

bool palygintiPagalVidurki(const Studentokai &a, const Studentokai &b) {
    return a.vidurkis < b.vidurkis;
}

bool palygintiPagalMediana(const Studentokai &a, const Studentokai &b) {
    return a.mediana < b.mediana;
}
