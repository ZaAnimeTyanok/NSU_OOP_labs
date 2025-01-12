#include "writer.h"

std::ofstream* Writer::output_stream() {
    return  &output_file;
}
