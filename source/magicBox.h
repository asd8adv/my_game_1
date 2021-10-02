#pragma once
#include <random>  
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>
#include <ctime> 


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

struct vec2 {
	int32_t x = 0;
	int32_t y = 0;
	vec2() {};
	vec2(int32_t X, int32_t Y) :x(X), y(Y)
	{}

	void set(int32_t X, int32_t Y) {
		x = X;
		y = Y;
	}

	friend bool operator>(const vec2& first, const vec2& second) {
		if (first.x > second.x && first.y > second.y) {
			return true;
		}
		return false;
	}

	friend bool operator<(const vec2& first, const vec2& second) {
		if (first.x < second.x && first.y < second.y) {
			return true;
		}
		return false;
	}

	friend vec2 operator+(const vec2& first, const vec2& second) {
		return { (first.x + second.x), (first.y + second.y) };
	}

	friend vec2 operator-(const vec2& first, const vec2& second) {
		return { (first.x - second.x), (first.y - second.y) };
	}

	friend vec2 operator*(const vec2& first, const vec2& second) {
		return { (first.x * second.x), (first.y * second.y) };
	}

	friend vec2 operator*(const vec2& first, const float qf) {
		return { int32_t(first.x *qf), int32_t(first.y * qf) };
	}

	friend std::ostream& operator<< (std::ostream& out, const vec2& point){
		out << point.x << "," << point.y;
		return out;
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
