#include "headers/player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, const Nat sprite_size, sf::Vector2f startPos) : 
	animation_(texture, imageCount, switchTime)
{
	this->speed_ = speed;
	this->row_ = 0;
	this->dir_ = RIGHT;
	body_.setSize(sf::Vector2f(sprite_size, sprite_size));
	body_.setOrigin(sprite_size/2, sprite_size/2);
	body_.setTexture(texture);	
	body_.setPosition(startPos);
}

void Player::update(float deltaTime, Direction dir)
{
		switch (dir)
		{
		case Direction::LEFT:
			this->body_.move(-speed_ * deltaTime, 0.0f);
			this->dir_ = LEFT;
			break;
		case Direction::RIGHT:
			this->body_.move(speed_ * deltaTime, 0.0f);
			this->dir_ = RIGHT;
			break;
		case Direction::UP:
			this->body_.move(0.0f, -speed_ * deltaTime);
			this->dir_ = UP;	
			break;
		case Direction::DOWN:
			this->body_.move(0.0f, speed_ * deltaTime);
			this->dir_ = DOWN;	
			break;
		
		default:
			break;
		}

		this->animation_.update(row_, deltaTime, dir_);
		body_.setTextureRect(animation_.uvRect);
		
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(this->body_);
}

const sf::Vector2f Player::playerPos() const
{
	return this->body_.getPosition();
}