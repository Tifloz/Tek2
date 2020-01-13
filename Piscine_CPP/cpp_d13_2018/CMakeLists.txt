cmake_minimum_required(VERSION 3.9)
project(cpp_d13_2018)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE INCL *.hpp)
include_directories(include)

add_executable(my_rpg
        ${SRCS}
        ${INCL})