#include "gameboy.hpp"
#include <SFML/Graphics.hpp>
#include <array>

int main(int argc, char ** argv) {
    gb::loadROM(argc > 1 ? argv[1] : "roms/Kirby's Dream Land.gb");
    sf::RenderWindow window(sf::VideoMode(160, 144), "GayBoy");
    sf::Texture display;
    display.create(160, 144);
    int frames = 0;
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::array<sf::Uint8, 160 * 144 * 4> pixels;
        for (decltype(pixels)::size_type i = 0; i < pixels.size(); ++i)
            pixels[i] = rand();
        display.update(pixels.data());
        window.draw(sf::Sprite(display));
        window.display();
        ++frames;
        if (clock.getElapsedTime() >= sf::seconds(1.0f)) {
            clock.restart();
            window.setTitle("GayBoy running at " + std::to_string(frames) + " fps");
            frames = 0;
        }
    }
}
