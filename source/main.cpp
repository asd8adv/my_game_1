// main.cpp
#include <SFML/Graphics.hpp>
#include "character.h"
#include "icons.h"
#include "buttonManager.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 800), "15");//30x25
	sf::Event event;
	sf::Clock clock;

	Character ch("resource/ch_01.png");
	ch.setSpiteSize(24, 32);
	ch.setTextures({ 64,0,96,32 },3);
	ch.init();

	MyMapGeneric mp(30, 25);
	mp.genericMap();
	mp.setMapImg("resource/set.png");

	sf::Texture text;
	text.loadFromFile("resource/boarder_1.png");

	sf::Sprite bord;
	bord.setTexture(text);
	bord.setPosition(960, 0);

	IconCounter gold("resource/UI.png");
	gold.setIconSize(32, 32);
	gold.setTextureRect(0, 0);
	gold.setPosition(1000, 50);
	gold.setFontResource("resource/alagard.ttf");
	gold.setText("0");
	gold.setTextColor(sf::Color::Blue);
	gold.setFontSize(50);

	auto btn=std::make_shared<bigButton> ("resource/btn_1.png","pressed it!!!", vec2( 1000, 200 ));
	btn->setCallback([]() {	std::cout << "u pressed it!!!" << "\n";	});
	btn->setPosition({ 1000, 200 });
	btn->setFontSize(12);
	btn->setSize({ 160, 80 });
	btn->setFontResource("resource/alagard.ttf");
	btn->setTextColor(sf::Color::Blue);

	ButtonManager man;
	man.addButton(btn, 0);

	while (window.isOpen())
	{
		float dt = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		dt = dt / 800;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code) {
				case(sf::Keyboard::Escape):
					window.close();
					break;
				case(sf::Keyboard::W):
				case(sf::Keyboard::A):
				case(sf::Keyboard::S):
				case(sf::Keyboard::D):
					ch.move(event, dt);
					break;
				default:
					break;
				}
			}
			if (event.type = sf::Event::MouseMoved) {
				auto pos = sf::Mouse::getPosition(window);
				man.checkColision({ pos.x,pos.y });
			}
		}



		window.clear();

		mp.draw(window);
		window.draw(bord);
		ch.draw(window);
		gold.draw(window);
		man.update(dt);
		man.draw(window);
		window.display();
	}

	return 0;
}