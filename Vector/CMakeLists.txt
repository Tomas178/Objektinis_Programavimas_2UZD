cmake_minimum_required(VERSION 3.25)
project(V2_0_Vector)

# Set the path to the Google Test libraries and includes
set(GTEST_LIBRARY "C:/msys64/mingw64/lib/libgtest.a")
set(GTEST_MAIN_LIBRARY "C:/msys64/mingw64/lib/libgtest_main.a")
set(GTEST_INCLUDE_DIR "C:/msys64/mingw64/include/gtest")

# Locate and include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
include_directories(Headers)

file(GLOB SOURCES "Sources/Vector_v2_0.cpp")
file(GLOB FUNKCIJOS "Sources/funkcijos.cpp")
file(GLOB TESTAVIMAS "Testavimas/*.cpp")

# Set the output directory for your executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/DebugVector)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

# Create the main executable
add_executable(${PROJECT_NAME} ${SOURCES} ${FUNKCIJOS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Testavimo_Rezultatai)

# Create the test executable
add_executable(Testas ${TESTAVIMAS} ${FUNKCIJOS})

# Link Google Test libraries with the test executable
target_link_libraries(Testas ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
