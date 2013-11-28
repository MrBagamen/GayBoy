#include "gameboy.hpp"

int main(int argc, char ** argv) {
    gb::loadROM(argc > 1 ? argv[1] : "roms/marioland.gb");
    return EXIT_SUCCESS;
}
