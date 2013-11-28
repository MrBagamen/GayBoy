#ifndef GAMEBOY_HPP
#define GAMEBOY_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

namespace gb {
    void loadROM(std::string filePath);
    void checkROMValid();
}

#endif // GAMEBOY_HPP
