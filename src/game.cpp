#include "headers/game.h"

Game::Game(std::array<std::string, MAP_HEIGHT> m, std::map<std::string, sf::Texture*> textures) : 
    map_(m, textures["map"], TILE_SIZE),
    player_(textures["player"], sf::Vector2u(6,4), 0.1f, PLAYER_SPEED, TILE_SIZE, sf::Vector2f(250, 250))
{

}