cmake_minimum_required(VERSION 3.25)
project(V2_0_Vector)
include_directories(Headers)
file(GLOB SOURCES "Sources/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/DebugVector)

# Cia galite keisti optimizavimo flag'us pasirenkart tarp (-O1, -O2, -O3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(${PROJECT_NAME} ${SOURCES})
