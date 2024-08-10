# README

date/3.0.1


## mac 
git clone https://github.com/HowardHinnant/date.git
cd date
git checkout v3.0.1
mkdir build
cd build
cmake -DENABLE_DATE_TESTING=ON -DBUILD_TZ_LIB=OFF -DBUILD_SHARED_LIBS=ON -DUSE_TZ_DB_IN_DOT=ON ../
cmake --build .
cmake --install .

-- Install configuration: ""
-- Installing: /usr/local/include/date/date.h
-- Installing: /usr/local/lib/libdate-tz.a
-- Installing: /usr/local/include/date/tz.h
-- Installing: /usr/local/lib/cmake/date/dateTargets.cmake
-- Installing: /usr/local/lib/cmake/date/dateTargets-noconfig.cmake
-- Installing: /usr/local/lib/cmake/date/dateConfig.cmake
-- Installing: /usr/local/lib/cmake/date/dateConfigVersion.cmake


set(CMAKE_CXX_STANDARD 17)
可以
set(CMAKE_CXX_STANDARD 11)
报错：Undefined symbols for architecture x86_64:
"date::locate_zone(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&)", referenced from:
_main in date.cpp.o
ld: symbol(s) not found for architecture x86_64