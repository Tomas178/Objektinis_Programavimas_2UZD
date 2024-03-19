cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ .
cmake --install .
cmake --build .
mkdir Debug
copy Sources\*.txt Debug\*.txt
cd Debug
V1_0.exe