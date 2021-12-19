#ifndef PLAYER_H
#define PLAYER_H
#include "animation.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, const Nat sprite_size);
	//~Player();
	
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body_;
	Animation animation_;
	unsigned int row_;
	float speed_;
	Direction dir_;
};


#endif