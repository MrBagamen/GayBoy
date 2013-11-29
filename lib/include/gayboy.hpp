#ifndef GAMEBOY_HPP
#define GAMEBOY_HPP

#include <string>
#include <vector>
#include <array>

namespace gb {
    void loadROM(std::string filePath);
    void powerup();
    extern std::vector<unsigned char> rom;
    extern std::array<unsigned char, 8192> ram, vram;
}

#endif // GAMEBOY_HPP
