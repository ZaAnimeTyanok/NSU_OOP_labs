#pragma once

#include <iostream>
#include <fstream>
#include <exception>

class writer_exception : public std::exception {
public:
    writer_exception(const std::string& ms) : message(ms) {};

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;

};

class Writer {
public:
    explicit Writer(const std::string& out_file = "out.csv") {
        output_file.open(out_file);

        if (!output_file.is_open()) {
            throw writer_exception("the file does not open");
        }

    }

    std::ofstream* output_stream();

    ~Writer() {
        output_file.close();

        if (output_file.is_open()) {
            throw writer_exception("the file does not close");
        }

    }

private:
    std::ofstream output_file;

};