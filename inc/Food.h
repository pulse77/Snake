#pragma once
#include <SFML/Graphics.hpp>

struct Food : sf::Drawable
{
	int x, y;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		sf::CircleShape circle(30.0f);
		circle.setPosition(sf::Vector2f(x * 60, y * 60));
		circle.setFillColor(sf::Color::Red);
		target.draw(circle);
	}
};