cmake_minimum_required(VERSION 3.19)
project(Pro C)

set(CMAKE_C_STANDARD 99)

add_executable(Pro main.c Controller.c Controller.h GameLogic.c GameLogic.h)