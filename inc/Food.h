#pragma once
#include <SFML/Graphics.hpp>

struct Food : sf::Drawable
{
	sf::Vector2i pos;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		sf::CircleShape circle(30.0f);
		circle.setPosition(sf::Vector2f(pos.x * 60, pos.y * 60));
		circle.setFillColor(sf::Color::Red);
		target.draw(circle);
	}
};