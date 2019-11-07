cmake_minimum_required(VERSION 3.15)
project(options C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(options
		options.c
		options.h)
