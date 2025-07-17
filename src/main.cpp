#include <SFML/Graphics.hpp>
#include <configuration.h>

#include "renderer.h"

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    auto window = sf::RenderWindow(sf::VideoMode({conf::window_size.x, conf::window_size.y}), "CMake SFML Template", sf::State::Windowed, settings);
    window.setFramerateLimit(conf::max_framerate);

    Renderer renderer(window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            };

            if (event->is<sf::Event::KeyPressed>())
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();
            }
        }

        window.clear();
        
        renderer.render();
        window.display();
    }

}
