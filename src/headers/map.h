#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp> // map does not requiere animation.h
#include "globals.hpp"

class Map
{
public:
    Map(std::array<std::string, MAP_HEIGHT> m, sf::Texture* texture, Nat tileSize);
    //~Map();
    void draw(sf::RenderWindow& window);
    void update(float deltaTime);
    Cell cellType(Coord);
    Nat tileSize();
   	sf::IntRect uvRect;
    Coord startPos;

private:
    std::map<Coord, Cell> map_;
    sf::Texture* texture_;
    Nat tileSize_;
    Nat pillCount_; // if == 0 level cleared. 

};

#endif