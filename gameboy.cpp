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
    std::vector<unsigned char> rom, ram, vram;
    unsigned char n_logo[] = {
        0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
        0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
        0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
    };

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
        file.read(reinterpret_cast<char*>(gb::rom.data()), gb::rom.size());
        std::cout << "Size of rom: " << gb::rom.size() / 1024 << "KB" << std::endl;
    }

    void checkROMValid() {
        int cv = 0;
        for(unsigned char i = 0; i < 48; i++) {
            if(gb::rom.at(0x0104+i) == n_logo[i]) {
                cv++;
            }
        }
        if(cv != 48)
        {
            std::cout << "Not gameboy rom" << std::endl;
        }
        else
        {
            std::cout << "This rom is valid" << std::endl;
        }
    }
}
