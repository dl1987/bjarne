cmake_minimum_required(VERSION 3.12)
project(bjarne_calculator)
add_executable(calculator main.cpp Token.hpp Token.cpp TokenStream.hpp TokenStream.cpp ../std_lib/std_lib_facilities.h)
