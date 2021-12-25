#include "headers/animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount_ = imageCount;
	this->switchTime_ = switchTime;
	this->totalTime_ = 0.0f;
	currentImage_.x = 0;

	uvRect.width  = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}


void Animation::update(unsigned int row, float deltaTime, Direction dir)
{
	// side animation in row 0, up-down animation in row 1
	if (dir == UP || dir == DOWN)
	{
		row += 1;
	}
	this->currentImage_.y = row;
	this->totalTime_ += deltaTime;

	if (totalTime_ >= switchTime_)
	{
		totalTime_ -= switchTime_;
		currentImage_.x++;

		// cicle animation 
		if (currentImage_.x >= imageCount_.x){
			currentImage_.x = 0;
		}		
	}

	this->uvRect.top = currentImage_.y * uvRect.height;
	this->uvRect.left = currentImage_.x * uvRect.width;
	this->uvRect.width = abs(uvRect.width);
	this->uvRect.height = abs(uvRect.width);
	
	// flip animation when moving LEFT or DOWN (uses only 2 rows of sprites)
	if (dir == LEFT){
		this->uvRect.left = (currentImage_.x + 1) * abs(uvRect.width);
		this->uvRect.width = -abs(uvRect.width);		
	}
	else if (dir == DOWN)
	{
		this->uvRect.top = (currentImage_.y +1) * abs(uvRect.height);
		this->uvRect.height = -abs(uvRect.width);
	}
};