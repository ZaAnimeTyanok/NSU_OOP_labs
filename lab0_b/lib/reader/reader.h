#pragma once

#include <iostream>
#include <fstream>
#include <exception>

class reader_exception : public std::exception {
public:
    reader_exception(const std::string& ms) : message(ms) {};

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;

};

class Reader {
public:

    explicit Reader(const std::string& in_file = "in.txt") {
        input_file.open(in_file);

        if (!input_file.is_open()) {
            throw reader_exception("the file does not open");
        }

    }

    bool get_word(std::string& word);

    ~Reader() {
        input_file.close();

        if (input_file.is_open()) {
            throw reader_exception("the file does not close");
        }

    }

private:
    std::ifstream input_file;

};