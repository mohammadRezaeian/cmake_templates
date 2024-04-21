cmake_minimum_required(VERSION 3.5)

project(checkCXX LANGUAGES CXX)

add_executable(checkCXX main.cpp)

include(CheckCXXSourceCompiles)

check_cxx_source_compiles("
    struct A {int a; };
    int main() { A { .a = 20 }; }
" have_cpp17 )

message(FATAL_ERROR ${have_cpp20})
