# V1.2

- Visi tyrimai yra atlikti iš 5 bandymų.
- Visi failai turi po 7 namų darbus.
### Naudojami sistemos parametrai
- CPU(Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz, 2400 Mhz, 2 branduolių, 4 loginiai procesoriai)
- RAM(16,0 GB)
- HDD(TOSHIBA MQ01ABD100 512GB)

                                                 100000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 0,3592s                       | 0,3131s                       | 0,267s                        |
| Studentų rūšiavimas = | 0,0554s                       | 0,0958s                       | 0,0317s                       |
| Studentų skirstymas = | 0,056s                        | 0,0605s                       | 0,0333s                       |
| .exe failo dydis =    | 194Kb                         | 194Kb                         | 197Kb                         |

                                                 1000000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 4,127s                        | 2,6258s                       | 2,6665s                       |
| Studentų rūšiavimas = | 0,551s                        | 0,434s                        | 0,407s                        |
| Studentų skirstymas = | 0,6174s                       | 0,3862s                       | 0,3843s                       |
| .exe failo dydis =    | 194Kb                         | 194Kb                         | 197Kb                         |

                                                 10000000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 30,5662s                      | 26,4068s                      | 26,43s                        |
| Studentų rūšiavimas = | 15,4674s                      | 5,2982s                       | 5,0698s                       |
| Studentų skirstymas = | 5,0718s                       | 4,2642s                       | 4,3094s                       |
| .exe failo dydis =    | 194Kb                         | 194Kb                         | 197Kb                         |

## Aprašymas apie perdengtus metodus

### Įvesties perdengimo metodai
- Duomenų įvestis rankiniu ir automatiniu būdu įvyksta, kai duomenų skaitymui yra naudojamas istream objektas (šios programos atveju cin), o tada žiūrima pagal vartotojo pasirinkta programos veikimą. 
    - Jei programos_veikimas == 1, tai rankiniu būdu.
    - Jei programos_veikimas == 2, tai vardą ir pavardę rankiniu būdu, o pažymiai yra sugeneruojami.
    - Jei programos_veikimas == 3, tai studentų yra sugeneruojama tiek, kiek nori vartotojas.
- Duomenų įvestis iš failo įvyksta, kai duomenų skaitymui naudojamas `istringstream` objektas.

### Išvesties perdengimo metodai
- Duomenų išvedimas per konsolę įvyksta, kai duomenų išvedimui yra naudojamas `ostream` objektas (Šios programos atveju cout).
- Duomenų išvedimas į failą įvyksta, kai duomenų išvedimui yra naudojamas `ofstream` objektas. 

# Instaliavimo instrukcija
- Jeigu neturite CMake, tuomet reikia atsisiųsti iš https://cmake.org/download/ ir instaliuojant programą pasirinkti, kad nustatytų sistemos kintamuosius arba galite žiūrėti šitą video: https://www.youtube.com/watch?v=8_X5Iq9niDE.
- Taip pat reikės atsisiųsti googletest darant šiuos žingsnius folderyje: 
    - git clone https://github.com/google/googletest.git
    - cd googletest        # Main directory of the cloned repository.
    - mkdir build          # Create a directory to hold the build output.
    - cd build
    - cmake ..             # Generate native build scripts for GoogleTest.
- Tuomet build folder'yje turėtu atsirasti libgtest.a ir libgtest_main.a failai ir tada žiūrėkite į CMakeLists.txt ir nustatykite kelią iki tų failų pagal savo failų lokaciją.
- Tuomet tam folderyje, raskite run.bat script'ą ir jums viska sutvarkys automatiškai.
- V2_0_Vector.exe failą rasite Debug folder'yje, o Testas.exe rasite Testavimo_rezultatai folder'yje, kurie atsiras po CMake įvykdymo.