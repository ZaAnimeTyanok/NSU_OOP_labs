add_library(ba_lib
    ./bitarray/bitarray.cpp
    ./bitarray/bitarray.h
)

set_target_properties(ba_lib PROPERTIES LINKER_LANGUAGE CXX)