# V1.1

- Visi tyrimai yra atlikti iš 5 bandymų.
- Visi failai turi po 7 namų darbus.
### Naudojami sistemos parametrai
- CPU(Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz, 2400 Mhz, 2 branduolių, 4 loginiai procesoriai)
- RAM(16,0 GB)
- HDD(TOSHIBA MQ01ABD100 512GB)

### TYRIMŲ REZULTATAI
                                                 100000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 0,3567s                       | 0,372s                        | 0,3472s                       |
| Studentų rūšiavimas = | 0,1302s                       | 0,1316s                       | 0,1362s                       |
| Studentų skirstymas = | 0,0748s                       | 0,0606s                       | 0,065s                        |

                                                 1000000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 3,2986s                       | 3,554667s                     | 3,3614s                       |
| Studentų rūšiavimas = | 1,6696s                       | 2,137667s                     | 2,076s                        |
| Studentų skirstymas = | 0,7604s                       | 0,861333s                     | 0,8094s                       |

                                                 10000000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 27,6668s                      | 31,9894s                      | 27,0716s                      |
| Studentų rūšiavimas = | 17,6838s                      | 17,8376s                      | 16,5052s                      |
| Studentų skirstymas = | 4,693s                        | 5,0644s                       | 4,5088s                       |

# Instaliavimo instrukcija
- Jeigu neturite CMake, tuomet reikia atsisiųsti iš https://cmake.org/download/ ir instaliuojant programą pasirinkti, kad nustatytų sistemos kintamuosius arba galite žiūrėti šitą video: https://www.youtube.com/watch?v=8_X5Iq9niDE.
- Tuomet tam folderyje, raskite run.bat script'ą ir jums viska sutvarkys automatiškai.
- V1_1_Vector.exe failą rasite Debug folderyje, kuris atsiras po CMake įvykdymo.