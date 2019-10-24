cmake_minimum_required(VERSION 3.15)
project(flood_fill C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(flood_fill
		flood_fill.c
		flood_fill.h)
