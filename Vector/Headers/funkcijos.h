#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "Zmogus.h"
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

/**
 * @brief Studento klasė.
 */
class Studentas : public Zmogus {
    private:
        vector<int> namu_darbai; /**< Namų darbų vektorius */
        int egzaminas; /**< Saugo egzamino pazymį */
        double mediana; /**< Saugo medianos balą */
        double vidurkis; /**< Saugo vidurkio balą */
    public:
        /**
         * @brief Default'inis konstruktorius.
         */
        Studentas();

        /**
         * @brief Studento klasės konstruktorius.
         * @param vard Studento vardas.
         * @param pavard Studento pavardė.
         */
        Studentas(const string &vard, const string &pavard);

        /**
         * @brief Namų darbų gavimui.
         * @return Namų darbų vektorių.
         */
        vector<int> Get_Nd() const { return namu_darbai; }

        /**
         * @brief Gauti egzamino rezultatą.
         * @return Egzamino rezultatą.
         */
        int Get_Egzaminas() const { return egzaminas; }

        /**
         * @brief Gauti galutinį balą pagal medianą.
         * @return Galutinis balas pagal medianą.
         */
        double Get_Mediana() const { return mediana; }

        /**
         * @brief Gauti galutinį balą pagal vidurkį.
         * @return galutinis balas pagal vidurkį.
         */
        double Get_Vidurkis() const { return vidurkis; }

        /**
         * @brief Patikrinti ar namų darbų vektorius yra tuščias.
         * @return True, jei vektorius tuščias. False, jei vektorius turi elementų.
         */
        bool Nd_empty() const { return namu_darbai.empty(); }

        /**
         * @brief Namų darbų vektoriaus dydis.
         * @return Namų darbų vektoriaus dydį.
         */
        int Nd_dydis() const { return namu_darbai.size(); }

        /**
         * @brief Namų darbų rūšiavimas didėjimo tvarka.
         */
        void nd_rusiavimas() { sort(namu_darbai.begin(), namu_darbai.end()); }

        /**
         * @brief Apskaičiuoti namų darbų sumą.
         * @return namų darbų vektoriaus elementų sumą.
         */
        int Nd_Suma() { return accumulate(namu_darbai.begin(), namu_darbai.end(), 0); }

        /**
         * @brief Gauti namų darbų vektoriaus paskutinį pažymį.
         * @return Paskutinį pažymį namų darbų vektoriuje.
         */
        int Get_Last_Nd() { return namu_darbai.back(); }

        /**
         * @brief Studento klasės destruktorius.
         */
        ~Studentas();

        /**
         * @brief Priskirti egzamino rezultatą.
         * @param egz egzamino rezultatas.
         */
        void setEgzaminas(int egz) { this->egzaminas = egz; }

        /**
         * @brief Priskirti galutinį balą pagal medianą.
         * @param med galutinio balo pagal medianą rezultatas.
         */
        void SetMediana(double med) { this->mediana = med; }

        /**
         * @brief Priskirti galutinį balą pagal vidurkį.
         * @param vid Galutinio balo pagal vidurkį rezultatas.
         */
        void setVidurkis(double vid) { this->vidurkis = vid; }

        /**
         * @brief Pridėti namų darbo rezultatą i vektorių.
         * @param nd Namų darbo rezultatas.
         */
        void setNd(int nd) { this->namu_darbai.push_back(move(nd)); }

        /**
         * @brief Ištrinti paskutinį namų darbų rezultatą.
         */
        void DeleteLastNd() { this->namu_darbai.pop_back(); }

        /**
         * @brief Išvalyti visą studentą.
         */
        void ClearEverything() { this->vardas.clear(); this->pavarde.clear(); this->namu_darbai.clear(); this->egzaminas = 0; this->mediana = 0.0; this->vidurkis = 0.0; }

        /**
         * @brief Išvalyti namų darbų vektorių.
         */
        void ND_clear() { this->namu_darbai.clear(); } 

        /**
         * @brief Apskaičiuoti galutinį balą pagal vidurkį.
         * @param nd_kiekis Namų darbų rezultatų kiekis.
         * @param nd_suma Visų namų darbų suma.
         * @param egzaminas Egzamino rezultatas.
         * @return Galutinį balą pagal vidurkį.
         */
        double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas);

        /**
         * @brief Apskaičiuoti galutinį balą pagal medianą.
         * @param namu_darbai Namų darbų vektorius.
         * @param nd_kiekis Namų darbų rezultatų kiekis.
         * @param egzaminas Egzamino rezultatas.
         * @return Galutinį balą pagal medianą.
         */
        double medianosSkaiciavimas(const vector<int> &namu_darbai, int nd_kiekis, int egzaminas);

        /**
         * @brief Tik tam, kad būtų galima paveldėti Zmogus klasę.
         */
        void Print() const;

        /**
         * @brief Kopijavimo konstruktorius.
         * @param LaikinasStudentas Objektas, kurį reikia kopijuoti.
         */
        Studentas(const Studentas &LaikinasStudentas);

        /**
         * @brief Perkėlimo konstruktorius.
         * @param LaikinasStudentas Objektas, kurį reikia perkelti.
         */
        Studentas(Studentas &&LaikinasStudentas) noexcept;

        /**
         * @brief Kopijavimo priskyrimo operatorius.
         * @param LaikinasStudentas Objektas, kurį reikia kopijuoti.
         */
        Studentas& operator=(const Studentas &LaikinasStudentas);

        /**
         * @brief Perkėlimo priskyrimo operatorius.
         * @param LaikinasStudentas Objektas, kurį reikia perkelti.
         */
        Studentas& operator=(Studentas &&LaikinasStudentas);

        /**
         * @brief Perkrautas įvesties operatorius darbui su failais.
         * @param filename Įvesties stringstream objektas.
         * @param LaikinasStudentas Objektas į kurį reikia skaityti duomenis.
         * @return Įvesties stringstream objektą.
         */
        friend istringstream& operator>>(istringstream& filename, Studentas &LaikinasStudentas);

        /**
         * @brief Perkrautas įvesties operatorius darbui su vartotoju per konsolę.
         * @param manual Įvesties istream objektas.
         * @param LaikinasStudentas Objektas į kurį reikia skaityti duomenis.
         * @return Įvesties istream objektą.
         */
        friend istream& operator>>(istream& manual, Studentas &LaikinasStudentas);

        /**
         * @brief Perkrautas išvesties operatorius į konsolę.
         * @param console Išvesties ostream objektas.
         * @param LaikinasStudentas Objektas, kurį reikia išvesti.
         * @return Išvesties ostream objektą.
         */
        friend ostream& operator<<(ostream& console, const Studentas &LaikinasStudentas);

        /**
         * @brief Perkrautas išvesties operatorius į failą.
         * @param filename Išvesties ofstream objektas.
         * @param LaikinasStudentas Objektas, kurį reikia išvesti.
         * @return Išvesties ofstream objektą.
         */
        friend ofstream& operator<<(ofstream& filename, const Studentas &LaikinasStudentas);
};

extern int norima_isvedimo_vieta; /**< Kintamasis, saugantis vartotojo norimą rezultatų išvedimo vietą*/
extern int programos_veikimas; /**< Kintamasis, saugantis vartojo norimą programos veikimą*/
extern int norimas_rikiavimas; /**< Kintamsis, saugantis vartotojo norimą rikiavimą*/
extern char programos_tesinys; /**< Kintamasis, kuris žino ar vartojas nori testi darbą su programa*/
extern char choice3; /**< Kintamasis, kuris žino ar vartotojas nori kartoti tam tikrą programos dalį (Pvz.: įvesti namų darbo rezultatą)*/

extern vector<string> Vardai; /**< Vardų vektorius skirtas generuoti atsitiktinius vardus*/
extern vector<string> Pavardes; /**< Pavardžių vektorius skirtas generuoti atsitiktines pavardes*/
extern vector<Studentas> Lievi; /**< Studentų vektorius, kurie gavo skolą*/
extern vector<Studentas> Studentai; /**< Studentų vektorius, kurie išlaikė dalyką*/

/**
 * @brief Palyginti du studentus pagal vardą.
 * @param a Pirmasis studentas.
 * @param b Antrasis studentas.
 * @return True, jei a studento vardas yra žemiau pagal abecėlę nei b studento, false atvirkščiai.
 */
bool palygintiPagalVarda(const Studentas &a, const Studentas &b);

/**
 * @brief Palyginti su studentus pagal pavardę.
 * @param a Pirmasis studentas.
 * @param b Antrasis studentas.
 * @return True, jei a studentu pavardė yra žemiau pagal abecėlę nei b studento, false atvirkščiai.
 */
bool palygintiPagalPavarde(const Studentas &a, const Studentas &b);

/**
 * @brief Palyginti dviejų studentų balus pagal vidurkį.
 * @param a Pirmasis studentas.
 * @param b Antrasis studentas.
 * @return True, jei a studento galutinis balas pagal vidurkį yra mažesnis nei b studento, false atvirkščiai.
 */
bool palygintiPagalVidurki(const Studentas &a, const Studentas &b);

/**
 * @brief Palyginti dviejų studentų balus pagal medianą.
 * @param a Pirmasis studentas.
 * @param b Antrasis studentas.
 * @return True, jei a studento galutinis balas pagal medianą yra mažesnis nei b studento, false atvirkščiai.
 */
bool palygintiPagalMediana(const Studentas &a, const Studentas &b);

/**
 * @brief Panaikinti studentus, kuriu galutinis balas >= 5.0.
 * @param Studentai Studentų vektorius.
 * @param norimas_rikiavimas Norimas rikiavimas.
 */
void PasalintiKietusStudentus(vector<Studentas> &Studentai, int norimas_rikiavimas);

/**
 * @brief Generuoti studentų failą.
 * @param kiekis Norimas studentų kiekis.
 * @param nd_kiekis Norimas namų darbų kiekis kiekvienam studentui.
 */
void GeneruotiFaila(int kiekis, int nd_kiekis);

/**
 * @brief Generuoti atsitiktinius pažymius studentui.
 * @param LaikinasStudentas Studento objektas.
 */
void GeneruotiPazymius(Studentas &LaikinasStudentas);

/**
 * @brief Generuoti atsitiktinį studentą.
 * @param LaikinasStudentas Studento objektas.
 */
void GeneruotiStudenta(Studentas &LaikinasStudentas);

/**
 * @brief Išvesti rezultatus i ekraną arba į failą.
 * @param pavadinimas Norimas failo pavadinimas.
 * @param Studentai Studentų vektorius.
 * @param norima_isvedimo_vieta Norima išvedimo vieta.
 */
void IsvestiRezultatus(string pavadinimas, const vector<Studentas> &Studentai, int norima_isvedimo_vieta);

#endif