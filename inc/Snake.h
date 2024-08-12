#pragma once
#include <deque>
#include <SFML/Graphics.hpp>

enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Snake {
public:
	Snake();

	void move();
	void grow();
	bool checkCollision() const;
	Direction getDirection() const;
	void changeDirection(Direction dir);

private:
	Direction m_direction;
	std::deque<sf::Vector2i> m_body;
};