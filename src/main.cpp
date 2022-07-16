#include <memory>

#include <SFML/Graphics.hpp>

#include "Logger.hpp"

int main() {
    auto logger = std::make_shared<Decrogame::Logger>("Decrogame.log");

    auto window = std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(
        sf::VideoMode(800, 600),
        "Decrogame",
        sf::Style::Default
    ));

    window->setFramerateLimit(60);

    auto smiling_cube_image = std::make_shared<sf::Texture>();
    smiling_cube_image->loadFromFile("sprites/smiling_cube.png");

    auto smiling_cube_sprite = std::make_shared<sf::Sprite>();
    smiling_cube_sprite->setTexture(*smiling_cube_image);

    while (window->isOpen()) {
        sf::Event event;
        
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear();
        
        window->draw(*smiling_cube_sprite);
        
        window->display();
    }

    return EXIT_SUCCESS;
}
