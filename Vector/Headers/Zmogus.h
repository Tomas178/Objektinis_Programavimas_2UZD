#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
using namespace std;


/**
 * @class Zmogus
 * @brief Abstrakti žmogaus klasė.
 * 
 * Zmogus klasė yra abstrakti klasė, kuri turi tik vardą ir pavardę.
 * Ji turi virtualią funkciją Print(), kuri yra privaloma klasėms, kurios paveldi Zmogus klasę.
 */
class Zmogus {
    protected:
        string vardas, pavarde; /**< Saugo vardą ir pavardę */

        Zmogus() : vardas(""), pavarde("") {}; /**< Default'inis konstruktorius */
        /**
         * @brief Zmogus klasės konstruktorius.
         * @param vard Studento vardas.
         * @param pavard Studento pavardė.
        */
        Zmogus(const string &vard, const string &pavard) : vardas(vard), pavarde(pavard) {}; 
        /**
         * @brief Zmogus klasės destruktorius.
        */
        virtual ~Zmogus() {};
    public:
        /**
        * @brief Vardo gavimui.
        * @return Vardą.
        */  
        inline string Get_Vardas() const { return vardas; }
        /**
        * @brief Pavardės gavimui.
        * @return Pavardę.
        */
        inline string Get_Pavarde() const { return pavarde; } 
        /**
         * @brief Vardo nustatymui.
         * @param vard Vardas.
         */
        void SetVardas(string vard) { this->vardas = vard; }
        /**
         * @brief Pavardės nustatymui.
         * @param pav Pavardė.
        */
        void SetPavarde(string pav) { this->pavarde = pav; }
        /**
         * @brief Spausdinimo funkcija padaranti klasę abstrakčia.
        */
        virtual void Print() const = 0;
};

#endif
