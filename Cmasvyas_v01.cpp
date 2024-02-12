#include <iostream>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <limits>

using namespace std;

const int N = 5;

struct Studentai {
    wstring vardas;
    wstring pavarde;
    int* namu_darbai;
    int egzaminas;
};

bool validateIntInput(int& value) {
    if (cin.fail()) { // If the input failed (i.e., not an integer)
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
        return false; // Return false to indicate failure
    }
    return true; // Return true to indicate success
}

int main() {
    setlocale(LC_ALL, "");
    int moksk = 0;
    double mediana[N];
    double galutinis_balas[N];

    Studentai* Studentas = new Studentai[100];

    //////// galima bandyti su while ciklu ir didinti moksk po viena kiekvieno ivedimo pabaigoje
    do
    {
        int nd_kiekis = 0;
        int rezultatas = 0;
        wcout << L"Įveskitę " << moksk+1 << L" studento vardą: ";
        wcin >> Studentas[moksk].vardas;

        wcout << L"Įveskitę " << moksk+1 << L" studento pavardę: ";
        wcin >> Studentas[moksk].pavarde;

        wcout << L"Įveskitę " << moksk+1 << L" studento egzamino rezultatą (1-10): ";
        wcin >> Studentas[moksk].egzaminas;

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

        if (choice1 == 'Y') {
            Studentas[moksk].namu_darbai = new int[N];
            while (nd_kiekis <= N-1){
                wcout << L"Įveskitę " << moksk+1 << L" studento " << nd_kiekis+1 << L" namų darbo rezultatą (1-10): ";
                wcin >> Studentas[moksk].namu_darbai[nd_kiekis];
                rezultatas += Studentas[moksk].namu_darbai[nd_kiekis];
                nd_kiekis++;
                if(nd_kiekis <= N-1){
                wcout << L"Dar bus pažymių? (Y/N): ";
                char choice3;
                cin >> choice3;
                if(toupper(choice3) != 'Y') break;
                } else{
                }
            }
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else{
            Studentas[moksk].namu_darbai = nullptr;
        }
        
        if(Studentas[moksk].namu_darbai != nullptr) {
        sort(Studentas[moksk].namu_darbai, Studentas[moksk].namu_darbai + nd_kiekis);
        if(nd_kiekis % 2 == 0 && nd_kiekis > 0){
            mediana[moksk] = (Studentas[moksk].namu_darbai[nd_kiekis/2-1] + Studentas[moksk].namu_darbai[nd_kiekis/2])/2.0*0.4 + (0.6*Studentas[moksk].egzaminas);
        } else if (nd_kiekis % 2 != 0 && nd_kiekis > 0){
            mediana[moksk] = Studentas[moksk].namu_darbai[nd_kiekis/2]*0.4 + 0.6*Studentas[moksk].egzaminas;
        }
        }else{
            mediana[moksk] = 0.6*Studentas[moksk].egzaminas;
        }

        if(nd_kiekis > 0){
            galutinis_balas[moksk] = 0.4*rezultatas/nd_kiekis + 0.6*Studentas[moksk].egzaminas;
        } else{
            galutinis_balas[moksk] = 0.6*Studentas[moksk].egzaminas;
        }

        moksk++;
        wcout << L"Ar norėsite įvesti dar vieną studentą? (Y/N): ";
        char choice2;
        cin >> choice2;
        if(toupper(choice2) != 'Y') break;
    } while (true);


    wcout << left << setw(20) << L"Vardas" << setw(20) << L"Pavardė" << setw(20) << L"Galutinis (Vid.)" << setw(20) << L"Galutinis (Med.)" << endl;
    wcout << L"----------------------------------------------------------------------------" << endl;

    for (int i = 0; i < moksk; i++) {
        wcout << left << setw(20) << Studentas[i].vardas << setw(20) << Studentas[i].pavarde << setw(20) << fixed << setprecision(2) << galutinis_balas[i] << setw(20) << fixed << setprecision(2) << mediana[i] << endl;
    }
    system("pause");
    delete[] Studentas;
    return 0;
}
