#include "funkcijos.h"

double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas){
    if(nd_kiekis > 0)
        return 0.4*nd_suma/nd_kiekis + 0.6*egzaminas;
    else
        return 0.6*egzaminas;
}

double medianosSkaiciavimas(const vector<int> &namu_darbai, int nd_kiekis, int egzaminas){
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

void GeneruotiFaila(int kiekis, int nd_kiekis){
    string FailoPavadinimas = "Studentai" + to_string(kiekis) + ".txt";
    ofstream RF(FailoPavadinimas);
    try
    {
        if (!RF.is_open()) { 
            throw runtime_error("Nepavyko atidaryti failo: " + FailoPavadinimas);
        }

        RF << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
        for(int i = 1; i <= nd_kiekis; i++){
            RF << setw(7) << "ND" + to_string(i);
        }
        RF << setw(7) << "Egz." << "\n";

        for(int i = 1; i <= kiekis; i++){
            RF << left << setw(20) << "Vardas"+to_string(i) << setw(20) << "Pavarde"+to_string(i);
            for(int j = 0; j < nd_kiekis+1; j++){
                RF << setw(7) << rand()%10+1;
            }
            if(i != kiekis)
            RF << "\n";
        }

        RF.close();
        cout << "Failas: " << FailoPavadinimas << " sugeneruotas sekmingai:)" << endl;
    }
    catch(const exception &e)
    {
        cerr << e.what() << '\n';
    }  
}

void IsvestiRezultatus(string pavadinimas, const vector<Studentokai> &Studentai, int norima_isvedimo_vieta) {

        size_t IlgiausiasVardas = 0;
        size_t IlgiausiaPavarde = 0;
        for (const auto& student : Studentai) {
            IlgiausiasVardas = max(IlgiausiasVardas, student.vardas.length());
            IlgiausiaPavarde = max(IlgiausiaPavarde, student.pavarde.length());
    }

    if (Studentai.size() > 0) {
        if (norima_isvedimo_vieta == 1) {
            cout << left << setw(IlgiausiasVardas + 5) << "Vardas" << setw(IlgiausiaPavarde + 5) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20)
                << "Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------------------------" << endl;

            for (const auto& studentas : Studentai) {
                cout << left << setw(IlgiausiasVardas + 5) << studentas.vardas << setw(IlgiausiaPavarde + 5) << studentas.pavarde << setw(20)
                    << fixed << setprecision(2) << studentas.vidurkis << setw(20) << fixed << setprecision(2) << studentas.mediana << endl;
            }
        } else if (norima_isvedimo_vieta == 2) {
            string FailoPavadinimas = pavadinimas + ".txt";
            ofstream RF(FailoPavadinimas);
            RF << left << setw(IlgiausiasVardas + 5) << "Vardas" << setw(IlgiausiaPavarde + 5) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20)
                << "Galutinis(Med.)" << endl;
            RF << "----------------------------------------------------------------------" << endl;
            for (const auto& studentas : Studentai) {
                RF << left << setw(IlgiausiasVardas + 5) << studentas.vardas << setw(IlgiausiaPavarde + 5) << studentas.pavarde << setw(20)
                    << fixed << setprecision(2) << studentas.vidurkis << setw(20) << fixed << setprecision(2) << studentas.mediana << endl;
            }
            RF.close();
            cout << "Rezultatai isvesti " << FailoPavadinimas <<" faile." << endl;
        }
    }
}
