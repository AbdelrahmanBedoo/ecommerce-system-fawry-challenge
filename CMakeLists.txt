cmake_minimum_required(VERSION 3.16)
project(ecommerce_system_fawry_challenge)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "main.cpp")

add_executable(ecommerce_system_fawry_challenge ${SOURCES})

# Add include directories
target_include_directories(ecommerce_system_fawry_challenge PRIVATE src)