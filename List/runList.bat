cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ .
cmake --install .
cmake --build .
mkdir DebugList
copy Sources\*.txt DebugList\*.txt
cd DebugList
V1_0_List.exe