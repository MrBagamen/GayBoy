#include "gayboy.hpp"
#include <iostream>
#include <fstream>

namespace {
    std::size_t getFileSize(std::ifstream & file) {
        file.seekg(0, std::ios::end);
        size_t size = file.tellg();
        file.seekg(0, std::ios::beg);
        return size;
    }
}

namespace gb {
    unsigned char carttype;
    void cartridgeType() {
        carttype = rom.at(0x0147);
        printf("Cart type: %02x\n", carttype);
    }
    void loadROM(std::string filePath) {
        std::ifstream file;
        file.exceptions(std::ios::failbit | std::ios::badbit);
        try {
            file.open(filePath, std::ios::binary);
        } catch (std::exception const & e) {
            std::cerr << "Failed at opening the file " << filePath << std::endl;
            std::cerr << "Error: " << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }
        rom.resize(getFileSize(file));
        file.read(reinterpret_cast<char*>(rom.data()), rom.size());
        std::cout << "Loaded " << filePath << std::endl;
        std::cout << "Size of rom: " << rom.size() / 1024 << "KiB" << std::endl;
        
        cartridgeType();
    }
}
