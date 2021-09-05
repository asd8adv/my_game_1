// main.cpp
#include <SFML/Graphics.hpp>
#include "character.h"
#include "icons.h"



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



	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		std::cout << time << "\n";

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
					ch.move(event, time);
					break;
				default:
					break;
				}
			}
		}

		window.clear();

		mp.draw(window);
		window.draw(bord);
		ch.draw(window);
		gold.draw(window);
		
		window.display();
	}

	return 0;
}