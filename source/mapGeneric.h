#pragma once
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>

#include "magicBox.h"

const int VAR = 3;//map objects variables count

class MyMapGeneric {
	randomize rand_;
	vec2 size_;
	std::vector<uint32_t> vec_;

	sf::Image im_;
	sf::Texture tx_;
	sf::Sprite cSprite_;

public:
	MyMapGeneric() :rand_(1, VAR)
	{}

	MyMapGeneric(int32_t x, int32_t y);

	void setMapImg(const std::string& name);

	void setSize(int32_t x, int32_t y);

	vec2 getSize() const;

	const std::vector<uint32_t>& getVec()const;

	void genericMap();

	void draw(sf::RenderWindow& wind);

	bool checkPos(int pos)const;//check need new line

	friend std::ostream& operator<<(std::ostream& os, const MyMapGeneric& map) {
		int i = 0;
		int j = 0;
		for (auto it : map.getVec()) {
			if (i >= map.getSize().x) {
				os << "\n";
				i = 0;
			}
			if (map.checkPos(j)) {
				os << 0;
				i++;
			}
			else {
				os << it;
				i++;
			}
			j++;
		}
		return os;

	}
};
