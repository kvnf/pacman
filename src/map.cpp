#include "headers/map.h"

Map::Map(std::array<std::string, MAP_HEIGHT> m, sf::Texture* texture, Nat tileSize)
{ 
    this->texture_ = texture;
    this->tileSize_ = tileSize;
    this->uvRect.width = this->tileSize_;
    this->uvRect.height = this->tileSize_;
 
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

 

/*draws entire map at game start only*/
void Map::draw(sf::RenderWindow& window)
{
    sf::RectangleShape tile(sf::Vector2f(this->tileSize(), this->tileSize()));
    tile.setTexture(this->texture_);
    for (Nat i = 0; i < MAP_HEIGHT; i++){
        for (Nat j = 0; j < MAP_WIDTH; j++){
            //move rectangle to curr coord
            tile.setPosition(static_cast<float>(j * tileSize()), static_cast<float>(i * tileSize()));

            switch (this->cellType(Coord(i,j)))
            {
            case Cell::PILL:
                uvRect.top = uvRect.height;
                uvRect.left = 0;
                tile.setFillColor(sf::Color::Green);
                break;
            case Cell::POWER_UP:
                uvRect.top = uvRect.height;
                uvRect.left = uvRect.width;
                tile.setFillColor(sf::Color::Red);
                break;
            case Cell::FLOOR:
                uvRect.top = uvRect.height;
                uvRect.left = uvRect.width * 3;
                tile.setFillColor(sf::Color::Green);
                break;
            case Cell::TUNNEL:
                uvRect.top = uvRect.height;
                uvRect.left = uvRect.width * 3;
                tile.setFillColor(sf::Color::Magenta);
                break;
            case Cell::DOOR:
                uvRect.top = uvRect.height;
                uvRect.left = uvRect.width * 2;
                tile.setFillColor(sf::Color::Yellow);
                break;
            case Cell::WALL:
                uvRect.top = 0;
                uvRect.left = 0;
                tile.setFillColor(sf::Color::Blue);
                break;
            default:
                uvRect.top = uvRect.height;
                uvRect.left = uvRect.width * 3;
                tile.setFillColor(sf::Color::Blue);

                break;
            }
            tile.setTextureRect(this->uvRect);
            window.draw(tile);
        }
    }
}


Cell Map::cellType(Coord coord)
{
    return this->map_[coord];
}

Nat Map::tileSize()
{
    return this->tileSize_;
}