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

struct Studentai {
    wstring vardas;
    wstring pavarde;
    int* namu_darbai;
    int egzaminas;
};

double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas){
    if(nd_kiekis > 0)
        return 0.4*nd_suma/nd_kiekis + 0.6*egzaminas;
    else
        return 0.6*egzaminas;
}

double medianosSkaiciavimas(int* namu_darbai, int nd_kiekis, int egzaminas){
    if(nd_kiekis % 2 == 0 && nd_kiekis > 0)
        return (namu_darbai[nd_kiekis/2-1] + namu_darbai[nd_kiekis/2])/2.0*0.4 + 0.6*egzaminas;
    else if(nd_kiekis % 2 != 0 && nd_kiekis > 0)
        return namu_darbai[nd_kiekis/2]*0.4 + 0.6*egzaminas;
    else 
    return 0.6*egzaminas;
}

int main() {
    setlocale(LC_ALL, "");
    int moksk = 0;
    double* mediana = new double[50];
    double* galutinis_balas = new double[50];
    int norimas_isvedimas;
    int programos_veikimas;
    wstring Vardai[] = {L"Tomas", L"Matas", L"Kasparas", L"Algirdas", L"Mantas", L"Adomas", L"Simona", L"Gerda", L"Jurgita", L"Rūta", L"Lukas", L"Edvardas", L"Ernestas", L"Rimas"};
    wstring Pavardes[] = {L"Petronis", L"Semėnas", L"Cesevičiūtė", L"Poškus", L"Šumskis", L"Leonardas", L"Petronytė", L"Šerelis", L"Kubilius", L"Katleris", L"Stonkus", L"Sabonis"};
    Studentai* Studentas = new Studentai[50];

    srand(time(nullptr));

    do
    {
        int nd_kiekis = 0;
        int rezultatas = 0;
        while(true){
            std::wcout << L"Pasirinkite programos eigą:\n1 - Vedimas ranka.\n2 - Generuoti pažymius.\n3 - Generuoti ir studentų pažymius, ir vardus bei pavardes.\n4 - Baigti darbą.\nPasirinkite: ";
            std::cin >> programos_veikimas;
            if(cin.fail()){
                std::wcout << L"Prašome įvesti skaičių!\n";
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else if(programos_veikimas > 0 && programos_veikimas < 5)
                break;
            else
            std::wcout << L"Įveskite skaičių šiame intervale [1-4]\n";
        }

        if(programos_veikimas == 4)
        break;

        if(programos_veikimas == 3){
            Studentas[moksk].vardas = Vardai[rand()%14];
            Studentas[moksk].pavarde = Pavardes[rand()%12];
            std::wcout << moksk+1 << " Studento vardas: " << Studentas[moksk].vardas << endl;
            std::wcout << moksk+1 << " Studento pavarde: " << Studentas[moksk].pavarde << endl;
        } 
        else{
            std::wcout << L"Įveskitę " << moksk+1 << L" studento vardą: ";
            std::wcin >> Studentas[moksk].vardas;
            std::wcout << L"Įveskitę " << moksk+1 << L" studento pavardę: ";
            std::wcin >> Studentas[moksk].pavarde;
        }

        if(programos_veikimas == 2 || programos_veikimas == 3){
            Studentas[moksk].namu_darbai = new int[N];
            while(nd_kiekis <= N-1){
                Studentas[moksk].namu_darbai[nd_kiekis] = rand()%10+1;
                std::wcout << moksk+1 << L" studento " << nd_kiekis+1 << L" namų darbo rezultatas: " << Studentas[moksk].namu_darbai[nd_kiekis] << endl;
                rezultatas += Studentas[moksk].namu_darbai[nd_kiekis];
                nd_kiekis++;
                if(nd_kiekis <= N-1){
                std::wcout << L"Dar generuoti pažymį? (Y/N): ";
                char choice3;
                cin >> choice3;
                if(toupper(choice3) != 'Y') break;
                }
            }
        }
        else if(programos_veikimas == 1){
            Studentas[moksk].namu_darbai = new int[N];
            while (nd_kiekis <= N-1){
                std::wcout << L"Įveskitę " << moksk+1 << L" studento " << nd_kiekis+1 << L" namų darbo rezultatą (1-10): ";
                std::wcin >> Studentas[moksk].namu_darbai[nd_kiekis];
                if(std::wcin.fail()){
                    std::wcout << L"Įveskitę skaičių!" << endl;
                    std::wcin.clear();
                    std::wcin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if(Studentas[moksk].namu_darbai[nd_kiekis] < 11 && Studentas[moksk].namu_darbai[nd_kiekis] > 0){
                    rezultatas += Studentas[moksk].namu_darbai[nd_kiekis];
                    nd_kiekis++;
                    if(nd_kiekis <= N-1){
                        std::wcout << L"Dar bus pažymių? (Y/N): ";
                        char choice3;
                        cin >> choice3;
                        if(toupper(choice3) != 'Y') break;
                    }
                }
                else
                std::wcout << L"Įvedėtę netinkamą skaičių, prašome pakartoti! " << endl;
            }
            std::wcin.clear();
            std::wcin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else{
            Studentas[moksk].namu_darbai = nullptr;
        }

        if(programos_veikimas == 2 || programos_veikimas == 3){
            Studentas[moksk].egzaminas = rand()%10+1;
            std::wcout << moksk+1 << L" Studento egzamino balas: " << Studentas[moksk].egzaminas << endl;
        }
        else {
            while(true){
                std::wcout << L"Įveskitę " << moksk+1 << L" studento egzamino rezultatą (1-10): ";
                std::cin >> Studentas[moksk].egzaminas;
                if(cin.fail()){
                    std::wcout << L"Įveskitę skaičių!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                else if(Studentas[moksk].egzaminas < 11 && Studentas[moksk].egzaminas > 0){
                    break;
                }
                else
                    std::wcout << L"Įvedėtę netinkamą skaičių, prašome pakartoti! " << endl;
            }
        }
        
        if(Studentas[moksk].namu_darbai != nullptr) {
        sort(Studentas[moksk].namu_darbai, Studentas[moksk].namu_darbai + nd_kiekis);
        mediana[moksk] = medianosSkaiciavimas(Studentas[moksk].namu_darbai, nd_kiekis, Studentas[moksk].egzaminas);
        galutinis_balas[moksk] = Vidurkis(nd_kiekis, rezultatas, Studentas[moksk].egzaminas);
        }

        moksk++;
        std::wcout << L"Ar norėsite įvesti dar vieną studentą? (Y/N): ";
        char choice2;
        cin >> choice2;
        if(toupper(choice2) != 'Y') break;
    } while (true);

    while (moksk > 0){
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

    if(norimas_isvedimas == 1 && moksk > 0){
        std::wcout << left << setw(20) << L"Vardas" << setw(20) << L"Pavardė" << setw(20) << L"Galutinis (Vid.)" << endl;
        std::wcout << L"--------------------------------------------------------" << endl;
        for (int i = 0; i < moksk; i++) {
            std::wcout << left << setw(20) << Studentas[i].vardas << setw(20) << Studentas[i].pavarde << setw(20) << fixed << setprecision(2) << galutinis_balas[i] << endl;
    }
    } else if(norimas_isvedimas == 2 && moksk > 0){
        std::wcout << left << setw(20) << L"Vardas" << setw(20) << L"Pavardė" << setw(20) << L"Galutinis (Med.)" << endl;
        std::wcout << L"--------------------------------------------------------" << endl;
        for (int i = 0; i < moksk; i++) {
            std::wcout << left << setw(20) << Studentas[i].vardas << setw(20) << Studentas[i].pavarde << setw(20) << fixed << setprecision(2) << mediana[i] << endl;
    }
    }

    //Trynimas
    for (int i = 0; i < moksk; ++i) {
    delete[] Studentas[i].namu_darbai;
    }
    delete[] Studentas;
    delete[] mediana;
    delete[] galutinis_balas;
    system("pause");
    return 0;
}
