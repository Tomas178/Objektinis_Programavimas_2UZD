# V1.0

- Visi tyrimai yra atlikti iš 5 bandymų.
### Naudojami sistemos parametrai
- CPU(Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz, 2400 Mhz, 2 branduolių, 4 loginiai procesoriai)
- RAM(16,0 GB)
- HDD(TOSHIBA MQ01ABD100 512GB)

### 1 Strategijos tyrimai 

                                                 1000 Studentų

|                       | Vector                     | List                          | Deque                         |
|-----------------------|----------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 0,0078s                    | 0,0132s                       | 0,017s                        |
| Studentų rūšiavimas = | 0,0016s                    | 0s                            | 0,0046s                       |
| Studentų skirstymas = | 0,0008s                    | 0,0092s                       | 0,0054s                       |

                                                 10000 Studentų

|                       | Vector                        | List                          | Deque                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 0,0648s                       | 0,1036s                       | 0,083s                        |
| Studentų rūšiavimas = | 0,0204s                       | 0,014s                        | 0,0508s                       |
| Studentų skirstymas = | 0,0198s                       | 0,0584s                       | 0,0308s                       |

                                                 100000 Studentų

|                       | Vector                        | List                          | Deque                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 0,478s                        | 0,764s                        | 0,599s                        |
| Studentų rūšiavimas = | 0,2404s                       | 0,1234s                       | 0,6058s                       |
| Studentų skirstymas = | 0,0998s                       | 0,4188s                       | 0,259s                        |

                                                 1000000 Studentų

|                       | Vector                        | List                          | Deque                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 4,16s                         | 7,7828s                       | 6,1738s                       |
| Studentų rūšiavimas = | 3,5234s                       | 1,8082s                       | 8,2234s                       |
| Studentų skirstymas = | 0,9028s                       | 4,4738s                       | 2,5364s                       |

                                                 10000000 Studentų

|                       | Vector                        | List                          | Deque                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 52,039s                       | 102,728s                      | 70,3016s                      |
| Studentų rūšiavimas = | 36,219s                       | 21,5344s                      | 93,503s                       |
| Studentų skirstymas = | 8,9612s                       | 58,242s                       | 42,3836s                      |

### 2 Strategijos tyrimai

                                                 1000 Studentų

|                       | Vector                     | List                          | Deque                         |
|-----------------------|----------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 0,0108s                    | 0,0156s                       | 0,0116s                       |
| Studentų rūšiavimas = | 0,0024s                    | 0s                            | 0,0174s                       |
| Studentų skirstymas = | 0,0006s                    | 0,0122s                       | 0,003s                        |

                                                 10000 Studentų

|                       | Vector                        | List                          | Deque                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 0,0474s                       | 0,1084s                       | 0,0768s                       |
| Studentų rūšiavimas = | 0,0152s                       | 0,0116s                       | 0,0562s                       |
| Studentų skirstymas = | 0,0122s                       | 0,095s                        | 0,0192s                       |

                                                 100000 Studentų

|                       | Vector                        | List                          | Deque                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 0,4068s                       | 0,7784s                       | 0,5756s                       |
| Studentų rūšiavimas = | 0,2334s                       | 0,1436s                       | 0,5958s                       |
| Studentų skirstymas = | 0,095s                        | 0,3678s                       | 0,2104s                       |

                                                 1000000 Studentų

|                       | Vector                        | List                          | Deque                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 3,9036s                       | 7,554s                        | 6,032s                        |
| Studentų rūšiavimas = | 3,5378s                       | 1,9044s                       | 8,1896s                       |
| Studentų skirstymas = | 0,8384s                       | 4,9178s                       | 2,1016s                       |

                                                 10000000 Studentų

|                       | Vector                        | List                          | Deque                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 51,466s                       | 98,927s                       | 67,8274s                      |
| Studentų rūšiavimas = | 37,2356s                      | 23,1012s                      | 94,4442s                      |
| Studentų skirstymas = | 8,6152s                       | 49,4404s                      | 21,478s                       |

# Instaliavimo instrukcija
- Jeigu neturite CMake, tuomet reikia atsisiųsti iš https://cmake.org/download/ ir instaliuojant programą pasirinkti, kad nustatytų sistemos kintamuosius arba galite žiūrėti šitą video: https://www.youtube.com/watch?v=8_X5Iq9niDE.
- Tuomet tam folderyje, raskite run.bat script'ą ir jums viska sutvarkys automatiškai.
- V1_0.exe failą rasite Debug folderyje, kuris atsiras po CMake įvykdymo.
