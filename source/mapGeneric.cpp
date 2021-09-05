#include "mapGeneric.h"

/****************
**MyMapGeneric***
****************/
MyMapGeneric::MyMapGeneric(int32_t x, int32_t y) :rand_(1, VAR) {
	setSize(x, y);
}

void MyMapGeneric::setMapImg(const std::string& name) {
	im_.loadFromFile(name);
	tx_.loadFromFile(name);
	cSprite_.setTexture(tx_);
}


void MyMapGeneric::setSize(int32_t x, int32_t y) {
	size_.set(x, y);
	vec_.clear();
	vec_.reserve(x * y);
}

coordinate MyMapGeneric::getSize() const {
	return size_;
}

const std::vector<uint32_t>& MyMapGeneric::getVec() const {
	return vec_;
}

void MyMapGeneric::genericMap() {

	for (size_t i = 0; i < size_.y; i++)
		for (size_t j = 0; j < size_.x; j++) {
			if (checkPos(i * size_.x + j))
				vec_.push_back(0);
			else
				vec_.push_back(rand_.get());
		}
}

void MyMapGeneric::draw(sf::RenderWindow& wind) {
	auto size = getSize().x;
	uint32_t i = 0;
	for (auto it : getVec()) {
		switch (it) {
		case 0:
		default:
			cSprite_.setTextureRect(sf::IntRect(32, 0, 32, 32));
			break;
		case 1:
			cSprite_.setTextureRect(sf::IntRect(64, 0, 32, 32));
			break;
		case 2:
		case 3:
			cSprite_.setTextureRect(sf::IntRect(0, 0, 32, 32));
			break;
		}
		auto x = 32 * (i % size);
		auto y = 32 * (i / size);
		i++;
		cSprite_.setPosition(x, y);
		wind.draw(cSprite_);
	}
}

	bool MyMapGeneric::checkPos(int pos)const {
		int x = pos % size_.x;
		int y = pos / size_.x;
		if (x == 0 || x == size_.x - 1 ||
			y == 0 || y == size_.y - 1)
			return true;
		return false;

	}
