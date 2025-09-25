cmake_minimum_required(VERSION 4.0)
project(InheritanceLab)

set(CMAKE_CXX_STANDARD 20)

add_executable(InheritanceLab main.cpp
        BankAccountSystem.h
        BankAccountSystem.cpp)
