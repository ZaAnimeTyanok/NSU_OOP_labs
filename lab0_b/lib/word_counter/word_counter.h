#pragma once

#include "../reader/reader.h"
#include "../writer/writer.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class WordCounter {
public:
    explicit WordCounter(const std::string& in_file = "in.txt", const std::string& out_file = "out.csv") : in_f(in_file), out_f(out_file) {}

    ~WordCounter() {
        word_map.clear();
        word_arr.clear();

    }

    void get_stats();

private:
    std::string in_f;
    std::string out_f;
    std::map<std::string, size_t> word_map;
    std::vector<std::string> word_arr;
    std::size_t word_count = 0;


    void get_input_data();

    void sort_data();

    void stats_to_outf();
};