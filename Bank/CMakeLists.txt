cmake_minimum_required(VERSION 3.26)
project(Bank)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bank main.cpp
        model/Date.cpp
        model/Date.h
        model/Account.cpp
        model/Account.h
        model/Accumulator.cpp
        model/Accumulator.h)
