#include "funkcijos.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <vector>
#include <numeric>
#include <random>
#include <ctime>
#include <fstream>
#include <locale>

const int N = 10;


int main() {
    try {

    setlocale(LC_ALL, "C");
    vector<Studentokai> Studentai;
    int norima_isvedimo_vieta;
    int programos_veikimas;
    int norimas_rikiavimas;
    vector<string> Vardai = {"Tomas", "Matas", "Kasparas", "Algirdas", "Mantas", "Adomas", "Simona", "Gerda", "Jurgita", "Ruta", "Lukas", "Edvardas", "Ernestas", "Rimas"};
    vector<string> Pavardes = {"Petronis", "Semenas", "Ceseviciute", "Poskus", "Sumskis", "Leonardas", "Petronyte", "Serelis", "Kubilius", "Katleris", "Stonkus", "Sabonis"};

    srand(time(nullptr));

    do {
        while(true) {
            cout << "Pasirinkite programos eiga:\n1 - Vedimas ranka.\n2 - Generuoti pazymius.\n3 - Generuoti ir studentu pazymius, ir vardus bei pavardes.\n4 - Baigti darba.\n5 - imti duomenis is failo.\nPasirinkite: ";
            cin >> programos_veikimas;
            if(cin.fail()) {
                cout << "Prasome ivesti skaiciu!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if(programos_veikimas > 0 && programos_veikimas < 6)
                break;
            else
                cout << "Iveskite skaiciu siame intervale [1-5]\n";
        }

        Studentokai Studentas;
        char programos_tesinys;
        char choice3;

        if(programos_veikimas == 4){
            break;
        }

        if (programos_veikimas == 5) {
            system("dir *.txt");
            ifstream DF("studentai1000000.txt");
            if (!DF) {
                cout << "Nepavyko atidaryti failo:(" << endl;
                return 1;
            }

            string line;
            getline(DF, line);

            while (getline(DF, line)) {
                istringstream iss(line);

                if (!(iss >> Studentas.vardas >> Studentas.pavarde)) {
                    cerr << "Failed to read vardas and pavarde." << endl;
                }

                int pazymys;
                Studentas.namu_darbai.clear();
                while (iss >> pazymys) {
                    Studentas.namu_darbai.push_back(pazymys);
                }

                if (!Studentas.namu_darbai.empty()) {
                    Studentas.egzaminas = Studentas.namu_darbai.back();
                    Studentas.namu_darbai.pop_back();
                }

                if (!Studentas.namu_darbai.empty()) {
                    sort(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end());
                    Studentas.mediana = medianosSkaiciavimas(Studentas.namu_darbai, Studentas.namu_darbai.size(), Studentas.egzaminas);
                    Studentas.vidurkis = Vidurkis(Studentas.namu_darbai.size(), accumulate(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end(), 0), Studentas.egzaminas);
                }
                Studentai.push_back(Studentas);
            }

            DF.close();
            cout << "Nuskaitymas sekmingas:)" << endl;
            Studentai.shrink_to_fit();
            cout << "Vektoriaus capacity: " << Studentai.capacity() << endl;
            cout << "Vektoriaus size: " << Studentai.size() << endl;
        }

        if(programos_veikimas == 3){
            try {
            int KiekisGeneravimui;
            cout << "Kiek studentu generuoti?: "; cin >> KiekisGeneravimui; 

            for(int i = 0; i < KiekisGeneravimui; i++){
                cout << Studentai.size() << endl;
                Studentas.vardas = Vardai[rand() % Vardai.size()];
                Studentas.pavarde = Pavardes[rand() % Pavardes.size()];
                int nd_kiekis = rand()%N+1;
                Studentas.namu_darbai.clear();
                for(int j = 0; j < nd_kiekis; j++){
                    int nd = rand()%10+1;
                    Studentas.namu_darbai.push_back(nd);
                }
                for(const auto &student : Studentas.namu_darbai){
                    cout << student << " ";
                }
                cout << endl;
                Studentas.egzaminas = rand()%10+1;
                Studentas.vidurkis = Vidurkis(Studentas.namu_darbai.size(), accumulate(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end(), 0), Studentas.egzaminas);
                Studentas.mediana = medianosSkaiciavimas(Studentas.namu_darbai, Studentas.namu_darbai.size(), Studentas.egzaminas);
                Studentai.push_back(Studentas);
            }
                cout << "Generavimas baigtas:)" << endl;
            }
            catch(const exception& e)
            {
                cerr << e.what() << '\n';
            }
            
        }

        if(programos_veikimas == 1 || programos_veikimas == 2){
            cout << "Iveskitę " << Studentai.size()+1 << " studento varda: ";
            cin >> Studentas.vardas;

            cout << "Iveskitę " << Studentai.size()+1 << " studento pavardę: ";
            cin >> Studentas.pavarde;
        }

        if (programos_veikimas == 2){
            while (Studentas.namu_darbai.size() <= N-1){
                int kiekisNDgeneravimui = rand()%N+1;
                for(int i = 0; i < kiekisNDgeneravimui; i++){
                    int nd = rand() % 10 +1;
                    Studentas.namu_darbai.push_back(nd);
                }
            }
            Studentas.egzaminas = rand()%10+1;
            cout << "Skaiciu generavimas baigtas sekmingai:)" << endl;
        }

        if(programos_veikimas == 1){
            while (Studentas.namu_darbai.size() <= N-1){
                cout << "Iveskitę " << Studentai.size()+1 << " studento " << Studentas.namu_darbai.size()+1 << " namu darbo rezultata (1-10): ";
                int nd = 0;
                cin >> nd;
                if(cin.fail()){
                    cout << "Iveskitę skaiciu!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if(nd < 11 && nd > 0){
                    Studentas.namu_darbai.push_back(nd);
                    if(Studentas.namu_darbai.size() <= N-1){
                        cout << "Dar bus pazymiu? (Y/N): ";
                        cin >> choice3;
                        if(toupper(choice3) != 'Y') break;
                    }
                }
                else
                    cout << "Ivedetę netinkama skaiciu, prasome pakartoti! " << endl;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        }

        if(programos_veikimas == 1){
            while (true){
                int egz = 0;
                cout << "Iveskitę " << Studentai.size()+1 << " studento egzamino bala: ";
                cin >> egz;
                if(cin.fail()){
                    cout << "Iveskitę skaiciu!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if(egz < 11 && egz > 0){
                    Studentas.egzaminas = egz;
                    break;
                }
                else
                    cout << "Ivedetę netinkama skaiciu, prasome pakartoti! " << endl;
            }
        }
    
        if(Studentas.namu_darbai.size() > 0 && programos_veikimas != 5){
            sort(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end());
            Studentas.mediana = medianosSkaiciavimas(Studentas.namu_darbai, Studentas.namu_darbai.size(), Studentas.egzaminas);
            Studentas.vidurkis = Vidurkis(Studentas.namu_darbai.size(), accumulate(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end(), 0), Studentas.egzaminas);
        }
        if(programos_veikimas != 5 && programos_veikimas != 3)
            Studentai.push_back(Studentas);

        cout << "Ar noresite ivesti dar viena studenta? (Y/N): ";
        cin >> programos_tesinys;
        if(toupper(programos_tesinys) != 'Y') break;
    } while (true);

    while(Studentai.size() > 0){
        cout << "\n1 - Isvesti rezultata konsoleje\n2 - Isvesti rezultata faile\nPasirinkite: ";
        cin >> norima_isvedimo_vieta;
        if(cin.fail()){
            cout << "Prasome ivesti skaiciu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(norima_isvedimo_vieta != 1 && norima_isvedimo_vieta != 2){
            cout << "Ivedete netinkama skaiciu.\n";
        }
        else
            break;
    }

    while(Studentai.size() > 0){
        cout << "\n1 - Rikiuoti pagal varda\n2 - Rikiuoti pagal pavarde\n3 - Rikiuoti pagal vidurki\n4 - Rikiuoti pagal mediana\nPasirinkite: ";
        cin >> norimas_rikiavimas;
        if(cin.fail()){
            cout << "Prasome ivesti skaiciu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(norimas_rikiavimas < 1 || norimas_rikiavimas > 4){
            cout << "Ivedete netinkama skaiciu.\n";
        }
        else{
            if(norimas_rikiavimas == 1){
            sort(Studentai.begin(), Studentai.end(), palygintiPagalVarda);
            break;
        } else if(norimas_rikiavimas == 2){
            sort(Studentai.begin(), Studentai.end(), palygintiPagalPavarde);
            break;
        } else if(norimas_rikiavimas == 3){
            sort(Studentai.begin(), Studentai.end(), palygintiPagalVidurki);
            break;
        } else if(norimas_rikiavimas == 4){
            sort(Studentai.begin(), Studentai.end(), palygintiPagalMediana);
            break;
        } 
        }
    }

    if(Studentai.size() > 0){
        size_t IlgiausiasVardas = 0;
        size_t IlgiausiaPavarde = 0;
        for (const auto& student : Studentai) {
            IlgiausiasVardas = max(IlgiausiasVardas, student.vardas.length());
            IlgiausiaPavarde = max(IlgiausiaPavarde, student.pavarde.length());
    }

    if(Studentai.size() > 0 && norima_isvedimo_vieta == 1){
        cout << left << setw(IlgiausiasVardas+5) << "Vardas" << setw(IlgiausiaPavarde+5) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20)
        << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------------------------" << endl;

        for(const auto &studentai : Studentai) {
            cout << left << setw(IlgiausiasVardas+5) << studentai.vardas << setw(IlgiausiaPavarde+5) << studentai.pavarde << setw(20)
             << fixed << setprecision(2) << studentai.vidurkis << setw(20) << fixed << setprecision(2) << studentai.mediana << endl;
        }
    } else if(Studentai.size() > 0 && norima_isvedimo_vieta == 2) {
        ofstream RF("studenciokai.txt");
        RF << left << setw(IlgiausiasVardas+5) << "Vardas" << setw(IlgiausiaPavarde+5) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20)
        << "Galutinis(Med.)" << endl;
        RF << "----------------------------------------------------------------------" << endl; 
        for(const auto &studentai : Studentai) {
            RF << left << setw(IlgiausiasVardas+5) << studentai.vardas << setw(IlgiausiaPavarde+5) << studentai.pavarde << setw(20) 
            << fixed << setprecision(2) << studentai.vidurkis << setw(20) << fixed << setprecision(2) << studentai.mediana << endl;
        }
        RF.close();
        cout << "Rezultatai isvesti studenciokai.txt faile." << endl;
    }
    }
    
    system("pause");
    return 0;
    } catch(const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
        return 1; // Exit with error status
    }
}
