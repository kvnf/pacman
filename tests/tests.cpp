#include <iostream>
#include "gtest-1.8.1/gtest.h"
#include <fstream>
#include "../src/headers/utils.h"
#include "../src/headers/globals.hpp"
#include "../src/headers/map.h"
#include "../src/headers/player.h"
#include "../src/headers/game.h"

using namespace std;

#if TESTS

TEST (testUtils, mapFromFile)
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
        "#............==............#",
        "#............  ............#",
        "#.............p............#",
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
    std::array<std::string, MAP_HEIGHT> fileMap = fileToArray("../resources/maps/map-01");
    EXPECT_EQ(fileMap, testMap);
}


TEST(testMap, testCellType)
{
	std::array<std::string, MAP_HEIGHT> testMap = fileToArray("../resources/maps/map-01");
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

TEST(testGame, testStartPosition)
{
    sf::Texture mapTexture;
    sf::Texture playerTexture;
    mapTexture.loadFromFile("../resources/sprites/map.png");
    playerTexture.loadFromFile("../resources/sprites/pacman.png");
    std::map<std::string, sf::Texture *> textures = {
        {"map", &mapTexture},
        {"player", &playerTexture}
    };
    Game game("../resources/maps/map-01", textures);
    Coord expectedStart(17, 14);
    sf::Vector2f start = game.agentPos(Agent::PACMAN);
    Nat posX = start.x / 16;
    Nat posY = start.y / 16;
    EXPECT_EQ(Coord(posX, posY), expectedStart);
}

TEST(testGame, testMapCellType)
{
    sf::Texture mapTexture;
    sf::Texture playerTexture;
    mapTexture.loadFromFile("../resources/sprites/map.png");
    playerTexture.loadFromFile("../resources/sprites/pacman.png");
    std::map<std::string, sf::Texture *> textures = {
        {"map", &mapTexture},
        {"player", &playerTexture}
    };
    Game game("../resources/maps/map-01", textures);
    EXPECT_EQ(game.mapCellType(Coord(0,0)), Cell::WALL);
	EXPECT_EQ(game.mapCellType(Coord(1,1)), Cell::PILL);
	EXPECT_EQ(game.mapCellType(Coord(1,5)), Cell::PILL);
	EXPECT_EQ(game.mapCellType(Coord(3,1)), Cell::POWER_UP);
	EXPECT_EQ(game.mapCellType(Coord(14,0)), Cell::TUNNEL);
	EXPECT_EQ(game.mapCellType(Coord(29,26)), Cell::FLOOR);
	EXPECT_EQ(game.mapCellType(Coord(30,27)), Cell::WALL);
}

TEST(testGame, testCanMove)
{
    sf::Texture mapTexture;
    sf::Texture playerTexture;
    mapTexture.loadFromFile("../resources/sprites/map.png");
    playerTexture.loadFromFile("../resources/sprites/pacman.png");
    std::map<std::string, sf::Texture *> textures = {
        {"map", &mapTexture},
        {"player", &playerTexture}
    };
    Game game("../resources/maps/map-01", textures);
    sf::Vector2f dest = map2Screen(Coord(1,4));
    game.setAgentPos(PACMAN, dest);
    
    EXPECT_EQ(game.agentPos(PACMAN).x, 16);
    EXPECT_EQ(game.agentPos(PACMAN).y, 4*16);
    
    game.moveAgent(PACMAN, 1, LEFT);
    game.moveAgent(PACMAN, 1, LEFT);
    game.moveAgent(PACMAN, 1, LEFT);
    game.moveAgent(PACMAN, 1, UP);
    game.moveAgent(PACMAN, 1, UP);
    game.moveAgent(PACMAN, 1, UP);
    game.moveAgent(PACMAN, 1, UP);
    game.moveAgent(PACMAN, 1, UP);
    EXPECT_LT(game.agentPos(PACMAN).y, 4*16);
    EXPECT_EQ(game.agentPos(PACMAN).x, 16);
}

#endif /*TESTS*/