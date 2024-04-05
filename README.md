# V1.1

- Visi tyrimai yra atlikti iš 5 bandymų.
- Visi failai turi po 7 namų darbus.
### Naudojami sistemos parametrai
- CPU(Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz, 2400 Mhz, 2 branduolių, 4 loginiai procesoriai)
- RAM(16,0 GB)
- HDD(TOSHIBA MQ01ABD100 512GB)

### TYRIMŲ REZULTATAI SU STRUCT
                                                 100000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 0,286667s                     | 0,295667s                     | 0,326667s                     |
| Studentų rūšiavimas = | 0,01s                         | 0,009333s                     | 0,013333s                     |
| Studentų skirstymas = | 0,044333s                     | 0,047333s                     | 0,041667s                     |
| .exe failo dydis =    | 214Kb                         | 204Kb                         | 230Kb                         |

                                                 1000000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 2,852333s                     | 2,983333s                     | 2,785333s                     |
| Studentų rūšiavimas = | 0,102s                        | 0,170667s                     | 0,103s                        |
| Studentų skirstymas = | 0,432333s                     | 0,401s                        | 0,338333s                     |
| .exe failo dydis =    | 214Kb                         | 204Kb                         | 230Kb                         |

                                                 10000000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 27,665s                       | 27,487s                       | 27,12333s                     |
| Studentų rūšiavimas = | 1,0515s                       | 1,145s                        | 1,057333s                     |
| Studentų skirstymas = | 3,6785s                       | 3,617667s                     | 4,127s                        |
| .exe failo dydis =    | 214Kb                         | 204Kb                         | 230Kb                         |

### TYRIMŲ REZULTATAI SU CLASS
                                                 100000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 0,3567s                       | 0,372s                        | 0,3472s                       |
| Studentų rūšiavimas = | 0,1302s                       | 0,1316s                       | 0,1362s                       |
| Studentų skirstymas = | 0,0748s                       | 0,0606s                       | 0,065s                        |
| .exe failo dydis =    | 203Kb                         | 197Kb                         | 207Kb                         |

                                                 1000000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 3,2986s                       | 3,554667s                     | 3,3614s                       |
| Studentų rūšiavimas = | 1,6696s                       | 2,137667s                     | 2,076s                        |
| Studentų skirstymas = | 0,7604s                       | 0,861333s                     | 0,8094s                       |
| .exe failo dydis =    | 203Kb                         | 197Kb                         | 207Kb                         |

                                                 10000000 Studentų

|                       | -O1                           | -O2                           | -O3                           |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 27,6668s                      | 31,9894s                      | 27,0716s                      |
| Studentų rūšiavimas = | 17,6838s                      | 17,8376s                      | 16,5052s                      |
| Studentų skirstymas = | 4,693s                        | 5,0644s                       | 4,5088s                       |
| .exe failo dydis =    | 203Kb                         | 197Kb                         | 207Kb                         |

# Instaliavimo instrukcija
- Jeigu neturite CMake, tuomet reikia atsisiųsti iš https://cmake.org/download/ ir instaliuojant programą pasirinkti, kad nustatytų sistemos kintamuosius arba galite žiūrėti šitą video: https://www.youtube.com/watch?v=8_X5Iq9niDE.
- Tuomet tam folderyje, raskite run.bat script'ą ir jums viska sutvarkys automatiškai.
- V1_1_Vector.exe failą rasite Debug folderyje, kuris atsiras po CMake įvykdymo.