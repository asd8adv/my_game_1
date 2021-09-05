#include <random>  
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>
#include <ctime> 

struct BaseObject {
	int x;
	int y;
	int height;
	int width;
};

struct TexturePosition {
	int bot;
	int top;
	int left;
	int right;
};

enum class Dir
{
	bot,
	top,
	left,
	rigth
};

struct coordinate {
	int32_t x = 0;
	int32_t y = 0;
	void set(int32_t X, int32_t Y) {
		x = X;
		y = Y;
	}

	friend bool operator>(const coordinate& first, const coordinate& second) {
		if (first.x > second.x && first.y > second.y) {
			return true;
		}
		return false;
	}

	friend bool operator<(const coordinate& first, const coordinate& second) {
		if (first.x < second.x && first.y < second.y) {
			return true;
		}
		return false;
	}
	friend coordinate operator+(const coordinate& first, const coordinate& second) {
		return { (first.x + second.x), (first.y + second.y) };
	}

};

class randomize {
	int32_t min_;
	int32_t max_;

	std::unique_ptr<std::mt19937> rand_;
public:
	randomize(int32_t min, int32_t max) :min_(min), max_(max) {
		if (min > max)std::cerr << "error min/max value\n";
		rand_ = std::make_unique<std::mt19937>(std::mt19937(time(0)));
	}

	randomize(int32_t max) :min_(0), max_(max) {
		if (0 > max)std::cerr << "error min/max value\n";
		rand_ = std::make_unique<std::mt19937>(std::mt19937(time(0)));
	};

	int32_t get() {
		auto res = (*rand_)() % (max_ - min_ + 1);
		return min_ + res;
	}

};

static bool isCollision(BaseObject rectFirst, BaseObject rectSecond) {
	return	rectFirst.x < rectSecond.x + rectSecond.width &&
			rectFirst.x + rectFirst.width > rectSecond.x &&
			rectFirst.y < rectSecond.y + rectSecond.height &&
			rectFirst.y + rectFirst.height > rectSecond.y;
}
