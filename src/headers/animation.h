#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include "types.h"

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	//~Animation();
	
	void update(unsigned int row, float deltaTime, Direction dir);


	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount_; // number of animation sprites in texture
	sf::Vector2u currentImage_; // current sprite of animation texture
	
	float totalTime_;
	float switchTime_;
};

#endif