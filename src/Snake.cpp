#include "Snake.h"
#include "Config.h"

Snake::Snake()
	: m_direction{Direction::RIGHT}
	, m_body{sf::Vector2i(Config::MAP_WIDTH / 2,Config::MAP_WIDTH / 2)}
{
	m_segmentRect.setFillColor(sf::Color::Green);
	m_segmentRect.setOutlineColor(sf::Color::Cyan);
	m_segmentRect.setOutlineThickness(0.2f);
	m_segmentRect.setSize(sf::Vector2f(30.0f, 30.0f));
}

Snake::~Snake()
{
}

void Snake::move()
{
	if (m_direction == Direction::NONE)
		return;

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
	m_body.push_front(newHead);
	m_body.pop_back();
}

void Snake::grow()
{
	m_body.emplace_back(m_body.back());
}

bool Snake::checkCollision() const
{
	return false; // for now (until we get the snake moving)

	//auto it = m_body.cbegin();
	//const sf::Vector2i& head = *it;
	//while (++it != m_body.cend()) {
	//	if (*it == head)
	//		return true;
	//}
	//return false;
}

Direction Snake::getDirection() const
{
	return m_direction;
}

void Snake::changeDirection(Direction dir)
{
	m_direction = dir;
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rect = m_segmentRect;
	for (auto part : m_body) {
		rect.setPosition(sf::Vector2f{part.x * 60.0f, part.y * 60.0f});
		target.draw(rect);
	}
}
