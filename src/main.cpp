#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "headers/game.h"
#include "headers/paths.hpp"

#if MAIN
int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE, SCREEN_SIZE), "Main!", sf::Style::Close);
	sf::View view(sf::Vector2f(VIEW_HEIGHT/2, VIEW_HEIGHT/2), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	sf::Texture mapTexture;
    sf::Texture playerTexture;
    mapTexture.loadFromFile("../resources/sprites/map.png");
    playerTexture.loadFromFile("../resources/sprites/pacman.png");
    std::map<std::string, sf::Texture *> textures = {
        {"map", &mapTexture},
        {"player", &playerTexture}
    };
    Game game("../resources/maps/map-01", textures);
	game.mainLoop(window, view);
    return 0;
}
#endif