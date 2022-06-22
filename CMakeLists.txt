cmake_minimum_required(VERSION 3.21)
project(PasswordManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(PasswordManager main.cpp
                Password.cpp
                Password.h
                Manager.cpp
                Manager.h
        )
