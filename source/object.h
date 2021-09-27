#pragma once
#include <SFML/Graphics.hpp>
#include "magicBox.h"

namespace sf{
class RenderWindow;
}

class VisualObject {
protected:
	virtual void draw(sf::RenderWindow& wind) {};
};


struct BaseObject {
public:
	int x;
	int y;
	int height;
	int width;
	void set(int X, int Y, int W, int H) {
		x = X;
		y = Y;
		height = H;
		width = W;
	}
};


static bool isCollision(const BaseObject& rectFirst, const BaseObject& rectSecond) {
	return	rectFirst.x < rectSecond.x + rectSecond.width &&
		rectFirst.x + rectFirst.width > rectSecond.x &&
		rectFirst.y < rectSecond.y + rectSecond.height &&
		rectFirst.y + rectFirst.height > rectSecond.y;
}

static bool isCollision(const BaseObject& rectFirst, vec2 point) {
	return	rectFirst.x < point.x && point.x < rectFirst.x + rectFirst.width&&
			rectFirst.y < point.y && point.y < rectFirst.y + rectFirst.height;
}