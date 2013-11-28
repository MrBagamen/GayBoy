#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace {
    std::size_t getFileSize(std::ifstream & file) {
        auto p = file.tellg();
        file.seekg(std::ios::end);
        auto size = file.tellg();
        file.seekg(p, std::ios::beg);
        return static_cast<size_t>(size);
    }
}

int main(int argc, char ** argv) {
    std::string filename = argc > 1 ? argv[1] : "roms/marioland.gb";
    std::ifstream file;
    file.exceptions(std::ios::failbit | std::ios::badbit);
    try {
        file.open(filename, std::ios::binary);
    } catch (std::exception const & e) {
        std::cerr << "Failed at opening the file " << filename << std::endl;
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    auto fSize = getFileSize(file);
    std::vector<char> buffer(fSize);
    file.read(buffer.data(), buffer.size());
    return EXIT_SUCCESS;
}
