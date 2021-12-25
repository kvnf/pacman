#ifndef GAME_H
#define GAME_H
#include "map.h"
#include "player.h"


class Game
{
public:
    Game(std::array<std::string, MAP_HEIGHT> m, std::map<std::string, sf::Texture*> textures);
private:
    Map map_;
    Player player_;
};

#endif /*GAME_H*/