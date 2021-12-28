#include "../headers/utils.h"

std::array<std::string, MAP_HEIGHT> fileToArray(std::string fileName){
    std::array<std::string, MAP_HEIGHT> m;
    
    std::ifstream file(fileName);
    int index = 0;
    for (std::string line; std::getline(file, line);){
        m[index] = line;
        index++;
    }

    return m;
};

sf::Vector2f map2Screen(const Coord coord)
{
    /*returns the pixel pair of given coordinates in the map
    the output is a sf::Vector3f pointing to the top-left pixel 
    of the tile.
    */
    sf::Vector2f screenPos(0,0);
    screenPos.y = coord.first * TILE_SIZE;
    screenPos.x = coord.second * TILE_SIZE;
    
    return screenPos;
}

Coord screen2Map(const sf::Vector2f pixel)
{
    /*returns the Coord / tile where given pixel is located*/ 
    Coord mapCoord(0,0);
    mapCoord.first = pixel.y / TILE_SIZE;
    mapCoord.second = pixel.x / TILE_SIZE;
    
    return mapCoord;     
}
