#include <iostream>
#include <iomanip>
#include <algorithm>
#include <locale>

using namespace std;

const int N = 5;

struct Studentas {
    string vardas;
    string pavarde;
    int namu_darbai[N];
    int egzaminas;
}Studentas[100];


int main(){
    setlocale(LC_ALL, "Lithuanian");
    int nd_kiekis;
    int moksk;
    cout << "Įveskitę kiek bus studentų: ";
    cin >> moksk;
    for(int i = 0; i < moksk; i++){
    int rezultatas = 0;
    cout << "Įveskitę " << i+1 << " studento vardą: ";
    cin >> Studentas[i].vardas;
    cout << "Įveskitę " << i+1 << " studento pavardę: ";
    cin >> Studentas[i].pavarde;
    cout << "Įveskitę " << i+1 << " studento namų darbų tarpinių rezultatų kiekį: ";
    cin >> nd_kiekis;
    for(int j = 0; j < nd_kiekis; j++){
        cout << "Įveskite " << i+1 << " studento " << j+1 << " namų darbo tarpinį rezultatą: ";
        cin >> Studentas[i].namu_darbai[j];
        rezultatas += Studentas[i].namu_darbai[j];
    }

    cout << "Įveskitę " << i+1 << " studento egzamino rezultatą: ";
    cin >> Studentas[i].egzaminas;
    }
}