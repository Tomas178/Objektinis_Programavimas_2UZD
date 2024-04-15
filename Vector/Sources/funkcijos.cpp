#include "../Headers/funkcijos.h"

Studentas::Studentas() : namu_darbai({0}) {
    vardas = "Nera Vardo";
    pavarde = "Nera Pavardes";
    egzaminas = 0;
    mediana = 0.0;
    vidurkis = 0.0;
}

Studentas::Studentas(string vard, string pavard) : namu_darbai({0}) {
    vardas = vard;
    pavarde = pavard;
    egzaminas = 0;
    mediana = 0.0;
    vidurkis = 0.0;
}

//Kopijavimo konstruktorius
Studentas::Studentas(const Studentas &LaikinasStudentas) {
    vardas = LaikinasStudentas.vardas;
    pavarde = LaikinasStudentas.pavarde;
    namu_darbai = LaikinasStudentas.namu_darbai;
    egzaminas = LaikinasStudentas.egzaminas;
    mediana = LaikinasStudentas.mediana;
    vidurkis = LaikinasStudentas.vidurkis;
}

Studentas::Studentas(Studentas &&LaikinasStudentas) noexcept{
    vardas = move(LaikinasStudentas.vardas);
    pavarde = move(LaikinasStudentas.pavarde);
    namu_darbai = move(LaikinasStudentas.namu_darbai);
    egzaminas = move(LaikinasStudentas.egzaminas);
    mediana = move(LaikinasStudentas.mediana);
    vidurkis = move(LaikinasStudentas.vidurkis);

    LaikinasStudentas.ClearEverything();
}

Studentas& Studentas::operator=(const Studentas &LaikinasStudentas){
    if(this != &LaikinasStudentas){
        vardas = LaikinasStudentas.vardas;
        pavarde = LaikinasStudentas.pavarde;
        namu_darbai = LaikinasStudentas.namu_darbai;
        egzaminas = LaikinasStudentas.egzaminas;
        mediana = LaikinasStudentas.mediana;
        vidurkis = LaikinasStudentas.vidurkis;
    }
    return *this;
}

Studentas& Studentas::operator=(Studentas &&LaikinasStudentas){
    if(this != &LaikinasStudentas){
        vardas = move(LaikinasStudentas.vardas);
        pavarde = move(LaikinasStudentas.pavarde);
        namu_darbai = move(LaikinasStudentas.namu_darbai);
        egzaminas = move(LaikinasStudentas.egzaminas);
        mediana = move(LaikinasStudentas.mediana);
        vidurkis = move(LaikinasStudentas.vidurkis);

        LaikinasStudentas.ClearEverything();
    }
    return *this;
}

istringstream& operator>>(istringstream& filename, Studentas &LaikinasStudentas){
    string vardas, pavarde;
    if (!(filename >> vardas >> pavarde)) {
        cerr << "Nepavyko nuskaityti vardo ir pavardes" << endl;
    }

    LaikinasStudentas.SetVardas(vardas);
    LaikinasStudentas.SetPavarde(pavarde);

    int pazymys;
    LaikinasStudentas.ND_clear();
    while (filename >> pazymys) {
        LaikinasStudentas.setNd(pazymys);
    }

    if (!LaikinasStudentas.Nd_empty()) {
        LaikinasStudentas.setEgzaminas(LaikinasStudentas.Get_Last_Nd());
        LaikinasStudentas.DeleteLastNd();
        LaikinasStudentas.nd_rusiavimas();
        LaikinasStudentas.SetMediana(LaikinasStudentas.medianosSkaiciavimas(LaikinasStudentas.Get_Nd(), LaikinasStudentas.Nd_dydis(), LaikinasStudentas.Get_Egzaminas()));
        LaikinasStudentas.setVidurkis(LaikinasStudentas.Vidurkis(LaikinasStudentas.Nd_dydis(), LaikinasStudentas.Nd_Suma(), LaikinasStudentas.Get_Egzaminas()));
    }
    cout << "As esu ivedimo is failo operatoriuje >>" << endl;
    return filename;
}

istream& operator>>(istream& manual, Studentas &LaikinasStudentas){
    string vardas, pavarde;
    char choice3;
    cout << "Iveskite studento varda: ";
    manual >> vardas;
    LaikinasStudentas.SetVardas(vardas);
    cout << "Iveskite studento pavarde: ";
    manual >> pavarde;
    LaikinasStudentas.SetPavarde(pavarde);
    while (LaikinasStudentas.Nd_dydis() <= 9){
        cout << "Iveskite studento " << LaikinasStudentas.Nd_dydis()+1 << " namu darbo rezultata (1-10): ";
        int nd = 0;
        manual >> nd;
        if(manual.fail()){
            cout << "Iveskite skaiciu!" << endl;
            manual.clear();
            manual.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if(nd < 11 && nd > 0){
            LaikinasStudentas.setNd(nd);
            if(LaikinasStudentas.Nd_dydis() <= 9){
                cout << "Dar bus pazymiu? (Y/N): ";
                manual >> choice3;
                if(toupper(choice3) != 'Y') break;
            }
        }
        else
            cout << "Ivedete netinkama skaiciu, prasome pakartoti! " << endl;
    }
    manual.clear();
    manual.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true){
        int egz = 0;
        cout << "Iveskite studento egzamino bala: ";
        manual >> egz;
        if(manual.fail()){
            cout << "Iveskite skaiciu!" << endl;
            manual.clear();
            manual.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(egz < 11 && egz > 0){
            LaikinasStudentas.setEgzaminas(egz);
            break;
        }
        else
            cout << "Ivedete netinkama skaiciu, prasome pakartoti! " << endl;
    }
    cout << "As esu rankinio budi ivedimo operatoriuje >>" << endl;
    return manual;
}

ostream& operator<<(ostream& console, const Studentas &LaikinasStudentas){
    console << left << setw(20) << LaikinasStudentas.Get_Vardas() << setw(20) << LaikinasStudentas.Get_Pavarde() <<
    setw(20) << fixed << setprecision(2) << LaikinasStudentas.Get_Vidurkis() << fixed << setw(20) << LaikinasStudentas.Get_Mediana();
    //cout << "As esu isvedimo i konsole operatoriuje <<" << endl;
    return console;

}

ofstream& operator<<(ofstream& filename, const Studentas &LaikinasStudentas){
    stringstream RF;
    RF << left << setw(20) << LaikinasStudentas.Get_Vardas() << setw(20) << LaikinasStudentas.Get_Pavarde() <<
    setw(20) << fixed << setprecision(2) << LaikinasStudentas.Get_Vidurkis() << fixed << setw(20) << LaikinasStudentas.Get_Mediana();
    //cout << "As esu isvedimo i faila operatoriuje <<" << endl;
    filename << RF.str();
    RF.clear();
    return filename;
}

Studentas::~Studentas(){
    namu_darbai.clear();
}

double Studentas::Vidurkis(int nd_kiekis, int nd_suma, int egzaminas){
    if(nd_kiekis > 0)
        return 0.4*nd_suma/nd_kiekis + 0.6*egzaminas;
    else
        return 0.6*egzaminas;
}

double Studentas::medianosSkaiciavimas(const vector<int> &namu_darbai, int nd_kiekis, int egzaminas){
    if(nd_kiekis % 2 == 0 && nd_kiekis > 0)
        return (namu_darbai[nd_kiekis/2-1] + namu_darbai[nd_kiekis/2])/2.0*0.4 + 0.6*egzaminas;
    else if(nd_kiekis % 2 != 0 && nd_kiekis > 0)
        return namu_darbai[nd_kiekis/2]*0.4 + 0.6*egzaminas;
    else 
        return 0.6*egzaminas;
}

bool palygintiPagalVarda(const Studentas &a, const Studentas &b) {
    return a.Get_Vardas() < b.Get_Vardas();
}

bool palygintiPagalPavarde(const Studentas &a, const Studentas &b) {
    return a.Get_Pavarde() < b.Get_Pavarde();
}

bool palygintiPagalVidurki(const Studentas &a, const Studentas &b) {
    return a.Get_Vidurkis() < b.Get_Vidurkis();
}

bool palygintiPagalMediana(const Studentas &a, const Studentas &b) {
    return a.Get_Mediana() < b.Get_Mediana();
}

void PasalintiKietusStudentus(vector<Studentas> &Studentai, int norimas_rikiavimas){
    try{
    if (norimas_rikiavimas == 3) {
        auto it = find_if(Studentai.begin(), Studentai.end(),
                               [](const Studentas &stud) {
                                   return stud.Get_Vidurkis() >= 5.0;
                               });

        if (it != Studentai.end()) {
            Studentai.erase(it, Studentai.end());
        } else {
            throw runtime_error("Nera studento su vidurkiu >= 5.0");
        }
    }

    if (norimas_rikiavimas == 4) {
        auto it = find_if(Studentai.begin(), Studentai.end(),
                               [](const Studentas &stud) {
                                   return stud.Get_Mediana() >= 5.0;
                               });

        if (it != Studentai.end()) {
            Studentai.erase(it, Studentai.end());
        } else {
            throw runtime_error("Nera studento su mediana >= 5.0");
        }
    }
    } catch (const exception &e){
                cerr << e.what() << endl;
    }
}

void GeneruotiFaila(int kiekis, int nd_kiekis){
    string FailoPavadinimas = "Studentai" + to_string(kiekis) + ".txt";
    ofstream FF(FailoPavadinimas);
    stringstream RF;
    try
    {
        if (!RF) { 
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

        FF << RF.str();
        RF.clear();
        FF.close();
        cout << "Failas: " << FailoPavadinimas << " sugeneruotas sekmingai:)" << endl;
    }
    catch(const exception &e)
    {
        cerr << e.what() << '\n';
    }  
}

void IsvestiRezultatus(string pavadinimas, const vector<Studentas> &Studentai, int norima_isvedimo_vieta) {
    if (Studentai.size() > 0) {
        if (norima_isvedimo_vieta == 1) {
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20)
                << "Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------------------------" << endl;

            for (const auto& studentas : Studentai) {
                 cout << studentas << endl;
            }
        } else if (norima_isvedimo_vieta == 2) {
            string FailoPavadinimas = pavadinimas + ".txt";
            ofstream RF(FailoPavadinimas);
            RF << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20)
                << "Galutinis(Med.)" << endl;
            RF << "----------------------------------------------------------------------" << endl;
            for (const auto& studentas : Studentai) {
                RF << studentas << endl;
            }
            RF.close();
            cout << "Rezultatai isvesti " << FailoPavadinimas <<" faile." << endl;
        }
    }
}