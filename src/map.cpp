#include "headers/map.h"

Map::Map(std::array<std::string, MAP_HEIGHT> m)
{ 
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            switch (m[i][j])
            {
            case '.':
                this->map_[Coord(i,j)] = Cell::PILL;
                break;
            case 'o':
                this->map_[Coord(i,j)] = Cell::POWER_UP;
                break;
            case '#':
                this->map_[Coord(i,j)] = Cell::WALL;
                break;
            case 'D':
                this->map_[Coord(i,j)] = Cell::TUNNEL;
                break;
            case '=':
                this->map_[Coord(i,j)] = Cell::DOOR;
                break;
            default:
                this->map_[Coord(i,j)] = Cell::FLOOR;
                break;
            }
        }
    }
}
Cell Map::cellType(Coord coord){
    return this->map_[coord];
}