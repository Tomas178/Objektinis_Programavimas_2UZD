cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ .
cmake --install .
cmake --build .
mkdir DebugDeque
copy Sources\*.txt DebugDeque\*.txt
cd DebugDeque
V1_0_Deque.exe