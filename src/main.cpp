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

    while (window->isOpen()) {
        sf::Event event;
        
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear();
        window->display();
    }

    return EXIT_SUCCESS;
}
