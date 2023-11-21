#pragma once
#include <SFML/Graphics.hpp>

class Point : public sf::Drawable
{
	int id;
	int w = 10, h = 30;
public:

	sf::RectangleShape shape; 
	Point(int,float,float,float,float);
	void color(sf::Color);
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	int getId();
};

