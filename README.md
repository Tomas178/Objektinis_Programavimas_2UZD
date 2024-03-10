# V1.0

- Visi tyrimai yra atlikti iš 5 bandymų.
### Naudojami sistemos parametrai
- CPU(Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz, 2400 Mhz, 2 branduolių, 4 loginiai procesoriai)
- RAM(16,0 GB)
- HDD(TOSHIBA MQ01ABD100 512GB)

### Tyrimai

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
