#include "../Headers/DequeFunkcijos.h"


const int N = 10;


int main() {
    try {

    deque<string> Vardai = {"Tomas", "Matas", "Kasparas", "Algirdas", "Mantas", "Adomas", "Simona", "Gerda", "Jurgita", "Ruta", "Lukas", "Edvardas", "Ernestas", "Rimas"};
    deque<string> Pavardes = {"Petronis", "Semenas", "Ceseviciute", "Poskus", "Sumskis", "Leonardas", "Petronyte", "Serelis", "Kubilius", "Katleris", "Stonkus", "Sabonis"};

    int norima_isvedimo_vieta;
    int programos_veikimas;
    int norimas_rikiavimas;
    int norima_strategija;
    deque<Studentokai> Studentai;
    deque<Studentokai> Kieti;
    deque<Studentokai> Lievi;
    srand(time(nullptr));

    do {
        try {
    while (true) {
        cout << "Pasirinkite programos eiga:\n1 - Vedimas ranka.\n2 - Generuoti pazymius.\n3 - Generuoti ir studentu pazymius, ir vardus bei pavardes.\n4 - Baigti darba.\n5 - imti duomenis is failo.\n6 - Generuoti faila.\nPasirinkite: ";
        cin >> programos_veikimas;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Iveskite skaiciu!");
        }
        if (programos_veikimas > 0 && programos_veikimas < 7)
            break;
        else
            throw runtime_error("Iveskite skaiciu intervale [1, 6]");
    }
    } catch (const invalid_argument& e) {
        cerr << "Klaida: " << e.what() << endl;
        continue;
    } catch (const out_of_range& e) {
        cerr << "Klaida: " << e.what() << endl;
        continue;
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }

        Studentokai Studentas;
        char programos_tesinys;
        char choice3;

        if(programos_veikimas == 4){
            break;
        }

        if (programos_veikimas == 5) {
            
            try{
            cout << "Cia jusu failai: " << endl;
            system("dir *.txt");
            string fileName;
            cout << "Iveskite failo pavadinima: ";
            cin >> fileName;

            ifstream DF(fileName);
            if (!DF.is_open()) { 
                throw runtime_error("Nepavyko atidaryti failo");
            }

            auto Pradzia_Skaitymo = std::chrono::high_resolution_clock::now(); 

            string line;
            getline(DF, line);

            while (getline(DF, line)) {
                istringstream iss(line);

                if (!(iss >> Studentas.vardas >> Studentas.pavarde)) {
                    cerr << "Nepavyko nuskaityti vardo ir pavardes" << endl;
                }

                int pazymys;
                Studentas.namu_darbai.clear();
                try{
                    while (iss >> pazymys) {
                    Studentas.namu_darbai.emplace_back(pazymys);
                    }
                } catch(const exception &e) {
                    cerr << "Nepavyko nuskaityti namu darbu balo " << Studentai.size() << " eiluteje:(" << endl;
                    exit(1);
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

                Studentai.emplace_back(Studentas);
            }

            DF.close();
            cout << "Nuskaitymas sekmingas:)" << endl;
            auto Pabaiga_Skaitymo = std::chrono::high_resolution_clock::now();

            auto Skaitymo_trukme = std::chrono::duration_cast<std::chrono::milliseconds>(Pabaiga_Skaitymo - Pradzia_Skaitymo).count();
            cout << "Failas Nuskaitytas per: " << Skaitymo_trukme/1000.0 << " s." << endl;
            
            } catch(const exception& e){
                cerr << "Klaida: " << e.what() << endl;
                continue;
            }
        }

        if(programos_veikimas == 6){
            int kiekis;
            int nd_kiekis;
            cout << "Keliu studentu faila generuoti?: "; cin >> kiekis;
            cout << "Kiek norite, kad studentas turetu namu darbu?: "; cin >> nd_kiekis;
            GeneruotiFaila(kiekis, nd_kiekis);
        }

        if(programos_veikimas == 3){
            try {
            int KiekisGeneravimui;
            cout << "Kiek studentu generuoti?: "; cin >> KiekisGeneravimui; 

            for(int i = 0; i < KiekisGeneravimui; i++){
                auto vardaiIter = Vardai.begin();
                advance(vardaiIter, rand() % Vardai.size());
                Studentas.vardas = *vardaiIter;

                auto pavardesIter = Pavardes.begin();
                advance(pavardesIter, rand() % Pavardes.size());
                Studentas.pavarde = *pavardesIter;

                int nd_kiekis = rand()%N+1;
                Studentas.namu_darbai.clear();
                for(int j = 0; j < nd_kiekis; j++){
                    int nd = rand()%10+1;
                    Studentas.namu_darbai.emplace_back(nd);
                }
                Studentas.egzaminas = rand()%10+1;
                Studentas.vidurkis = Vidurkis(Studentas.namu_darbai.size(), accumulate(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end(), 0), Studentas.egzaminas);
                Studentas.mediana = medianosSkaiciavimas(Studentas.namu_darbai, Studentas.namu_darbai.size(), Studentas.egzaminas);
                Studentai.emplace_back(Studentas);
            }
                cout << "Generavimas baigtas:)" << endl;
            }
            catch(const exception& e)
            {
                cerr << "Klaida generuojant studento duomenis. "<< e.what() << '\n';
            }
            
        }

        if(programos_veikimas == 1 || programos_veikimas == 2){
            cout << "Iveskite " << Studentai.size()+1 << " studento varda: ";
            cin >> Studentas.vardas;

            cout << "Iveskite " << Studentai.size()+1 << " studento pavarde: ";
            cin >> Studentas.pavarde;
        }

        if (programos_veikimas == 2){
            while (Studentas.namu_darbai.size() <= N-1){
                int kiekisNDgeneravimui = rand()%N+1;
                for(int i = 0; i < kiekisNDgeneravimui; i++){
                    int nd = rand() % 10 +1;
                    Studentas.namu_darbai.emplace_back(nd);
                }
            }
            Studentas.egzaminas = rand()%10+1;
            cout << "Skaiciu generavimas baigtas sekmingai:)" << endl;
        }

        if(programos_veikimas == 1){
            while (Studentas.namu_darbai.size() <= N-1){
                cout << "Iveskite " << Studentai.size()+1 << " studento " << Studentas.namu_darbai.size()+1 << " namu darbo rezultata (1-10): ";
                int nd = 0;
                cin >> nd;
                if(cin.fail()){
                    cout << "Iveskite skaiciu!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if(nd < 11 && nd > 0){
                    Studentas.namu_darbai.emplace_back(nd);
                    if(Studentas.namu_darbai.size() <= N-1){
                        cout << "Dar bus pazymiu? (Y/N): ";
                        cin >> choice3;
                        if(toupper(choice3) != 'Y') break;
                    }
                }
                else
                    cout << "Ivedete netinkama skaiciu, prasome pakartoti! " << endl;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        }

        if(programos_veikimas == 1){
            while (true){
                int egz = 0;
                cout << "Iveskite " << Studentai.size()+1 << " studento egzamino bala: ";
                cin >> egz;
                if(cin.fail()){
                    cout << "Iveskite skaiciu!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if(egz < 11 && egz > 0){
                    Studentas.egzaminas = egz;
                    break;
                }
                else
                    cout << "Ivedete netinkama skaiciu, prasome pakartoti! " << endl;
            }
        }
    
        if(Studentas.namu_darbai.size() > 0 && programos_veikimas != 5){
            sort(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end());
            Studentas.mediana = medianosSkaiciavimas(Studentas.namu_darbai, Studentas.namu_darbai.size(), Studentas.egzaminas);
            Studentas.vidurkis = Vidurkis(Studentas.namu_darbai.size(), accumulate(Studentas.namu_darbai.begin(), Studentas.namu_darbai.end(), 0), Studentas.egzaminas);
        }
        if(programos_veikimas != 5 && programos_veikimas != 3 && !Studentas.namu_darbai.empty())
            Studentai.emplace_back(Studentas);

        cout << "Ar noresite ivesti dar viena studenta? (Y/N): ";
        cin >> programos_tesinys;
        if(toupper(programos_tesinys) != 'Y') break;
    } while (true);

    while(!Studentai.empty()){
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

    while(!Studentai.empty()){
        cout << "\n1 - Programa vykdyti pagal 1 strategija\n2 - Programa vykdyti pagal 2 strategija\nPasirinkite: ";
        cin >> norima_strategija;
        if(cin.fail()){
            cout << "Prasome ivesti skaiciu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(norima_strategija != 1 && norima_strategija != 2){
            cout << "Ivedete netinkama skaiciu.\n";
        }
        else
            break;
    }

    if(norima_strategija == 1){
        while(!Studentai.empty()){
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
                for(auto stud : Studentai){
                    if(stud.vidurkis < 5.0) Lievi.emplace_back(stud);
                    else Kieti.emplace_back(stud);
                }
                break;
            } else if(norimas_rikiavimas == 4){
                sort(Studentai.begin(), Studentai.end(), palygintiPagalMediana);
                for(auto stud : Studentai){
                    if(stud.mediana < 5.0) Lievi.emplace_back(stud);
                    else Kieti.emplace_back(stud);
                }
                break;
            } 
            }
        }
    }

    if(norima_strategija == 2){
        while(!Studentai.empty()){
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
                auto Rusiavimo_pradzia = std::chrono::high_resolution_clock::now();
                sort(Studentai.begin(), Studentai.end(), palygintiPagalVidurki);
                auto Rusiavimo_pabaiga = std::chrono::high_resolution_clock::now();
                auto Rusiavimo_trukme = std::chrono::duration_cast<std::chrono::milliseconds>(Rusiavimo_pabaiga - Rusiavimo_pradzia).count();
                cout << "Studentu rusiavimo didejant trukme: " << Rusiavimo_trukme/1000.0 << " s." << endl;

                auto Skirstymo_pradzia = std::chrono::high_resolution_clock::now();
                for(auto stud : Studentai){
                    if(stud.vidurkis < 5.0){
                        Lievi.push_back(stud);
                    }
                }
                Studentai.erase(remove_if(Studentai.begin(), Studentai.end(),
                                [](const auto& stud) {
                                    return stud.vidurkis < 5.0;
                                }),
                    Studentai.end());
                auto Skirstymo_pabaiga = std::chrono::high_resolution_clock::now();
                auto Skirstymo_trukme = std::chrono::duration_cast<std::chrono::milliseconds>(Skirstymo_pabaiga - Skirstymo_pradzia).count();
                cout << "Studentu Skirstymo i lievus ir kietus trukme: " << Skirstymo_trukme/1000.0 << " s." << endl;
                break;
            } else if(norimas_rikiavimas == 4){
                auto Rusiavimo_pradzia = std::chrono::high_resolution_clock::now();
                sort(Studentai.begin(), Studentai.end(), palygintiPagalMediana);
                auto Rusiavimo_pabaiga = std::chrono::high_resolution_clock::now();
                auto Rusiavimo_trukme = std::chrono::duration_cast<std::chrono::milliseconds>(Rusiavimo_pabaiga - Rusiavimo_pradzia).count();
                cout << "Studentu rusiavimo didejant trukme: " << Rusiavimo_trukme/1000.0 << " s." << endl;

                auto Skirstymo_pradzia = std::chrono::high_resolution_clock::now();
                for(auto stud : Studentai){
                    if(stud.mediana < 5.0){
                        Lievi.push_back(stud);
                    }
                }
                Studentai.erase(remove_if(Studentai.begin(), Studentai.end(),
                                [](const auto& stud) {
                                    return stud.mediana < 5.0;
                                }),
                    Studentai.end());
                auto Skirstymo_pabaiga = std::chrono::high_resolution_clock::now();
                auto Skirstymo_trukme = std::chrono::duration_cast<std::chrono::milliseconds>(Skirstymo_pabaiga - Skirstymo_pradzia).count();
                cout << "Studentu Skirstymo i lievus ir kietus trukme: " << Skirstymo_trukme/1000.0 << " s." << endl;
                break;
            } 
            }
        }
    }

    if(Studentai.size() > 0){
        if(norima_strategija == 1){
            IsvestiRezultatus("Studenciokai", Studentai, norima_isvedimo_vieta);
            IsvestiRezultatus("Lievi", Lievi, norima_isvedimo_vieta);
            IsvestiRezultatus("Kieti", Kieti, norima_isvedimo_vieta);
        }
        if(norima_strategija == 2){
            IsvestiRezultatus("Studenciokai", Studentai, norima_isvedimo_vieta);
            IsvestiRezultatus("Lievi", Lievi, norima_isvedimo_vieta);
        }
    }
    
    system("pause");
    return 0;

    } catch(const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
}
