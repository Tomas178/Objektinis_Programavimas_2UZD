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
#include <windows.h>

using namespace std;

const int N = 5;

struct Studentokai {
    string vardas;
    string pavarde;
    vector<int> namu_darbai;
    int egzaminas;
};

double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas){
    if(nd_kiekis > 0)
        return 0.4*nd_suma/nd_kiekis + 0.6*egzaminas;
    else
        return 0.6*egzaminas;
}

double medianosSkaiciavimas(vector<int>& namu_darbai, int nd_kiekis, int egzaminas){
    if(nd_kiekis % 2 == 0 && nd_kiekis > 0)
        return (namu_darbai[nd_kiekis/2-1] + namu_darbai[nd_kiekis/2])/2.0*0.4 + 0.6*egzaminas;
    else if(nd_kiekis % 2 != 0 && nd_kiekis > 0)
        return namu_darbai[nd_kiekis/2]*0.4 + 0.6*egzaminas;
    else 
        return 0.6*egzaminas;
}

int main() {
    try {
        // Set the console's code page to UTF-8
        SetConsoleOutputCP(CP_UTF8);

        // Confirm the new code page setting
        cout << "Console code page: " << GetConsoleOutputCP() << endl;

        // Your program logic here...
    } catch (const std::runtime_error& e) {
        // Handle any errors that occur when setting the code page
        cerr << "Error setting code page: " << e.what() << endl;
        return 1; // Exit the program with an error status
    }


    setlocale(LC_ALL, "C");
    vector<Studentokai> Studentai;
    vector<double> mediana;
    vector<double> galutinis_balas;
    int norimas_isvedimas;
    int programos_veikimas;
    int failo_skaitymas = 0;
    vector<string> Vardai = {"Tomas", "Matas", "Kasparas", "Algirdas", "Mantas", "Adomas", "Simona", "Gerda", "Jurgita", "Rūta", "Lukas", "Edvardas", "Ernestas", "Rimas"};
    vector<string> Pavardes = {"Petronis", "Semėnas", "Cesevičiūtė", "Poškus", "Šumskis", "Leonardas", "Petronytė", "Šerelis", "Kubilius", "Katleris", "Stonkus", "Sabonis"};

    srand(time(nullptr));

    do {
        while(true) {
            cout << "Pasirinkite programos eigą:\n1 - Vedimas ranka.\n2 - Generuoti pažymius.\n3 - Generuoti ir studentų pažymius, ir vardus bei pavardes.\n4 - Baigti darbą.\n5 - imti duomenis iš failo.\nPasirinkite: ";
            cin >> programos_veikimas;
            if(cin.fail()) {
                cout << "Prašome įvesti skaičių!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if(programos_veikimas > 0 && programos_veikimas < 6)
                break;
            else
                cout << "Įveskite skaičių šiame intervale [1-4]\n";
        }

        Studentokai Studentas;
        char programos_tesinys;
        char choice3;

        if(programos_veikimas == 4){
            break;
        }

        if(programos_veikimas == 5){
            ifstream DF("kursiokai.txt");
            if(!DF){
                cout << "Npeavyko atidaryti failo:(" << endl;
                break;
            }
            string line;
            getline(DF, line);
            while (DF >> Studentas.vardas >> Studentas.pavarde) {
            cout << "Studento vardas: " << Studentas.vardas << endl;
            cout << "Studento pavarde: " << Studentas.pavarde << endl;
            for(int i = 0; i < 5; i++){
                int pazymys;
                DF >> pazymys;
                cout << i << "-asis pazymy = " << pazymys << endl;
                Studentas.namu_darbai.push_back(pazymys);
            }
            DF >> Studentas.egzaminas;
            cout << "egzamino balas = " << Studentas.egzaminas << endl;
            }
            cout << "Nuskaitymas iš failo pavyko" << endl;
        }

        if(programos_veikimas == 3){
            Studentas.vardas = Vardai[rand()%14];
            Studentas.pavarde = Pavardes[rand()%12];
            cout << Studentai.size()+1 << " Studento vardas: " << Studentas.vardas << endl;
            cout << Studentai.size()+1 << " Studento pavarde: " << Studentas.pavarde << endl;
        }
        if(programos_veikimas == 1 || programos_veikimas == 2){
            cout << "Įveskitę " << Studentai.size()+1 << " studento vardą: ";
            cin >> Studentas.vardas;

            cout << "Įveskitę " << Studentai.size()+1 << " studento pavardę: ";
            cin >> Studentas.pavarde;
        }

        if (programos_veikimas == 2 || programos_veikimas == 3){
            while (Studentas.namu_darbai.size() <= N-1){
                int nd = rand() % 10 +1;
                cout << Studentai.size()+1 << " Studento " << Studentas.namu_darbai.size()+1 << " namų darbo rezultatas: " << nd << endl;
                Studentas.namu_darbai.push_back(nd);
                if(Studentas.namu_darbai.size() <= N-1){
                    cout << "Dar generuoti pažymį? (Y/N): ";
                    char choice3;
                    cin >> choice3;
                    if(toupper(choice3) != 'Y') break;
                }
            }
        }
        if(programos_veikimas == 1){
            while (Studentas.namu_darbai.size() <= N-1){
                cout << "Įveskitę " << Studentai.size()+1 << " studento " << Studentas.namu_darbai.size()+1 << " namų darbo rezultatą (1-10): ";
                int nd = 0;
                cin >> nd;
                if(cin.fail()){
                    cout << "Įveskitę skaičių!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if(nd < 11 && nd > 0){
                    Studentas.namu_darbai.push_back(nd);
                    if(Studentas.namu_darbai.size() <= N-1){
                        cout << "Dar bus pažymių? (Y/N): ";
                        cin >> choice3;
                        if(toupper(choice3) != 'Y') break;
                    }
                }
                else
                    cout << "Įvedėtę netinkamą skaičių, prašome pakartoti! " << endl;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        if(programos_veikimas == 2 || programos_veikimas == 3){
            int egz = rand()%10+1;
            cout << Studentai.size()+1 << " Studento egzamino balas: " << egz << endl;
            Studentas.egzaminas = egz;
        }
        if(programos_veikimas == 1){
            while (true){
                int egz = 0;
                cout << "Įveskitę " << Studentai.size()+1 << " studento egzamino balą: ";
                cin >> egz;
                if(cin.fail()){
                    cout << "Įveskitę skaičių!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if(egz < 11 && egz > 0){
                    Studentas.egzaminas = egz;
                    break;
                }
                else
                    cout << "Įvedėtę netinkamą skaičių, prašome pakartoti! " << endl;
            }
        }
    
        if(Studentas.namu_darbai.size() > 0){
            double gal_bal, med;
            sort(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end());
            med = medianosSkaiciavimas(Studentas.namu_darbai, Studentas.namu_darbai.size(), Studentas.egzaminas);
            gal_bal = Vidurkis(Studentas.namu_darbai.size(),accumulate(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end(), 0), Studentas.egzaminas);
            galutinis_balas.push_back(gal_bal);
            mediana.push_back(med);
        }
        
        Studentai.push_back(Studentas);

        cout << "Ar norėsite įvesti dar vieną studentą? (Y/N): ";
        cin >> programos_tesinys;
        if(toupper(programos_tesinys) != 'Y') break;
    } while (true);

    while (Studentai.size() > 0){
        cout << "1 - Išvesti rezultatą su vidurkiu\n2 - Išvesti rezultatą su mediana\nPasirinkite: ";
        cin >> norimas_isvedimas;
        if(cin.fail()){
            cout << "Prašome įvesti skaičių.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(norimas_isvedimas != 1 && norimas_isvedimas != 2){
            cout << "Įvedėte netinkamą skaičių.\n";
        }
        else
            break;
    }

    size_t maxNameWidth = 0;
    size_t maxSurnameWidth = 0;
    for (const auto& student : Studentai) {
        maxNameWidth = max(maxNameWidth, student.vardas.length());
        maxSurnameWidth = max(maxSurnameWidth, student.pavarde.length());
    }

    if(norimas_isvedimas == 1 && Studentai.size() > 0){
        cout << left << setw(maxNameWidth+10) << "Vardas" << setw(maxSurnameWidth+10) << "Pavardė" << setw(20) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------------" << endl;

        for(size_t i = 0; i < Studentai.size(); ++i) {
            cout << left << setw(maxNameWidth+10) << Studentai[i].vardas << setw(maxSurnameWidth+10) << Studentai[i].pavarde << setw(20) << fixed << setprecision(2) << galutinis_balas[i] << endl;
        }
    } else if(norimas_isvedimas == 2 && Studentai.size() > 0){
        cout << left << setw(maxNameWidth+10) << "Vardas" << setw(maxSurnameWidth+10) << "Pavardė" << setw(20) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------------" << endl;

        for(size_t i = 0; i < Studentai.size(); ++i) {
            cout << left << setw(maxNameWidth+10) << Studentai[i].vardas << setw(maxSurnameWidth+10) << Studentai[i].pavarde << setw(20) << fixed << setprecision(2) << mediana[i] << endl;
        }
    }
    system("pause");
    return 0;
}
