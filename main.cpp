#include "gameboy.hpp"

int main(int argc, char ** argv) {
    gb::loadROM(argc > 1 ? argv[1] : "roms/Kirby's Dream Land.gb");
    return EXIT_SUCCESS;
}
