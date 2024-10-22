cmake_minimum_required(VERSION 3.16)
project(lab0_b)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab0_b src/main.cpp src/word_counter.h src/word_counter.cpp  "src/memchek.h" "src/memchek.cpp")