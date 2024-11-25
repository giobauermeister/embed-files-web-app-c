# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(SimpleServer C)

# Add compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")

# Specify the target executable and source files
add_executable(SimpleServer src/main.c)

# Optionally, set the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)