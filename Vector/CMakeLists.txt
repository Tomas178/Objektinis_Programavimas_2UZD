cmake_minimum_required(VERSION 3.25)
project(V1_0_Vector)
include_directories(Headers)
file(GLOB SOURCES "Sources/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/DebugVector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")

add_executable(${PROJECT_NAME} ${SOURCES})