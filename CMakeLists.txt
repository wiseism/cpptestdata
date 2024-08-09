cmake_minimum_required(VERSION 3.12)
project(cpptestdata)

set(CMAKE_CXX_STANDARD 11)
find_package(data CONFIG REQUIRED)
add_executable(cpptestdata src/main.cpp)
target_link_libraries(cpptestdata data::data)
add_executable(cpptestdata2 src/data.cpp)
target_link_libraries(cpptestdata2 data::data)