#ifndef GAME_H
#define GAME_H
#include "utils.h"
#include "map.h"
#include "player.h"
class Game
{
public:
    Game(std::string mapFile, std::map<std::string, sf::Texture*> textures); 
    Nat level;
    Nat playerLives;
    Nat score;
    const sf::Vector2f agentPos(Agent agent);
    const Cell mapCellType(Coord coord);
    void moveAgent(Agent agent, float deltaTime, Direction dir);
    void resizeView(const sf::RenderWindow& window, sf::View& view);
    void mainLoop(sf::RenderWindow& window, sf::View& view);

    #if TESTS
    void setAgentPos(Agent agent, sf::Vector2f position);
    #endif
private:
    Map map_;
    Player player_;
    bool canMove_(Agent agent, Direction dir);

};

#endif /*GAME_H*/