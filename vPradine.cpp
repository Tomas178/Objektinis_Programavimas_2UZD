#include <iostream>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <limits>

using namespace std;

const int N = 5;

struct Studentas {
    wstring vardas;
    wstring pavarde;
    int namu_darbai[N];
    int egzaminas;
} Studentas[100];

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

    int nd_kiekis;
    int moksk;
    double mediana[N];
    double galutinis_balas[N];

    do{
    wcout << L"Įveskitę kiek bus studentų: ";
    cin >> moksk;
    } while (!validateIntInput(moksk));

    for (int i = 0; i < moksk; i++) {
        int rezultatas = 0;

            wcout << L"Įveskitę " << i + 1 << L" studento vardą: ";
            wcin >> Studentas[i].vardas;

            wcout << L"Įveskitę " << i + 1 << L" studento pavardę: ";
            wcin >> Studentas[i].pavarde;

        do {
            wcout << L"Įveskitę " << i + 1 << L" studento namų darbų tarpinių rezultatų kiekį: ";
            cin >> nd_kiekis;
        } while (!validateIntInput(nd_kiekis));

        if(nd_kiekis < 1){
            rezultatas = 0;
            do {
                wcout << L"Įveskitę " << i + 1 << L" studento egzamino rezultatą: ";
                cin >> Studentas[i].egzaminas;
                galutinis_balas[i] = 0.6 * Studentas[i].egzaminas;
            } while (!validateIntInput(Studentas[i].egzaminas));
        }
        else{
            for (int j = 0; j < nd_kiekis; j++) {
                do {
                    wcout << L"Įveskite " << i + 1 << L" studento " << j + 1 << L" namų darbo tarpinį rezultatą: ";
                    cin >> Studentas[i].namu_darbai[j];
                } while (!validateIntInput(Studentas[i].namu_darbai[j]));
                rezultatas += Studentas[i].namu_darbai[j];
            }

            sort(Studentas[i].namu_darbai, Studentas[i].namu_darbai + nd_kiekis);

            do {
                wcout << L"Įveskitę " << i + 1 << L" studento egzamino rezultatą: ";
                cin >> Studentas[i].egzaminas;
            } while (!validateIntInput(Studentas[i].egzaminas));

            if (nd_kiekis % 2 == 0 && nd_kiekis > 0) {
                mediana[i] = (Studentas[i].namu_darbai[nd_kiekis / 2] + Studentas[i].namu_darbai[nd_kiekis / 2 - 1]) / 2.0;
            } else {
                mediana[i] = Studentas[i].namu_darbai[nd_kiekis / 2];
            }

            galutinis_balas[i] = 0.4 * rezultatas / nd_kiekis + 0.6 * Studentas[i].egzaminas;
        }
    }

    wcout << left << setw(20) << L"Vardas" << setw(20) << L"Pavardė" << setw(20) << L"Galutinis (Vid.)" << setw(20) << L"Galutinis (Med.)" << endl;
    wcout << L"----------------------------------------------------------------------------" << endl;

    for (int i = 0; i < moksk; i++) {
        wcout << left << setw(20) << Studentas[i].vardas << setw(20) << Studentas[i].pavarde << setw(20) << fixed << setprecision(2) << galutinis_balas[i] << setw(20) << fixed << setprecision(2) << mediana[i] << endl;
    }
    system("pause");
    return 0;
}
