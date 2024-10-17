#include "word_counter.h"
//#include "memchek.h"      // <- using for detect memory leaks in vs

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "error: incorrect number of arguments" << std::endl;

        return 0;

    }

    WordCounter* wordCounter = new WordCounter(argv[1], argv[2]);
    
    (*wordCounter).read_file();
    (*wordCounter).write_to_file();
    
    delete wordCounter;
    
    //check_memory();       // <- using for detect memory leaks in vs
    
    return 0;

}

