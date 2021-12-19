#ifndef MAP_H
#define MAP_H
#include "types.h"

static const Nat MAP_HEIGHT = 31;
static const Nat MAP_WIDTH = 28;

class Map
{
public:
    Map(std::array<std::string, MAP_HEIGHT> m);
    //~Map();

    Cell cellType(Coord);
private: 
    std::map<Coord, Cell> map_;
    Nat pillCount_;

};

#endif