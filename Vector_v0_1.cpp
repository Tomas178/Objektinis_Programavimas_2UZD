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

int main() {
    setlocale(LC_ALL, "");
    vector<Studentokai> Studentai;
    vector<double> mediana;
    vector<double> galutinis_balas;

    srand(time(nullptr));

    do
    {
        Studentokai Studentas;
        wcout << L"Įveskitę " << Studentai.size()+1 << L" studento vardą: ";
        wcin >> Studentas.vardas;

        wcout << L"Įveskitę " << Studentai.size()+1 << L" studento pavardę: ";
        wcin >> Studentas.pavarde;

        char choice1;
        while (true) {
            wcout << L"Ar norėsite įvesti studento namų darbų rezultatus? (Y/N): ";
            cin >> choice1;
            choice1 = toupper(choice1);
            if (choice1 == 'Y' || choice1 == 'N') {
                break;
            }
            wcout << L"Prašome įvesti Y arba N." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        char choice4;
        while (true && choice1 == 'Y') {
            wcout << L"Ar norite, kad namų darbų pažymiai būtų generuojami atsitiktinai? (Y/N): ";
            cin >> choice4;
            choice4 = toupper(choice4);
            if (choice4 == 'Y' || choice4 == 'N') {
                break;
            }
            wcout << L"Prašome įvesti Y arba N." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice1 == 'Y' && choice4 == 'Y'){
            while (Studentas.namu_darbai.size() <= N-1){
                int nd = rand() % 10 +1;
                wcout << Studentai.size()+1 << L" Studento " << Studentas.namu_darbai.size()+1 << L" namų darbo rezultatas: " << nd << endl;
                Studentas.namu_darbai.push_back(nd);
                if(Studentas.namu_darbai.size() <= N-1){
                wcout << L"Dar generuoti pažymį? (Y/N): ";
                char choice3;
                cin >> choice3;
                if(toupper(choice3) != 'Y') break;
                }
            }
        }

        if (choice1 == 'Y' && choice4 == 'N') {
            while (Studentas.namu_darbai.size() <= N-1){
                wcout << L"Įveskitę " << Studentai.size()+1 << L" studento " << Studentas.namu_darbai.size()+1 << L" namų darbo rezultatą (1-10): ";
                int nd = 0;
                wcin >> nd;
                if(wcin.fail()){
                    wcout << L"Įveskitę skaičių!" << endl;
                    wcin.clear();
                    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if(nd < 11 && nd > 0){
                Studentas.namu_darbai.push_back(nd);
                if(Studentas.namu_darbai.size() <= N-1){
                wcout << L"Dar bus pažymių? (Y/N): ";
                char choice3;
                cin >> choice3;
                if(toupper(choice3) != 'Y') break;
                }
                }
                else
                wcout << L"Įvedėtę netinkamą skaičių, prašome pakartoti! " << endl;
            }
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        char choice5;
        while (true) {
            wcout << L"Ar norite, kad egzamino balas būtų generuojamas atsitiktinai? (Y/N): ";
            cin >> choice5;
            choice5 = toupper(choice5);
            if (choice5 == 'Y' || choice5 == 'N') {
                break;
            }
            wcout << L"Prašome įvesti Y arba N." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(choice5 == 'Y'){
            int egz = rand()%10+1;
            wcout << Studentai.size()+1 << L" Studento egzamino balas: " << egz << endl;
            Studentas.egzaminas = egz;
        } else {
            while (true){
            int egz = 0;
            wcout << L"Įveskitę " << Studentai.size()+1 << L" studento egzamino balą: ";
            cin >> egz;
            if(cin.fail()){
                wcout << L"Įveskitę skaičių!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            else if(egz < 11 && egz > 0){
            Studentas.egzaminas = egz;
            break;
            }
            else
            wcout << L"Įvedėtę netinkamą skaičių, prašome pakartoti! " << endl;
            }
        }
        
        double med, gal_bal;
        if(Studentas.namu_darbai.size() > 0){
        sort(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end());
        if(Studentas.namu_darbai.size() % 2 == 0 && Studentas.namu_darbai.size() > 0){
            med = (Studentas.namu_darbai[Studentas.namu_darbai.size()/2-1] + Studentas.namu_darbai[Studentas.namu_darbai.size()/2])/2.0*0.4 + (0.6*Studentas.egzaminas);
        } else if (Studentas.namu_darbai.size() % 2 != 0 && Studentas.namu_darbai.size() > 0){
            med = Studentas.namu_darbai[Studentas.namu_darbai.size()/2]*0.4 + 0.6*Studentas.egzaminas;
        }
        } else{
            med = Studentas.egzaminas*0.6;
        }

        if(Studentas.namu_darbai.size() > 0){
            gal_bal = 0.4*accumulate(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end(), 0)/Studentas.namu_darbai.size() + 0.6*Studentas.egzaminas;
        } else{
            gal_bal = 0.6*Studentas.egzaminas;
        }

        mediana.push_back(med);
        galutinis_balas.push_back(gal_bal);
        Studentai.push_back(Studentas);

        wcout << L"Ar norėsite įvesti dar vieną studentą? (Y/N): ";
        char choice2;
        cin >> choice2;
        if(toupper(choice2) != 'Y') break;
    } while (true);


    wcout << left << setw(20) << L"Vardas" << setw(20) << L"Pavardė" << setw(20) << L"Galutinis (Vid.)" << setw(20) << L"Galutinis (Med.)" << endl;
    wcout << L"----------------------------------------------------------------------------" << endl;

    for_each(Studentai.begin(), Studentai.end(), [&](const Studentokai& student) {
    size_t index = &student - &Studentai[0];
    wcout << left << setw(20) << student.vardas << setw(20) << student.pavarde << setw(20) << fixed << setprecision(2) << galutinis_balas[index] << setw(20) << fixed << setprecision(2) << mediana[index] << endl;
});
    system("pause");
    return 0;
}
