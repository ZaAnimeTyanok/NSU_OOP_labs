#include "reader.h"

bool Reader::get_word(std::string& word) {
    if (input_file >> word) {
        return 1;
    }

    return 0;

}


