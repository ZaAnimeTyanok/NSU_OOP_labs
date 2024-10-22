add_library(wc_lib
    ./word_counter/word_counter.cpp
    ./word_counter/word_counter.h
)

add_library(mc_lib
    ./memcheck/memcheck.cpp
    ./memcheck/memcheck.h
)

set_target_properties(wc_lib mc_lib PROPERTIES LINKER_LANGUAGE CXX)