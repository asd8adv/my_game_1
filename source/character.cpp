#include "character.h"
#include "magicBox.h"

Character::Character(sf::String resourceName) {
	moveSpeed_ = 5;
	im_.loadFromFile(resourceName);
	im_.createMaskFromColor(sf::Color(100, 100, 100));
	tx_.loadFromImage(im_);
	heroSprite_.setTexture(tx_);
	heroSprite_.setScale(2, 2);
	lastDir_ = Dir::bot;
	currentFrame_ = 0;
	spriteCount_ = 0;
}

void Character::init() {
	heroSprite_.setTextureRect(sf::IntRect(bot_[0].x, bot_[0].y, spriteSize_.x, spriteSize_.y));
}
void Character::setSpiteSize(int x, int y) {
	spriteSize_ = { x,y };
}

void Character::setTextures(TexturePosition pos, int spriteCount) {
	spriteCount_ = spriteCount;

	for (int i = 0; i < spriteCount; i++) {
		left_.push_back({ i * spriteSize_.x,pos.left});
		right_.push_back({ i * spriteSize_.x,pos.right });
		bot_.push_back({ i * spriteSize_.x,pos.bot });
		top_.push_back({ i * spriteSize_.x,pos.top });
	};
}

void Character::move(sf::Event& event, float time) {
	if (time > 5)time = 5;
	currentFrame_++;
	if (currentFrame_ >= spriteCount_ * moveSpeed_) currentFrame_ = 0;

	time = moveSpeed_ * time * 1.4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		heroSprite_.move(0, -0.1 * time);
		heroSprite_.setTextureRect(sf::IntRect(top_[currentFrame_ / moveSpeed_].x, top_[currentFrame_ / moveSpeed_].y, spriteSize_.x, spriteSize_.y));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		heroSprite_.move(-0.1 * time, 0);
		heroSprite_.setTextureRect(sf::IntRect(left_[currentFrame_ / moveSpeed_].x, left_[currentFrame_ / moveSpeed_].y, spriteSize_.x, spriteSize_.y));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		heroSprite_.move(0, 0.1 * time);
		heroSprite_.setTextureRect(sf::IntRect(bot_[currentFrame_ / moveSpeed_].x, bot_[currentFrame_ / moveSpeed_].y, spriteSize_.x, spriteSize_.y));

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		heroSprite_.move(0.1 * time, 0);
		heroSprite_.setTextureRect(sf::IntRect(right_[currentFrame_ / moveSpeed_].x, right_[currentFrame_ / moveSpeed_].y, spriteSize_.x, spriteSize_.y));
	}

}

void Character::draw(sf::RenderWindow& wind) {
	wind.draw(heroSprite_);
}

void Character::setPosition(uint32_t x, uint32_t y) {
	heroSprite_.setPosition(x, y);
}

vec2 Character::getPosition() const {
	return { int32_t(heroSprite_.getPosition().x),int32_t(heroSprite_.getPosition().y) };
}

vec2 Character::getSize()const {
	return spriteSize_;
}