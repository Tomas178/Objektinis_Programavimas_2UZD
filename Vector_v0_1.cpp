#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <vector>
#include <numeric>
#include <random>
#include <ctime>

using namespace std;

const int N = 5;

struct Studentokai {
    wstring vardas;
    wstring pavarde;
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
    setlocale(LC_ALL, "");
    vector<Studentokai> Studentai;
    vector<double> mediana;
    vector<double> galutinis_balas;
    int norimas_isvedimas;
    int programos_veikimas;
    vector<wstring> Vardai = {L"Tomas", L"Matas", L"Kasparas", L"Algirdas", L"Mantas", L"Adomas", L"Simona", L"Gerda", L"Jurgita", L"Rūta", L"Lukas", L"Edvardas", L"Ernestas", L"Rimas"};
    vector<wstring> Pavardes = {L"Petronis", L"Semėnas", L"Cesevičiūtė", L"Poškus", L"Šumskis", L"Leonardas", L"Petronytė", L"Šerelis", L"Kubilius", L"Katleris", L"Stonkus", L"Sabonis"};

    srand(time(nullptr));

    do
    {
        while(true){
            std::wcout << L"Pasirinkite programos eigą:\n1 - Vedimas ranka.\n2 - Generuoti pažymius.\n3 - Generuoti ir studentų pažymius, ir vardus bei pavardes.\n4 - Baigti darbą.\nPasirinkite: ";
            std::cin >> programos_veikimas;
            if(cin.fail()){
                std::wcout << L"Prašome įvesti skaičių!\n";
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if(programos_veikimas > 0 && programos_veikimas < 5)
                break;
            else
            std::wcout << L"Įveskite skaičių šiame intervale [1-4]\n";
        }

        Studentokai Studentas;
        char programos_tesinys;
        char choice3;

        if(programos_veikimas == 4){
            break;
        }

        if(programos_veikimas == 3){
            Studentas.vardas = Vardai[rand()%14];
            Studentas.pavarde = Pavardes[rand()%12];
            std::wcout << Studentai.size()+1 << " Studento vardas: " << Studentas.vardas << endl;
            std::wcout << Studentai.size()+1 << " Studento pavarde: " << Studentas.pavarde << endl;
        }
        else{
        std::wcout << L"Įveskitę " << Studentai.size()+1 << L" studento vardą: ";
        std::wcin >> Studentas.vardas;

        std::wcout << L"Įveskitę " << Studentai.size()+1 << L" studento pavardę: ";
        std::wcin >> Studentas.pavarde;
        }

        if (programos_veikimas == 2 || programos_veikimas == 3){
            while (Studentas.namu_darbai.size() <= N-1){
                int nd = rand() % 10 +1;
                std::wcout << Studentai.size()+1 << L" Studento " << Studentas.namu_darbai.size()+1 << L" namų darbo rezultatas: " << nd << endl;
                Studentas.namu_darbai.push_back(nd);
                if(Studentas.namu_darbai.size() <= N-1){
                std::wcout << L"Dar generuoti pažymį? (Y/N): ";
                char choice3;
                cin >> choice3;
                if(toupper(choice3) != 'Y') break;
                }
            }
        }
        else{
            while (Studentas.namu_darbai.size() <= N-1){
                std::wcout << L"Įveskitę " << Studentai.size()+1 << L" studento " << Studentas.namu_darbai.size()+1 << L" namų darbo rezultatą (1-10): ";
                int nd = 0;
                std::wcin >> nd;
                if(std::wcin.fail()){
                    std::wcout << L"Įveskitę skaičių!" << endl;
                    std::wcin.clear();
                    std::wcin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if(nd < 11 && nd > 0){
                    Studentas.namu_darbai.push_back(nd);
                    if(Studentas.namu_darbai.size() <= N-1){
                    std::wcout << L"Dar bus pažymių? (Y/N): ";
                    cin >> choice3;
                    if(toupper(choice3) != 'Y') break;
                }
                }
                else
                    std::wcout << L"Įvedėtę netinkamą skaičių, prašome pakartoti! " << endl;
            }
            std::wcin.clear();
            std::wcin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        if(programos_veikimas == 2 || programos_veikimas == 3){
            int egz = rand()%10+1;
            std::wcout << Studentai.size()+1 << L" Studento egzamino balas: " << egz << endl;
            Studentas.egzaminas = egz;
        } else {
            while (true){
            int egz = 0;
            std::wcout << L"Įveskitę " << Studentai.size()+1 << L" studento egzamino balą: ";
            cin >> egz;
            if(cin.fail()){
                std::wcout << L"Įveskitę skaičių!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            else if(egz < 11 && egz > 0){
            Studentas.egzaminas = egz;
            break;
            }
            else
            std::wcout << L"Įvedėtę netinkamą skaičių, prašome pakartoti! " << endl;
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

        std::wcout << L"Ar norėsite įvesti dar vieną studentą? (Y/N): ";
        cin >> programos_tesinys;
        if(toupper(programos_tesinys) != 'Y') break;
    } while (true);

    while (Studentai.size() > 0){
    std::wcout << L"1 - Išvesti rezultatą su vidurkiu\n2 - Išvesti rezultatą su mediana\nPasirinkite: ";
    cin >> norimas_isvedimas;
    if(cin.fail()){
        wcout << L"Prašome įvesti skaičių.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(norimas_isvedimas != 1 && norimas_isvedimas != 2){
        wcout << L"Įvedėte netinkamą skaičių.\n";
    }
    else
        break;
    }

    if(norimas_isvedimas == 1 && Studentai.size() > 0){
        std::wcout << left << setw(20) << L"Vardas" << setw(20) << L"Pavardė" << setw(20) << L"Galutinis (Vid.)" << endl;
        std::wcout << L"--------------------------------------------------------" << endl;

        std::for_each(Studentai.begin(), Studentai.end(), [&](const Studentokai& student) {
        size_t index = &student - &Studentai[0];
        std::wcout << left << setw(20) << student.vardas << setw(20) << student.pavarde << setw(20) << fixed << setprecision(2) << galutinis_balas[index] << endl;
    });
    } else if(norimas_isvedimas == 2 && Studentai.size() > 0){
        std::wcout << left << setw(20) << L"Vardas" << setw(20) << L"Pavardė" << setw(20) << L"Galutinis (Med.)" << endl;
        std::wcout << L"--------------------------------------------------------" << endl;

        std::for_each(Studentai.begin(), Studentai.end(), [&](const Studentokai& student) {
        size_t index = &student - &Studentai[0];
        std::wcout << left << setw(20) << student.vardas << setw(20) << student.pavarde << setw(20) << fixed << setprecision(2) << mediana[index] << endl;
    });
    }
    system("pause");
    return 0;

}

