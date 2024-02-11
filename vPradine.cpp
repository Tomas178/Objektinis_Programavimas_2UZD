#include <iostream>
#include <iomanip>
#include <algorithm>
#include <locale>

using namespace std;

const int N = 5;

struct Studentas {
    wstring vardas;
    wstring pavarde;
    int namu_darbai[N];
    int egzaminas;
} Studentas[100];

int main() {
    setlocale(LC_ALL, "");

    int nd_kiekis;
    int moksk;
    double mediana[N];
    double galutinis_balas[N];

    wcout << L"Įveskitę kiek bus studentų: ";
    cin >> moksk;
    cin.ignore();

    for (int i = 0; i < moksk; i++) {
        int rezultatas = 0;

        wcout << L"Įveskitę " << i + 1 << L" studento vardą: ";
        wcin >> Studentas[i].vardas;

        wcout << L"Įveskitę " << i + 1 << L" studento pavardę: ";
        wcin >> Studentas[i].pavarde;

        wcout << L"Įveskitę " << i + 1 << L" studento namų darbų tarpinių rezultatų kiekį: ";
        cin >> nd_kiekis;

        for (int j = 0; j < nd_kiekis; j++) {
            wcout << L"Įveskite " << i + 1 << L" studento " << j + 1 << L" namų darbo tarpinį rezultatą: ";
            cin >> Studentas[i].namu_darbai[j];
            rezultatas += Studentas[i].namu_darbai[j];
        }

        sort(Studentas[i].namu_darbai, Studentas[i].namu_darbai + nd_kiekis);

        wcout << L"Įveskitę " << i + 1 << L" studento egzamino rezultatą: ";
        cin >> Studentas[i].egzaminas;

        if (nd_kiekis % 2 == 0) {
            mediana[i] = (Studentas[i].namu_darbai[nd_kiekis / 2] + Studentas[i].namu_darbai[nd_kiekis / 2 - 1]) / 2.0;
        } else {
            mediana[i] = Studentas[i].namu_darbai[nd_kiekis / 2];
        }

        galutinis_balas[i] = 0.4 * rezultatas / nd_kiekis + 0.6 * Studentas[i].egzaminas;
    }

    wcout << left << setw(20) << L"Vardas" << setw(20) << L"Pavardė" << setw(20) << L"Galutinis (Vid.)" << setw(20) << L"Galutinis (Med.)" << endl;
    wcout << L"----------------------------------------------------------------------------" << endl;

    for (int i = 0; i < moksk; i++) {
        wcout << left << setw(20) << Studentas[i].vardas << setw(20) << Studentas[i].pavarde << setw(20) << fixed << setprecision(2) << galutinis_balas[i] << setw(20) << fixed << setprecision(2) << mediana[i] << endl;
    }
    system("pause");
    return 0;
}
