cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ .
cmake --install .
cmake --build .
copy Sources\*.txt DebugVector\*.txt
cd DebugVector
V1_5_Vector.exe