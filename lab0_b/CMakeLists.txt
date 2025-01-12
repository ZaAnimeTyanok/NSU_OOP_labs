cmake_minimum_required(VERSION 3.16)
project(Lab0_b_project)  

set(CMAKE_CXX_STANDARD 20)  

add_executable (lab0_b "bin/main.cpp" "lib/word_counter/word_counter.h" "lib/reader/reader.h" "lib/reader/reader.cpp" "lib/word_counter/word_counter.cpp" "lib/writer/writer.h" "lib/writer/writer.cpp")
