#pragma once
#include "mapGeneric.h"
#include "character.h"

class Icon {
	sf::Image img_;
	sf::Texture texture_;
	sf::Sprite icon_;
	coordinate iconSize_;
public:
	Icon(const std::string& file);

	virtual void setPosition(int x, int y);
	
	coordinate getPosition() const;

	const sf::Sprite& getIcon() const;

	virtual void draw(sf::RenderWindow& wind);

	void setIconSize(int x, int y);

	const coordinate& getIconSize() const;

	void setTextureRect(int x, int y);
};


class TextIcon:public Icon {
	using Base = Icon;
	Dir orient_;
	sf::Text text_;
	sf::Font font_;
	int fontSize = 30;
public:
	TextIcon(const std::string& file, const std::string& text, Dir orien = Dir::rigth);

	virtual void setPosition(int x, int y) override;

	void setText(const std::string& text);

	void setFontResource(const std::string& file);

	void setTextColor(sf::Color color);

	void setFontSize(uint32_t size);

	virtual void draw(sf::RenderWindow& wind) override;
};


class IconCounter :public TextIcon {
	int count = 0;

public:
	IconCounter(const std::string& file, Dir orien = Dir::rigth);

	void increment(int c);
};

