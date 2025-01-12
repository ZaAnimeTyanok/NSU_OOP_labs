#include "word_counter.h"

void WordCounter::get_stats() {
    get_input_data();
    sort_data();
    stats_to_outf();

}

void WordCounter::get_input_data() {
    Reader reader(in_f);

    std::string word;

    while (reader.get_word(word)) {
        size_t w_size = word.size();

        for (size_t i = 0; i < w_size; i++) {
            if (isalnum(word[i])) {
                word[i] = tolower(word[i]);
            }

            else {
                word.erase(i, 1);
                i--;
                w_size--;
            }

        }

        if (!word.empty()) {
            word_count++;
            if (!word_map[word]++) word_arr.push_back(word);

        }

    }

}

void WordCounter::sort_data() {
    if (!word_arr.empty()) {
        std::sort(word_arr.begin(), word_arr.end(),

            [this](std::string word1, std::string word2) {
                return word_map[word1] < word_map[word2];
            }

        );

    }

}

void WordCounter::stats_to_outf() {
    Writer writer(out_f);
    size_t n = word_arr.size();

    for (size_t i = 0; i < n; i++) {
        double percent = (double)word_map[word_arr[n - i - 1]] / (double)word_count * 100;

        *writer.output_stream() << word_arr[n - i - 1] << ';' << word_map[word_arr[n - i - 1]] << ';' << percent << "%" << std::endl;

    }

}
