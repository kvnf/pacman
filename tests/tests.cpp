#include <iostream>
#include "gtest-1.8.1/gtest.h"
#include "../src/headers/globals.hpp"
#include "../src/headers/map.h"
#include "../src/headers/player.h"
#include "../src/headers/game.h"

using namespace std;

#if TESTS
TEST(testMap, testCellType)
{
	std::array<std::string, MAP_HEIGHT> testMap = {
    "############################",
    "#............##............#",
    "#.####.#####.##.#####.####.#",
    "#o####.#####.##.#####.####o#",
    "#.####.#####.##.#####.####.#",
    "#..........................#",
    "#.####.##.########.##.####.#",
    "#.####.##.########.##.####.#",
    "#......##....##............#",
    "######.#####.##............#",
    "######.#####.##............#",
    "######.##..................#",
    "######.##..................#",
    "######.##..................#",
    "D..........................D",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#..........................#",
    "#......................... #",
    "############################"
};
    sf::Texture texture;
    texture.loadFromFile("../resources/sprites/map.png");
	Map mapu(testMap, &texture, 16);
	EXPECT_EQ(mapu.cellType(Coord(0,0)), Cell::WALL);
	EXPECT_EQ(mapu.cellType(Coord(1,1)), Cell::PILL);
	EXPECT_EQ(mapu.cellType(Coord(1,5)), Cell::PILL);
	EXPECT_EQ(mapu.cellType(Coord(3,1)), Cell::POWER_UP);
	EXPECT_EQ(mapu.cellType(Coord(14,0)), Cell::TUNNEL);
	EXPECT_EQ(mapu.cellType(Coord(29,26)), Cell::FLOOR);
	EXPECT_EQ(mapu.cellType(Coord(30,27)), Cell::WALL);

}

TEST(testPlayer, testPosition)
{
    sf::Texture texture;
    texture.loadFromFile("../resources/sprites/pacman.png");
    const sf::Vector2f startPos(200,200);
    Player player(&texture, sf::Vector2u(6,4), 0.1f, PLAYER_SPEED, TILE_SIZE, startPos);
    EXPECT_EQ(player.playerPos(), sf::Vector2f(200,200));

}

TEST(testPlayer, testBasicMove)
{
    sf::Texture texture;
    texture.loadFromFile("../resources/sprites/pacman.png");
    const sf::Vector2f startPos(150,150);
    Player player(&texture, sf::Vector2u(6,4), 0.1f, PLAYER_SPEED, TILE_SIZE, startPos);
    EXPECT_EQ(player.playerPos(), sf::Vector2f(150,150));
    player.update(1, LEFT);
    player.update(1, LEFT);
    EXPECT_EQ(player.playerPos().y, 150);
    EXPECT_LT(player.playerPos().x, 150);
    player.update(1, UP);
    player.update(1, UP);
    EXPECT_LT(player.playerPos().y, 150);
    EXPECT_LT(player.playerPos().x, 150);
    player.update(1, RIGHT);
    player.update(1, RIGHT);
    EXPECT_LT(player.playerPos().y, 150);
    EXPECT_EQ(player.playerPos().x, 150);
    player.update(1, DOWN);
    player.update(1, DOWN);
    EXPECT_EQ(player.playerPos().y, 150);
    EXPECT_EQ(player.playerPos().x, 150);

}

#endif /*TESTS*/