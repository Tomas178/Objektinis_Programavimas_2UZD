#include "../Headers/funkcijos.h"


const int N = 10;


int main() {
    try {

    vector<string> Vardai = {"Tomas", "Matas", "Kasparas", "Algirdas", "Mantas", "Adomas", "Simona", "Gerda", "Jurgita", "Ruta", "Lukas", "Edvardas", "Ernestas", "Rimas"};
    vector<string> Pavardes = {"Petronis", "Semenas", "Ceseviciute", "Poskus", "Sumskis", "Leonardas", "Petronyte", "Serelis", "Kubilius", "Katleris", "Stonkus", "Sabonis"};

    int norima_isvedimo_vieta;
    int programos_veikimas;
    int norimas_rikiavimas;
    int norima_strategija;
    vector<Studentas> Studentai;
    vector<Studentas> Kieti;
    vector<Studentas> Lievi;
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

        Studentas Studentokai;
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

            auto Pradzia_Skaitymo = chrono::high_resolution_clock::now(); 

            string line;
            getline(DF, line);
            cout << "Pirma eilute pasalinta!!!!" << endl;

            while (getline(DF, line)) {
                istringstream iss(line);

                string vardas, pavarde;
                cout << "Pradedamas vardo ir pavardes skaitymas!!!" << endl;
                if (!(iss >> vardas >> pavarde)) {
                    cerr << "Nepavyko nuskaityti vardo ir pavardes" << endl;
                } else {
                    Studentokai.SetVardas(vardas);
                    cout << "Vardas pridetas!!!" << endl;
                    Studentokai.SetPavarde(pavarde);
                    cout << "Vardas ir Pavarde prideti!!!" << endl;
                }

                cout << "Pradedamas ND irasymas!!!" << endl;
                int pazymys;
                vector<int> papildomas_nd;
                papildomas_nd.clear();
                try{
                    while (iss >> pazymys) {
                        papildomas_nd.push_back(pazymys);
                    }
                } catch(const exception &e) {
                    cerr << "Nepavyko nuskaityti namu darbu balo " << Studentai.size() << " eiluteje:(" << endl;
                    exit(1);
                }

                cout << "SU nd viskas ivyko sekmingai!!!" << endl;
                if (!papildomas_nd.empty()) {
                    Studentokai.setEgzaminas(papildomas_nd.back());
                    cout << "Egzamino balas pridetas sekmingai!!!" << endl;
                    papildomas_nd.pop_back();
                    cout << "Nd paskutinis pazymys pasalintas sekmingai!!!" << endl;
                    Studentokai.setNd(papildomas_nd);
                    cout << "Nd prideti i Studento klase!!!" << endl;
                }
                cout << "Namu darbu vektoriaus dydis = " << Studentokai.Nd_dydis() << endl;
                cout << "Papildomas_nd vektoriaus dydis = " << papildomas_nd.size() << endl;
                cout << "Prasideda rusiavimo, ir vidurkiu bei medianos skaicivimu eile!!!" << endl;
                if (!Studentokai.Nd_tuscia_ar_netuscia()) {
                    Studentokai.nd_rusiavimas();
                    cout << "Isrusiuota sekmingai!!!" << endl;
                    Studentokai.SetMediana(Studentokai.medianosSkaiciavimas(Studentokai.Get_Nd(), Studentokai.Nd_dydis(), Studentokai.Get_Egzaminas()));
                    cout << "Mediana suskaiciuota sekmingai!!!" << endl;
                    Studentokai.setVidurkis(Studentokai.Vidurkis(Studentokai.Nd_dydis(), Studentokai.Nd_Suma(), Studentokai.Get_Egzaminas()));
                    cout << "Vidurkis suskaiciuota sekmingai!!!" << endl;
                }

                Studentai.push_back(Studentokai);
                cout << "Studento duomenis prideti sekmingai i Studentai vektoriu" << endl;
            }

            DF.close();
            cout << "Nuskaitymas sekmingas:)" << endl;
            Studentai.shrink_to_fit();
            auto Pabaiga_Skaitymo = chrono::high_resolution_clock::now();

            auto Skaitymo_trukme = chrono::duration_cast<chrono::milliseconds>(Pabaiga_Skaitymo - Pradzia_Skaitymo).count();
            cout << "Failas Nuskaitytas per: " << Skaitymo_trukme/1000.0 << " s." << endl;

            cout << "Vektoriaus capacity: " << Studentai.capacity() << endl;
            cout << "Vektoriaus size: " << Studentai.size() << endl;
            
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
            vector<int> papildomas_nd;
            int KiekisGeneravimui;
            cout << "Kiek studentu generuoti?: "; cin >> KiekisGeneravimui; 
            Studentai.reserve(KiekisGeneravimui);

            for(int i = 0; i < KiekisGeneravimui; i++){
                Studentokai.SetVardas(Vardai[rand() % Vardai.size()]);
                Studentokai.SetPavarde(Pavardes[rand() % Pavardes.size()]);
                int nd_kiekis = rand()%N+1;
                Studentokai.Get_Nd().clear();
                for(int j = 0; j < nd_kiekis; j++){
                    int nd = rand()%10+1;
                    papildomas_nd.push_back(nd);
                }
                Studentokai.setNd(papildomas_nd);
                Studentokai.setEgzaminas(rand()%10+1);
                Studentokai.setVidurkis(Studentokai.Vidurkis(Studentokai.Nd_dydis(), Studentokai.Nd_Suma(), Studentokai.Get_Egzaminas()));
                Studentokai.SetMediana(Studentokai.medianosSkaiciavimas(Studentokai.Get_Nd(), Studentokai.Nd_dydis(), Studentokai.Get_Egzaminas()));
                Studentai.push_back(Studentokai);
            }
                cout << "Generavimas baigtas:)" << endl;
            }
            catch(const exception& e)
            {
                cerr << "Klaida generuojant studento duomenis. "<< e.what() << '\n';
            }
            
        }

        if(programos_veikimas == 1 || programos_veikimas == 2){
            string vardas, pavarde;
            cout << "Iveskite " << Studentai.size()+1 << " studento varda: ";
            cin >> vardas;
            Studentokai.SetVardas(vardas);

            cout << "Iveskite " << Studentai.size()+1 << " studento pavarde: ";
            cin >> pavarde;
            Studentokai.SetPavarde(pavarde);
        }

        if (programos_veikimas == 2){
            vector<int> papildomas_nd;
            while (Studentokai.Nd_dydis() <= N-1){
                int kiekisNDgeneravimui = rand()%N+1;
                for(int i = 0; i < kiekisNDgeneravimui; i++){
                    int nd = rand() % 10 +1;
                    papildomas_nd.push_back(nd);
                }
            }
            Studentokai.setNd(papildomas_nd);
            Studentokai.setEgzaminas(rand()%10+1);
            cout << "Skaiciu generavimas baigtas sekmingai:)" << endl;
        }

        if(programos_veikimas == 1){
            vector<int> papildomas_nd;
            while (Studentokai.Nd_dydis() <= N-1){
                cout << "Iveskite " << Studentai.size()+1 << " studento " << Studentokai.Nd_dydis()+1 << " namu darbo rezultata (1-10): ";
                int nd = 0;
                cin >> nd;
                if(cin.fail()){
                    cout << "Iveskite skaiciu!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if(nd < 11 && nd > 0){
                    papildomas_nd.push_back(nd);
                    if(Studentokai.Nd_dydis() <= N-1){
                        cout << "Dar bus pazymiu? (Y/N): ";
                        cin >> choice3;
                        if(toupper(choice3) != 'Y') break;
                    }
                }
                else
                    cout << "Ivedete netinkama skaiciu, prasome pakartoti! " << endl;
            }
            Studentokai.setNd(papildomas_nd);
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
                    Studentokai.setEgzaminas(egz);
                    break;
                }
                else
                    cout << "Ivedete netinkama skaiciu, prasome pakartoti! " << endl;
            }
        }
    
        if(Studentokai.Nd_dydis() > 0 && programos_veikimas != 5){
            Studentokai.nd_rusiavimas();
            Studentokai.SetMediana(Studentokai.medianosSkaiciavimas(Studentokai.Get_Nd(), Studentokai.Nd_dydis(), Studentokai.Get_Egzaminas()));
            Studentokai.setVidurkis(Studentokai.Vidurkis(Studentokai.Nd_dydis(), Studentokai.Nd_Suma(), Studentokai.Get_Egzaminas()));
        }
        if(programos_veikimas != 5 && programos_veikimas != 3 && !Studentokai.Get_Nd().empty())
            Studentai.push_back(Studentokai);

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
        cout << "\n1 - Programa vykdyti pagal 1 strategija\n2 - Programa vykdyti pagal 2 strategija\n3 - Programa vykdyti pagal 3 strategija\nPasirinkite: ";
        cin >> norima_strategija;
        if(cin.fail()){
            cout << "Prasome ivesti skaiciu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(norima_strategija != 1 && norima_strategija != 2 && norima_strategija != 3){
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
                if(stud.Get_Vidurkis() < 5.0) Lievi.push_back(stud);
                else Kieti.push_back(stud);
            }
            break;
        } else if(norimas_rikiavimas == 4){
            sort(Studentai.begin(), Studentai.end(), palygintiPagalMediana);
            for(auto stud : Studentai){
                if(stud.Get_Mediana() < 5.0) Lievi.push_back(stud);
                else Kieti.push_back(stud);
            }
            break;
        } 
        }
    }
    Lievi.shrink_to_fit();
    Kieti.shrink_to_fit();
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
            sort(Studentai.begin(), Studentai.end(), palygintiPagalVidurki);
            for(auto stud : Studentai){
                if(stud.Get_Vidurkis() > 5.0){
                    Kieti.push_back(stud);
                }
            }
            Studentai.erase(remove_if(Studentai.begin(), Studentai.end(),
                               [](const auto& stud) {
                                   return stud.Get_Vidurkis() > 5.0;
                               }),
                Studentai.end());
            break;
        } else if(norimas_rikiavimas == 4){
            sort(Studentai.begin(), Studentai.end(), palygintiPagalMediana);
            for(auto stud : Studentai){
                if(stud.Get_Mediana() > 5.0){
                    Kieti.push_back(stud);
                }
            }
            Studentai.erase(remove_if(Studentai.begin(), Studentai.end(),
                               [](const auto& stud) {
                                   return stud.Get_Mediana() > 5.0;
                               }),
                Studentai.end());
            break;
        } 
        }
    }
    Kieti.shrink_to_fit();
    }

    if(norima_strategija == 3){
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
                auto Rusiavimo_pradzia = chrono::high_resolution_clock::now();
                sort(Studentai.begin(), Studentai.end(), palygintiPagalVidurki);
                auto Rusiavimo_pabaiga = chrono::high_resolution_clock::now();
                auto Rusiavimo_trukme = chrono::duration_cast<chrono::milliseconds>(Rusiavimo_pabaiga - Rusiavimo_pradzia).count();
                cout << "Studentu rusiavimo didejant trukme: " << Rusiavimo_trukme/1000.0 << " s." << endl;

                auto Skirstymo_pradzia = chrono::high_resolution_clock::now();
                for(auto stud : Studentai){
                    if(stud.Get_Vidurkis() >= 5.0){
                        Kieti.push_back(stud);
                    }
                }
                PasalintiKietusStudentus(Studentai, norimas_rikiavimas);
                auto Skirstymo_pabaiga = chrono::high_resolution_clock::now();
                auto Skirstymo_trukme = chrono::duration_cast<chrono::milliseconds>(Skirstymo_pabaiga - Skirstymo_pradzia).count();
                cout << "Studentu Skirstymo i lievus ir kietus trukme: " << Skirstymo_trukme/1000.0 << " s." << endl;
                break;
            } else if(norimas_rikiavimas == 4){
                auto Rusiavimo_pradzia = chrono::high_resolution_clock::now();
                sort(Studentai.begin(), Studentai.end(), palygintiPagalMediana);
                auto Rusiavimo_pabaiga = chrono::high_resolution_clock::now();
                auto Rusiavimo_trukme = chrono::duration_cast<chrono::milliseconds>(Rusiavimo_pabaiga - Rusiavimo_pradzia).count();
                cout << "Studentu rusiavimo didejant trukme: " << Rusiavimo_trukme/1000.0 << " s." << endl;

                auto Skirstymo_pradzia = chrono::high_resolution_clock::now();
                for(auto stud : Studentai){
                    if(stud.Get_Mediana() >= 5.0){
                        Kieti.push_back(stud);
                    }
                }
                PasalintiKietusStudentus(Studentai, norimas_rikiavimas);
                auto Skirstymo_pabaiga = chrono::high_resolution_clock::now();
                auto Skirstymo_trukme = chrono::duration_cast<chrono::milliseconds>(Skirstymo_pabaiga - Skirstymo_pradzia).count();
                cout << "Studentu Skirstymo i lievus ir kietus trukme: " << Skirstymo_trukme/1000.0 << " s." << endl;
                break;
            } 
            }
        }
    Kieti.shrink_to_fit();
    }

    if(norima_strategija == 1){
        IsvestiRezultatus("VisiStudentai", Studentai, norima_isvedimo_vieta);
        IsvestiRezultatus("Lievi", Studentai, norima_isvedimo_vieta);
        IsvestiRezultatus("Kieti", Kieti, norima_isvedimo_vieta);
    }
    if(norima_strategija == 2 || norima_strategija == 3){
        IsvestiRezultatus("Lievi", Studentai, norima_isvedimo_vieta);
        IsvestiRezultatus("Kieti", Kieti, norima_isvedimo_vieta);
    }
    
    system("pause");
    return 0;

    } catch(const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
}
