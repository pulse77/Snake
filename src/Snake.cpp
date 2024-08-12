#include "Snake.h"
#include "Config.h"

Snake::Snake()
	: m_direction{Direction::RIGHT}
	, m_body{sf::Vector2i(Config::MAP_WIDTH / 2,Config::MAP_WIDTH / 2)}
{
}

void Snake::move()
{
	sf::Vector2i newHead = m_body.front();
	switch (m_direction) {
	case Direction::UP:
		newHead.y--;
		break;
	case Direction::DOWN:
		newHead.y++;
		break;
	case Direction::LEFT:
		newHead.x--;
		break;
	case Direction::RIGHT:
		newHead.x++;
		break;
	}
	m_body.pop_back();
	m_body.push_front(newHead);
}

void Snake::grow()
{
}

bool Snake::checkCollision() const
{
	auto it = m_body.cbegin();
	const sf::Vector2i& head = *it;
	while (++it != m_body.cend()) {
		if (*it == head)
			return true;
	}
	return false;
}

Direction Snake::getDirection() const
{
	return m_direction;
}

void Snake::changeDirection(Direction dir)
{
	m_direction = dir;
}