#include "headers/player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, const Nat sprite_size) : 
	animation_(texture, imageCount, switchTime)
{
	this->speed_ = speed;
	this->row_ = 0;
	this->dir_ = RIGHT;
	body_.setSize(sf::Vector2f(sprite_size, sprite_size));
	body_.setOrigin(sprite_size/2, sprite_size/2);
	body_.setTexture(texture);	
}

void Player::update(float deltaTime)
{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
			this->body_.move(-speed_ * deltaTime, 0.0f);
			this->dir_ = LEFT;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
			this->body_.move(speed_ * deltaTime, 0.0f);
			this->dir_ = RIGHT;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
			this->body_.move(0.0f, -speed_ * deltaTime);
			this->dir_ = UP;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
			this->body_.move(0.0f, speed_ * deltaTime);
			this->dir_ = DOWN;
		}
		this->animation_.update(row_, deltaTime, dir_);
		body_.setTextureRect(animation_.uvRect);
		
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(this->body_);
}
