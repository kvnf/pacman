#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include <SFML/Graphics.hpp>
#include "../headers/globals.hpp"

std::array<std::string, MAP_HEIGHT> fileToArray(std::string filenName);

sf::Vector2f map2Screen(const Coord coord);

Coord screen2Map(const sf::Vector2f pixel);
#endif /*UTILS_H*/