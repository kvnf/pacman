#ifndef GLOBALS_H
#define GLOBALS_H
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

//paths
fs::path PROJECT_PATH = (std::string)fs::current_path().parent_path();
fs::path SPRITES_PATH = PROJECT_PATH  / "resources" / "sprites";

//constants 
static const float PLAYER_SPEED = 200;
static const unsigned int TILE_SIZE =  16;
static const unsigned int SCREEN_SIZE = 512;
static const float VIEW_HEIGHT = 512;
#endif