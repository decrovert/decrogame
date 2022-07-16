#include <memory>

#include <SFML/Graphics.hpp>

int main() {
    auto window = std::shared_ptr<sf::RenderWindow>(
        new sf::RenderWindow(sf::VideoMode(800, 600), "Decrogame", sf::Style::Default),
        [] (sf::Window* const window) {
            window->close();
            delete window;
        }
    );

    window->setFramerateLimit(60);

    auto smiling_cube_image = std::make_shared<sf::Texture>();
    
    if (!smiling_cube_image->loadFromFile("sprites/smiling_cube.png")) {
        // error
        return EXIT_FAILURE;
    }

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
