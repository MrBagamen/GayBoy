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
        auto elapsedMilliseconds = clock.getElapsedTime().asMilliseconds();
        for (int y = 0; y < 144; ++y)
            for (int x = 0; x < 160; ++x) {
                int i = y * (160 * 4) + x * 4;
                sf::Uint8 &r = pixels[i], &g = pixels[i + 1], &b = pixels[i + 2], &a = pixels[i + 3];
                r = g = b = (y ^ x) + elapsedMilliseconds;
                a = 255;
            }
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
