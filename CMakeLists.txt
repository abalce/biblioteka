cmake_minimum_required(VERSION 3.27)
project(bibloteczka)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bibloteczka
        bib.h
        main.cpp)
