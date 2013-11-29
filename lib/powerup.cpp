#include <array>
#include "gayboy.hpp"

namespace gb {
    namespace {
        bool compareLogo() {
            std::array<unsigned char, 48> logo {
                0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 
                0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
                0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E,
                0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
                0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC,
                0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
            };
            return std::equal(logo.begin(), logo.end(), rom.begin() + 0x104);
        }
        bool validateHeaderChecksum() {
            unsigned short sum = 0;
            for (int i = 0x134; i <= 0x14d; ++i)
                sum += rom[i];
            sum += 25;
            return reinterpret_cast<unsigned char*>(&sum)[0] == 0;
        }
    }
    void powerup() {
        if (!compareLogo())
            throw std::runtime_error("Logo comparison failed. Invalid or corrupted ROM.");
        if (!validateHeaderChecksum())
            throw std::runtime_error("Header checksum failed. Invalid or corrupted ROM.");
    }
}
