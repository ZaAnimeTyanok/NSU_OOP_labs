#include <iostream>
#include "../lib/word_counter/word_counter.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "wrong number of input arguments, need 3\nexample: a.exe in.txt out.csv";

        exit(EXIT_FAILURE);

    }

    try {
        WordCounter wordCounter(argv[1], argv[2]);
        wordCounter.get_stats();
    }

    catch (const reader_exception& err) {
        std::cout << "input file error : " << err.what() << std::endl;
    }
    
    catch (const writer_exception& err) {
        std::cout << "output file error : " << err.what() << std::endl;
    }

	return 0;

}
