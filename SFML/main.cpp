#include "gameboy.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char ** argv) {
    gb::loadROM(argc > 1 ? argv[1] : "roms/Kirby's Dream Land.gb");
    sf::RenderWindow window(sf::VideoMode(160, 144), "GayBoy");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
}
