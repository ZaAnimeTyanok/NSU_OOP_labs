#include "word_counter.h"

void WordCounter::quick_sort(size_t l, size_t r) {
    size_t x = word_map[word_arr[(l + r) / 2]];
    size_t i = l;
    size_t j = r;

    while (i <= j) {
        while (word_map[word_arr[i]] < x) i++;

        while (word_map[word_arr[j]] > x) j--;

        if (i <= j) {
            std::string w = word_arr[i];
            word_arr[i] = word_arr[j];
            word_arr[j] = w;

            i++;
            j--;

        }

    }

    if (l < j) quick_sort(l, j);

    if (i < r) quick_sort(i, r);

}

void WordCounter::read_file() {
    std::string word;

    while (in_f >> word) {
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

    quick_sort(0, word_arr.size() - 1);

}

void WordCounter::write_to_file() {
    size_t n = word_arr.size();
    
    for (size_t i = 0; i < n; i++) {
        double perc = (double)word_map[word_arr[n - i - 1]] / (double)word_count * 100;

        out_f << word_arr[n - i - 1] << " " << word_map[word_arr[n - i - 1]] << " " << perc << "%" << std::endl;

    }

}
