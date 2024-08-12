#pragma once
#include <deque>
#include <SFML/Graphics.hpp>

enum class Direction {
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Snake : public sf::Drawable {
public:
	Snake();
	~Snake();

	void update();
	bool isDead() const;
	Direction getDirection() const;
	void changeDirection(Direction dir);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	void move();
	void grow();
	bool checkCollision() const;

	bool m_isDead;
	Direction m_direction;
	sf::RectangleShape m_segmentRect;
	std::deque<sf::Vector2i> m_body;
};