#pragma once

namespace conf
{
// Window configuration
sf::Vector2u const window_size = {1980, 1080};
sf::Vector2f const window_size_f = static_cast<sf::Vector2f>(window_size);
uint32_t const max_framerate = 144;

}