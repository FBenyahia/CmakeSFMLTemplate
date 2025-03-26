#include <SFML/Graphics.hpp>
#include <configuration.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({conf::window_size.x, conf::window_size.y}), "CMake SFML Template");
    window.setFramerateLimit(conf::max_framerate);

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
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) window.close();
            }
        }

        window.clear();

        sf::CircleShape c{ 100.0f };
        c.setFillColor(sf::Color::Red);
        window.draw(c);
        window.display();
    }

}
