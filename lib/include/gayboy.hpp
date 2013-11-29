#ifndef GAMEBOY_HPP
#define GAMEBOY_HPP

#include <string>
#include <vector>
#include <array>
#include <cstdint>

namespace gb {
    typedef uint8_t  byte;
    typedef uint16_t word;

    void loadROM(std::string filePath);
    void powerup();
    extern std::vector<byte> rom;
    extern std::array<byte, 8192> ram, vram;
    namespace cpu {
        extern word af;     // Accumulator & flags
        extern byte &a;     // Accumulator
        extern byte &flags; // Flags
        extern word bc;
        extern byte &b; 
        extern byte &c;
        extern word de;
        extern byte &d;
        extern byte &e;
        extern word hl;
        extern byte &h;
        extern byte &l;
        extern word sp;     // Stack pointer
        extern word pc;     // Program counter
    }
}

#endif // GAMEBOY_HPP
