cmake_minimum_required(VERSION 3.25)
project(V2_0_Vector)

# Pasikeisti pagal savo direktoriją iki failų
set(GTEST_LIBRARY "C:/msys64/mingw64/lib/libgtest.a")
set(GTEST_MAIN_LIBRARY "C:/msys64/mingw64/lib/libgtest_main.a")
set(GTEST_INCLUDE_DIR "C:/msys64/mingw64/include/gtest")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
include_directories(Headers)

file(GLOB SOURCES "Sources/Vector_v2_0.cpp")
file(GLOB FUNKCIJOS "Sources/funkcijos.cpp")
# file(GLOB PROGRAMOS_TESTAVIMAS "Testavimas/Testavimas.cpp")
file(GLOB VEKTORIAUS_TESTAVIMAS "Testavimas/Vektoriaus_Testavimas.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/DebugVector)

# Galima rinktis tarp -O1, -O2, -O3
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(${PROJECT_NAME} ${SOURCES} ${FUNKCIJOS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Testavimo_Rezultatai)

# add_executable(Programos_Testas ${PROGRAMOS_TESTAVIMAS} ${FUNKCIJOS})

# target_link_libraries(Programos_Testas ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})

add_executable(Vektoriaus_Testas ${VEKTORIAUS_TESTAVIMAS})

target_link_libraries(Vektoriaus_Testas ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
