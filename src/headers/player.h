#ifndef PLAYER_H
#define PLAYER_H
#include "animation.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, const Nat sprite_size, const sf::Vector2f startPos);
	//~Player();
	
	void update(float deltaTime, Direction dir);
	void draw(sf::RenderWindow& window);
	const sf::Vector2f playerPos() const;
	#if TESTS
	void setPlayerPos(sf::Vector2f position);
	#endif

private:
	sf::RectangleShape body_;
	Animation animation_;
	unsigned int row_;
	float speed_;
	Direction dir_;
};


#endif