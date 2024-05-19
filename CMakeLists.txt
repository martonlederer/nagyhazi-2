cmake_minimum_required(VERSION 3.26)
project(nagyhazi_2)

set(CMAKE_CXX_STANDARD 11)

set(CXXFLAGS  "-Wall -Werror -DMEMTRACE")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

add_executable(nagyhazi_2 main.cpp
        string.cpp
        string.h
        gtest_lite.h
        PhoneNumber.h
        Name.h
        Contact.h
        List.hpp
        PhoneNumber.cpp
        Name.cpp
        Loader.cpp
        memtrace.h
        memtrace.cpp
)
