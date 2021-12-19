#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <experimental/filesystem>
#include "headers/animation.h"
#include "headers/map.h"
#include "headers/npc.h"
#include "headers/player.h"
#include "headers/types.h"
namespace fs = std::experimental::filesystem;

//paths
fs::path PROJECT_PATH = (std::string)fs::current_path().parent_path();
fs::path SPRITES_PATH = PROJECT_PATH  / "resources" / "sprites";

//constants 
static const float PLAYER_SPEED = 200;
static const unsigned int PLAYER_SIZE =  16;
static const unsigned int SCREEN_SIZE = 512;
static const float VIEW_HEIGHT = 512;

void resizeView(const sf::RenderWindow& window, sf::View& view){
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE, SCREEN_SIZE), "Main!", sf::Style::Close);
// 	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

// 	sf::Texture playerTexture;
// 	playerTexture.loadFromFile(SPRITES_PATH / "pacman.png");
// 	Player player(&playerTexture, sf::Vector2u(6,4), 0.1f, PLAYER_SPEED, PLAYER_SIZE);
	
// 	float deltaTime = 0.0f;
// 	sf::Clock clock;

//     while (window.isOpen())
//     {
// 		deltaTime = clock.restart().asSeconds();
//         sf::Event evnt;
//         while (window.pollEvent(evnt))
//         {
// 			switch (evnt.type)
// 			{
// 			case sf::Event::Closed:
// 				window.close();
// 				break;
// 			case sf::Event::Resized:
// 				resizeView(window, view);
// 				break;
// 			}
//             if (evnt.type == sf::Event::Closed)
//                 window.close();
//         }


// 		player.update(deltaTime);
//         window.clear();
// 		window.setView(view);
//         player.draw(window);
//         window.display();
//     }

//     return 0;
// }