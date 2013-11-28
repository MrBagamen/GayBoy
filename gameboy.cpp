#include "gameboy.hpp"

namespace {
    std::size_t getFileSize(std::ifstream & file) {
        file.seekg(0, std::ios::end);
        size_t size = file.tellg();
        file.seekg(0, std::ios::beg);
        return size;
    }
}

namespace gb {
    std::vector<char> rom, ram, vram;

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
        std::cout << "Loaded " << filePath << std::endl;
        gb::rom.resize(getFileSize(file));
        file.read(gb::rom.data(), gb::rom.size());
        std::cout << "Size of rom: " << gb::rom.size() / 1024 << "KB" << std::endl;
        //fak printing hex
        /*for(unsigned int i = 0; i < gb::rom.size(); i++) {
            std::cout << std::hex << static_cast<int>(gb::rom.at(i)) << " ";
        }
        std::cout << std::endl;*/
    }
}
