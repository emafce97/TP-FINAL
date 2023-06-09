cmake_minimum_required(VERSION 3.25)
project(Ema C)

set(CMAKE_C_STANDARD 11)

add_executable(Ema main.c implementaciones.c headers.h implementaciones.c Menu.h)
