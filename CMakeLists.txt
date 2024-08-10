cmake_minimum_required(VERSION 3.12)
project(cpptestdata)

set(CMAKE_CXX_STANDARD 11)
find_package(date CONFIG REQUIRED)
add_executable(cpptestdata src/main.cpp)
target_link_libraries(cpptestdata date::date)
add_executable(cpptestdata2 src/data.cpp)
target_link_libraries(cpptestdata2 date::date)