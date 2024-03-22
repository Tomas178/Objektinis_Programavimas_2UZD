cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ .
cmake --install .
cmake --build .
mkdir DebugVector
copy Sources\*.txt DebugVector\*.txt
cd DebugVector
V1_0_Vector.exe