#pragma once
#include "SFML/Graphics.hpp"


class Renderer
{
public:
    explicit
    Renderer(sf::RenderTarget& target)
        : m_target{target}
    {

    }

    void render()
    {

        sf::CircleShape circle{1.0f};
        circle.setPointCount(32);
        circle.setOrigin({1.0f, 1.0f});
        circle.setPosition({10.0f, 10.0f});
        circle.setScale({25.0f,25.0f});
        circle.setFillColor(sf::Color::White);
        m_target.draw(circle);
    }

private:
    sf::RenderTarget& m_target;
};