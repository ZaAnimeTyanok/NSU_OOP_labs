#ifndef LAB0_B_WORD_COUNTER_H
#define LAB0_B_WORD_COUNTER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

class WordCounter {

private:
    std::ifstream in_f;
    std::ofstream out_f;

    std::size_t word_count = 0;

    std::unordered_map<std::string, size_t> word_map;
    std::vector<std::string> word_arr;

    void quick_sort(size_t l, size_t r);

public:

    explicit WordCounter(const std::string& in_file = "in.txt", const std::string& out_file = "out.csv") {
        in_f.open(in_file);

        if (!in_f.is_open()) {
            std::cerr << "input file open error" << std::endl;
            exit(EXIT_FAILURE);

        }

        out_f.open(out_file);

        if (!out_f.is_open()) {
            std::cerr << "output file open error" << std::endl;
            exit(EXIT_FAILURE);

        }

    }

    void read_file();

    void write_to_file();

    ~WordCounter() {
        in_f.close();

        if (in_f.is_open()) {
            std::cerr << "output file close error" << std::endl;
            exit(EXIT_FAILURE);

        }

        out_f.close();

        if (out_f.is_open()) {
            std::cerr << "output file close error" << std::endl;
            exit(EXIT_FAILURE);

        }

        word_map.clear();

        word_arr.clear();

    }

};

#endif