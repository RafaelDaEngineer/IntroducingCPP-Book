cmake_minimum_required(VERSION 4.2)
project(IntroToCPPBook)

set(CMAKE_CXX_STANDARD 23)

add_executable(IntroToCPPBook
        analysis.cpp
        analysis.h
        input.cpp
        input.h
        stock.h
        main.cpp
)
