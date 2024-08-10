cmake_minimum_required(VERSION 3.12)
project(cpptestdata)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
find_package(date CONFIG REQUIRED)
add_executable(cpptestdata src/main.cpp)
add_executable(date1 src/date1.cpp)
target_link_libraries(cpptestdata date-tz)
add_executable(cpptestdata2 src/date.cpp)
target_link_libraries(cpptestdata2 date-tz)
target_link_libraries(date1 date-tz)



#-- Using Conan toolchain: /Users/ibqo/Develop/git/github/cpptestdata/build/Debug/generators/conan_toolchain.cmake
#-- Conan toolchain: C++ Standard 17 with extensions ON
#-- Conan: Component target declared 'date::date-tz'
#-- Conan: Target declared 'date::date'
#-- Conan: Component target declared 'CURL::libcurl'
#-- Conan: Target declared 'ZLIB::ZLIB'
#-- Configuring done
#-- Generating done
