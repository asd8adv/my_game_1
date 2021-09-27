#pragma once
#include "mapGeneric.h"
#include "character.h"
#include "object.h"

class Icon:public BaseObject, VisualObject {
protected:
	sf::Image img_;
	sf::Texture texture_;
	sf::Sprite icon_;
	vec2 iconSize_;
public:
	Icon(const std::string& file);

	virtual void setPosition(int x, int y);

	virtual void setPosition(vec2 pos);

	virtual void setScale(float scale);
	
	vec2 getPosition() const;

	const sf::Sprite& getIcon() const;

	virtual void draw(sf::RenderWindow& wind)override;

	void setIconSize(int x, int y);

	const vec2& getIconSize() const;

	void setTextureRect(int x, int y);
};

class Text :public VisualObject {
protected:
	sf::Text text_;
	sf::Font font_;
	int fontSize = 30;
public:
	Text(const std::string& text);

	virtual void draw(sf::RenderWindow& wind) override;

	void setText(const std::string& text);

	void setFontResource(const std::string& file);

	void setTextColor(sf::Color color);

	void setFontSize(uint32_t size);
	
	void setPosition(vec2 pos);
};

class TextIcon:public Icon, public Text {
	using Base = Icon;
	Dir orient_;
public:
	TextIcon(const std::string& file, const std::string& text, Dir orien = Dir::rigth);

	virtual void setPosition(int x, int y) override;

	virtual void draw(sf::RenderWindow& wind) override;
};


class IconCounter :public TextIcon {
	int count = 0;

public:
	IconCounter(const std::string& file, Dir orien = Dir::rigth);

	void increment(int c);
};

