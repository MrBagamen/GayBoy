#include "gayboy.hpp"

namespace gb {
    std::vector<byte> rom;
    std::array<byte, 8192> ram, vram;
    
    namespace cpu {
        word af;
        byte &a = reinterpret_cast<byte*>(&af)[1];
        byte &flag = reinterpret_cast<byte*>(&af)[0];
        word bc;
        byte &b = reinterpret_cast<byte*>(&bc)[1];
        byte &c = reinterpret_cast<byte*>(&bc)[0];
        word de;
        byte &d = reinterpret_cast<byte*>(&de)[1];
        byte &e = reinterpret_cast<byte*>(&de)[0];
        word hl;
        byte &h = reinterpret_cast<byte*>(&hl)[1];
        byte &l = reinterpret_cast<byte*>(&hl)[0];
        word sp;
        word pc;
    }
}
