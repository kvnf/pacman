#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "headers/animation.h"
#include "headers/map.h"
#include "headers/npc.h"
#include "headers/player.h"
#include "headers/types.h"
#include "headers/globals.h"

#if MAIN
void resizeView(const sf::RenderWindow& window, sf::View& view){
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
int main()
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

    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE, SCREEN_SIZE), "Main!", sf::Style::Close);
	sf::View view(sf::Vector2f(VIEW_HEIGHT/2, VIEW_HEIGHT/2), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	sf::Texture mapTexture;
	mapTexture.loadFromFile(SPRITES_PATH / "map.png");
	Map mapu(testMap, &mapTexture, TILE_SIZE);

	sf::Texture playerTexture;
	playerTexture.loadFromFile(SPRITES_PATH / "pacman.png");
	Player player(&playerTexture, sf::Vector2u(6,4), 0.1f, PLAYER_SPEED, TILE_SIZE);
	


	float deltaTime = 0.0f;
	sf::Clock clock;

    while (window.isOpen())
    {
		deltaTime = clock.restart().asSeconds();
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				resizeView(window, view);
				break;
			}
            if (evnt.type == sf::Event::Closed)
                window.close();
        }


		player.update(deltaTime);
        window.clear();
		window.setView(view);
		mapu.draw(window);
        player.draw(window);
        window.display();
    }

    return 0;
}
#endif