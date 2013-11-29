#ifndef GAMEBOY_HPP
#define GAMEBOY_HPP

#include <string>
#include <vector>

namespace gb {
    void loadROM(std::string filePath);
    void powerup();
    extern std::vector<unsigned char> rom, ram, vram;
}

#endif // GAMEBOY_HPP
