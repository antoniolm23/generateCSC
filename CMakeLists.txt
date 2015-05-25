cmake_minimum_required(VERSION 2.6)
project(modify_csc)

add_executable(modify_csc main.cpp)

install(TARGETS modify_csc RUNTIME DESTINATION bin)
