#pragma once
#include "icons.h"

/****************
******Icon*******
****************/

Icon::Icon(const std::string& file) {
	img_.loadFromFile(file);
	img_.createMaskFromColor(sf::Color(100, 100, 100));
	texture_.loadFromImage(img_);
	icon_.setTexture(texture_);
	icon_.setScale(2, 2);
}

void Icon::setPosition(int x, int y) {
	icon_.setPosition(x, y);
}

coordinate Icon::getPosition() const {
	return { int32_t(icon_.getPosition().x),int32_t(icon_.getPosition().y) };
}

const sf::Sprite& Icon::getIcon() const {
	return icon_;
}

void Icon::draw(sf::RenderWindow& wind) {
	wind.draw(icon_);
}

void Icon::setIconSize(int x, int y) {
	iconSize_ = { x, y };
}

const coordinate& Icon::getIconSize() const {
	return iconSize_;
}

void Icon::setTextureRect(int x, int y) {
	icon_.setTextureRect(sf::IntRect(x, y, iconSize_.x, iconSize_.y));
}

/****************
*****TextIcon***
****************/

TextIcon::TextIcon(const std::string& file, const std::string& text, Dir orien) :orient_(orien), Base(file) {

	text_.setString(text);
}

void TextIcon::setPosition(int x, int y) {
	//TODO set text position with all direction
	Base::setPosition(x, y);
	switch (orient_)
	{
	case Dir::bot:
		text_.setPosition(getIcon().getPosition().x + getIconSize().x, getIcon().getPosition().y + getIconSize().y);
		break;
	case Dir::left:
		text_.setPosition(getIcon().getPosition().x + getIconSize().x, getIcon().getPosition().y + getIconSize().y);
		break;
	case Dir::top:
		text_.setPosition(getIcon().getPosition().x + getIconSize().x, getIcon().getPosition().y + getIconSize().y);
		break;
	default:
	case Dir::rigth:
		text_.setPosition(getIcon().getPosition().x + getIconSize().x * 1.25 * 2, getIcon().getPosition().y + getIconSize().y / 2 - fontSize / 2);
		break;
	}
}

void TextIcon::setText(const std::string& text) {
	text_.setString(text);
}

void TextIcon::setFontResource(const std::string& file) {
	font_.loadFromFile(file);
	text_.setFont(font_);
}



void TextIcon::setTextColor(sf::Color color) {
	//text_.setColor(color);
	text_.setFillColor(color);
}

void TextIcon::setFontSize(uint32_t size) {
	fontSize = size;
	text_.setCharacterSize(fontSize);
}

void TextIcon::draw(sf::RenderWindow& wind) {
	wind.draw(text_);
	Base::draw(wind);
}


/****************
***IconCounter***
****************/

IconCounter::IconCounter(const std::string& file, Dir orien) :TextIcon(file, "", orien) {
	count = 0;

}

void IconCounter::increment(int c) {
	count += c;
	setText(std::to_string(count));
}

