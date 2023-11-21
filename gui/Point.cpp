#include "Point.h"
#include <SFML/Graphics.hpp>

Point::Point(int id, float w,float h,float x, float y)
{
	this->id = id;
	this->shape.setSize({ w, h });
	this->shape.setFillColor(sf::Color::Black);
	this->shape.setPosition(x, y);
}

void Point::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

void Point::color(sf::Color a)
{
	this->shape.setFillColor(a);
}
int Point::getId()
{
	return this->id;
}