#pragma once
#include "mapGeneric.h"


class Character
{
	Dir lastDir_;
	sf::Image im_;
	sf::Texture tx_;
	sf::Sprite heroSprite_;
	float moveSpeed_;
	float currentFrame_;
	int spriteCount_;

	std::vector<coordinate> bot_;
	std::vector<coordinate> top_;
	std::vector<coordinate> left_;
	std::vector<coordinate> right_;
	coordinate spriteSize_;
public:
	Character(sf::String resourceName);

	void init();

	void setSpiteSize(int x, int y);

	void setTextures(TexturePosition pos, int spriteCount);

	void move(sf::Event& event, float time);

	void draw(sf::RenderWindow& wind);

	void setPosition(uint32_t x, uint32_t y);

	coordinate getPosition() const;

	coordinate getSize() const;
};

