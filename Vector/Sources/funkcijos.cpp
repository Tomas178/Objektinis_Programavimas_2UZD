#include "../Headers/Zmogus.h"
#include "../Headers/funkcijos.h"

/**
 * @brief Studento klasės default'inis konstruktorius.
 * Vardo ir pavardės nustatymas į tuščią string'ą.
 * Namų darbų vektorius išvalomas.
 * Egzamino, medianos ir vidurkio balas nustatomas į 0.
*/
Studentas::Studentas() : Zmogus() {
    namu_darbai.clear();
    egzaminas = 0;
    mediana = 0.0;
    vidurkis = 0.0;
}

/**
 * @brief Studento klasės konstruktorius.
 * @param vard Studento vardas.
 * @param pavard Studento pavardė.
 * Vardo ir pavardės nustatymas į perduotus parametrus.
 * Namų darbų vektorius išvalomas.
 * Egzamino, medianos ir vidurkio balas nustatomas į 0.
*/
Studentas::Studentas(const string &vard, const string &pavard) : Zmogus(vard, pavard) {
    namu_darbai.clear();
    egzaminas = 0;
    mediana = 0.0;
    vidurkis = 0.0;
}

/**
 * @brief Studento klasės kopijavimo konstruktorius.
 * @param LaikinasStudentas Studentas, kurio duomenys kopijuojami.
 * Vardas ir pavardė nukopijuojami.
 * Namų darbų vektorius nukopijuojamas.
 * Egzamino, medianos ir vidurkio balas nukopijuojamas.
*/
Studentas::Studentas(const Studentas &LaikinasStudentas) : Zmogus(LaikinasStudentas.vardas, LaikinasStudentas.pavarde) {
    namu_darbai = LaikinasStudentas.namu_darbai;
    egzaminas = LaikinasStudentas.egzaminas;
    mediana = LaikinasStudentas.mediana;
    vidurkis = LaikinasStudentas.vidurkis;
    //cout << "Kopijavimo konstruktorius suveike" << endl;
}

/**
 * @brief Studento klasės perkelimo konstruktorius.
 * @param LaikinasStudentas Studentas, kurio duomenys perkeliami.
 * Vardas ir pavardė perkeliami.
 * Namų darbų vektorius perkeliamas.
 * Egzamino, medianos ir vidurkio balas perkeliamas.
*/
Studentas::Studentas(Studentas &&LaikinasStudentas) noexcept : Zmogus(move(LaikinasStudentas.vardas), move(LaikinasStudentas.pavarde)){
    namu_darbai = move(LaikinasStudentas.namu_darbai);
    egzaminas = move(LaikinasStudentas.egzaminas);
    mediana = move(LaikinasStudentas.mediana);
    vidurkis = move(LaikinasStudentas.vidurkis);

    LaikinasStudentas.ClearEverything();
    //cout << "Perkelimo konstruktorius suveike" << endl;
}

/**
 * @brief Studento klasės kopijavimo operatorius.
 * @param LaikinasStudentas Studentas, kurio duomenys kopijuojami.
 * @return Grąžinamas Studentas su nukopijuotais duomenimis.
*/
Studentas& Studentas::operator=(const Studentas &LaikinasStudentas){
    if(this != &LaikinasStudentas){
        vardas = LaikinasStudentas.vardas;
        pavarde = LaikinasStudentas.pavarde;
        namu_darbai = LaikinasStudentas.namu_darbai;
        egzaminas = LaikinasStudentas.egzaminas;
        mediana = LaikinasStudentas.mediana;
        vidurkis = LaikinasStudentas.vidurkis;
    }
    //cout << "kopijavimo operatorius suveike" << endl;
    return *this;
}

/**
 * @brief Studento klasės perkelimo operatorius.
 * @param LaikinasStudentas Studentas, kurio duomenys perkeliami.
 * @return Grąžinamas Studentas su perkeltais duomenimis.
*/
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
    //cout << "Perkelimo operatorius suveike" << endl;
    return *this;
}

/**
 * @brief Įvesties iš failo operatorius.
 * @param filename Įvesties failas.
 * @param LaikinasStudentas Studentas, kuriam bus priskiriami duomenys.
 * @return Grąžinamas Studentas su nuskaitytais duomenimis.
*/
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
    //cout << "As esu ivedimo is failo operatoriuje >>" << endl;
    return filename;
}

/**
 * @brief Įvesties per konsolę operatorius.
 * @param manual Įvesties srautas.
 * @param LaikinasStudentas Studentas, kuriam bus priskiriami duomenys.
 * @return Grąžinamas Studentas su nuskaitytais duomenimis.
*/
istream& operator>>(istream& manual, Studentas &LaikinasStudentas){
    if(programos_veikimas == 1){
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
    LaikinasStudentas.nd_rusiavimas();
    LaikinasStudentas.SetMediana(LaikinasStudentas.medianosSkaiciavimas(LaikinasStudentas.Get_Nd(), LaikinasStudentas.Nd_dydis(), LaikinasStudentas.Get_Egzaminas()));
    LaikinasStudentas.setVidurkis(LaikinasStudentas.Vidurkis(LaikinasStudentas.Nd_dydis(), LaikinasStudentas.Nd_Suma(), LaikinasStudentas.Get_Egzaminas()));
    //cout << "As esu ten kur Programos_veikimas == 1 ivedimo per konsole operatoriuje >>" << endl;
    }
    if(programos_veikimas == 2) {
        string vardas, pavarde;
        cout << "Iveskite studento varda: "; manual >> vardas;
        LaikinasStudentas.SetVardas(vardas);
        cout << "Iveskite studento pavarde: "; manual >> pavarde;
        LaikinasStudentas.SetPavarde(pavarde);
        GeneruotiPazymius(LaikinasStudentas);
        LaikinasStudentas.nd_rusiavimas();
        LaikinasStudentas.SetMediana(LaikinasStudentas.medianosSkaiciavimas(LaikinasStudentas.Get_Nd(), LaikinasStudentas.Nd_dydis(), LaikinasStudentas.Get_Egzaminas()));
        LaikinasStudentas.setVidurkis(LaikinasStudentas.Vidurkis(LaikinasStudentas.Nd_dydis(), LaikinasStudentas.Nd_Suma(), LaikinasStudentas.Get_Egzaminas()));
        //cout << "As esu ten kur Programos_veikimas == 2 ivedimo per konsole operatoriuje >>" << endl;	
    }
    if(programos_veikimas == 3) {
        GeneruotiStudenta(LaikinasStudentas);
        cout << "As esu ten kur Programos_veikimas == 3 ivedimo per konsole operatoriuje >>" << endl;
    }
    //cout << "As esu ivedimo per konsole operatoriuje >>" << endl;
    return manual;
}

/**
 * @brief Išvesties į ekraną operatorius.
 * @param console Išvesties srautas.
 * @param LaikinasStudentas Studentas, kurio duomenys išvedami.
 * @return Grąžinamas Studentas su išvestais duomenimis.
*/
ostream& operator<<(ostream& console, const Studentas &LaikinasStudentas){
    console << left << setw(20) << LaikinasStudentas.Get_Vardas() << setw(20) << LaikinasStudentas.Get_Pavarde() <<
    setw(20) << fixed << setprecision(2) << LaikinasStudentas.Get_Vidurkis() << fixed << setw(20) << LaikinasStudentas.Get_Mediana();
    //cout << "As esu isvedimo i konsole operatoriuje <<" << endl;
    return console;
}

/**
 * @brief Išvesties į failą operatorius.
 * @param filename Išvesties failas.
 * @param LaikinasStudentas Studentas, kurio duomenys išvedami.
 * @return Grąžinamas Studentas su išvestais duomenimis.
*/
ofstream& operator<<(ofstream& filename, const Studentas &LaikinasStudentas){
    stringstream RF;
    RF << left << setw(20) << LaikinasStudentas.Get_Vardas() << setw(20) << LaikinasStudentas.Get_Pavarde() <<
    setw(20) << fixed << setprecision(2) << LaikinasStudentas.Get_Vidurkis() << fixed << setw(20) << LaikinasStudentas.Get_Mediana();
    //cout << "As esu isvedimo i faila operatoriuje <<" << endl;
    filename << RF.str();
    RF.clear();
    return filename;
}

/**
 * @brief Studento klasės destruktorius.
 * Namų darbų vektorius išvalomas.
*/
Studentas::~Studentas(){
    namu_darbai.clear();
}

/**
 * @brief Studento klasės galutinio balo skaičiavimas pagal vidurkį.
 * @param nd_kiekis Namų darbų kiekis.
 * @param nd_suma Namų darbų suma.
 * @param egzaminas Egzamino balas.
 * @return Grąžinamas galutinis balas pagal vidurkį.
*/
double Studentas::Vidurkis(int nd_kiekis, int nd_suma, int egzaminas){
    if(nd_kiekis > 0)
        return 0.4*nd_suma/nd_kiekis + 0.6*egzaminas;
    else
        return 0.6*egzaminas;
}

/**
 * @brief Studento klasės galutinio balo skaičiavimas pagal medianą.
 * @param namu_darbai Namų darbų vektorius.
 * @param nd_kiekis Namų darbų kiekis.
 * @param egzaminas Egzamino balas.
 * @return Grąžinamas galutinis balas pagal medianą.
*/
double Studentas::medianosSkaiciavimas(const vector<int> &namu_darbai, int nd_kiekis, int egzaminas){
    if(nd_kiekis % 2 == 0 && nd_kiekis > 0)
        return (namu_darbai[nd_kiekis/2-1] + namu_darbai[nd_kiekis/2])/2.0*0.4 + 0.6*egzaminas;
    else if(nd_kiekis % 2 != 0 && nd_kiekis > 0)
        return namu_darbai[nd_kiekis/2]*0.4 + 0.6*egzaminas;
    else 
        return 0.6*egzaminas;
}

/**
 * @brief Dviejų studentų palyginimas pagal vardą.
 * @return Grąžinama true, jei pirmo studento vardas yra žemiau abecėlėje už antro studento vardą. False atvirkščiai.
*/
bool palygintiPagalVarda(const Studentas &a, const Studentas &b) {
    return a.Get_Vardas() < b.Get_Vardas();
}

/**
 * @brief Dviejų studentų palyginimas pagal pavardę.
 * @return Grąžinama true, jei pirmo studento pavardė yra žemiau abecėlėje už antro studento pavardę. False atvirkščiai.
*/
bool palygintiPagalPavarde(const Studentas &a, const Studentas &b) {
    return a.Get_Pavarde() < b.Get_Pavarde();
}

/**
 * @brief Dviejų studentų palyginimas pagal vidurkį.
 * @return Grąžinama true, jei pirmo studento vidurkis yra mažesnis už antro studento vidurkį. False atvirkščiai.
*/
bool palygintiPagalVidurki(const Studentas &a, const Studentas &b) {
    return a.Get_Vidurkis() < b.Get_Vidurkis();
}

/**
 * @brief Dviejų studentų palyginimas pagal vidurkį.
 * @return Grąžinama true, jei pirmo studento mediana yra mažesnė už antro studento medianą. False atvirkščiai.
*/
bool palygintiPagalMediana(const Studentas &a, const Studentas &b) {
    return a.Get_Mediana() < b.Get_Mediana();
}

/**
 * @brief Pašalinti studentus, kurių galutinis balas >= 5.0.
*/
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

/**
 * @brief Generuoti studentų failą.
 * @param kiekis Studentų kiekis.
 * @param nd_kiekis Namų darbų kiekis.
 * Sugeneruojamas failas su studentų vardais, pavardėmis, namų darbų ir egzamino balais.
 * Failo pavadinimas: Studentai[kiekis].txt
*/
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

/**
 * @brief Išvesti rezultatus į ekraną arba į failą.
 * @param pavadinimas Failo pavadinimas.
 * @param Studentai Studentų vektorius.
 * @param norima_isvedimo_vieta Norima išvesti rezultatus: 1 - į ekraną, 2 - į failą.
 * Išvedami studentų vardai, pavardės, galutinis balas pagal vidurkį ir galutinis balas pagal medianą.
 * Failo pavadinimas: [pavadinimas].txt
*/
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

/**
 * @brief Generuoti atsitiktinius pažymius studentui intervale [1;10].
 * @param LaikinasStudentas Studentas, kuriam bus sugeneruojami pažymiai.
*/
void GeneruotiPazymius(Studentas &LaikinasStudentas){
    int nd_kiekis = rand() % 10 + 1;
    LaikinasStudentas.ND_clear();
    for(int i = 0; i < nd_kiekis; i++){
        LaikinasStudentas.setNd(rand() % 10 + 1);
    }
    LaikinasStudentas.setEgzaminas(rand() % 10 + 1);
}

/**
 * @brief Generuoti atsitiktinį studentą.
 * @param LaikinasStudentas Studentas, kuriam bus sugeneruojami duomenys.
 * Sugeneruojamas studento vardas, pavardė, namų darbų ir egzamino balai.
*/
void GeneruotiStudenta(Studentas &LaikinasStudentas){
    vector<string> Vardai = {"Tomas", "Matas", "Kasparas", "Algirdas", "Mantas", "Adomas", "Simona", "Gerda", "Jurgita", "Ruta", "Lukas", "Edvardas", "Ernestas", "Rimas"};
    vector<string> Pavardes = {"Petronis", "Semenas", "Ceseviciute", "Poskus", "Sumskis", "Leonardas", "Petronyte", "Serelis", "Kubilius", "Katleris", "Stonkus", "Sabonis"};
    LaikinasStudentas.SetVardas(Vardai[rand() % Vardai.size()]);
    LaikinasStudentas.SetPavarde(Pavardes[rand() % Pavardes.size()]);
    GeneruotiPazymius(LaikinasStudentas);
    LaikinasStudentas.nd_rusiavimas();
    LaikinasStudentas.SetMediana(LaikinasStudentas.medianosSkaiciavimas(LaikinasStudentas.Get_Nd(), LaikinasStudentas.Nd_dydis(), LaikinasStudentas.Get_Egzaminas()));
    LaikinasStudentas.setVidurkis(LaikinasStudentas.Vidurkis(LaikinasStudentas.Nd_dydis(), LaikinasStudentas.Nd_Suma(), LaikinasStudentas.Get_Egzaminas()));
}