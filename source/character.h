#pragma once
#include "mapGeneric.h"

class vec2;

class Character
{
	Dir lastDir_;
	sf::Image im_;
	sf::Texture tx_;
	sf::Sprite heroSprite_;
	float moveSpeed_;
	float currentFrame_;
	int spriteCount_;

	std::vector<vec2> bot_;
	std::vector<vec2> top_;
	std::vector<vec2> left_;
	std::vector<vec2> right_;
	vec2 spriteSize_;
public:
	Character(sf::String resourceName);

	void init();

	void setSpiteSize(int x, int y);

	void setTextures(TexturePosition pos, int spriteCount);

	void move(sf::Event& event, float time);

	void draw(sf::RenderWindow& wind);

	void setPosition(uint32_t x, uint32_t y);

	vec2 getPosition() const;

	vec2 getSize() const;
};

