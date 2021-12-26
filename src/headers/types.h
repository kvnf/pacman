#ifndef TYPES_H
#define TYPES_H
#include <array>
#include <map>
#include <string>
#include <vector>
#include <iostream>
using Nat = unsigned int;
using Coord = std::pair<Nat, Nat>;

enum Cell {
	FLOOR, PILL, POWER_UP, WALL, TUNNEL, DOOR
};
enum  Direction {
	UP, DOWN, LEFT,	RIGHT
};

enum Agent {
	PACMAN, BLINKY, PINKY, INKY, CLYDE
};

#endif 