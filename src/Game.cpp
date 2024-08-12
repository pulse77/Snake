#include "Game.h"
#include "Config.h"

const sf::Time Game::timePerFrame = sf::seconds(0.15f);

Game::Game()
	: m_window{sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), "Snake", sf::Style::Close}
	, m_view{m_window.getDefaultView()}
{
	m_window.setFramerateLimit(Config::FPS_LIMIT);
	m_window.setKeyRepeatEnabled(false);
	srand(time(nullptr));
	m_food.pos.x = rand() % 20;
	m_food.pos.y = rand() % 20;
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	m_snake.grow();
	while (m_window.isOpen()) {
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			handleEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::handleEvents()
{
	sf::Event ev;
	while (m_window.pollEvent(ev)) {
		switch (ev.type) {
		case sf::Event::KeyPressed:
			handleInput(ev.key.code);
			break;
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}
	}
}

void Game::handleInput(sf::Keyboard::Key key)
{
	using sf::Keyboard;
	switch (key) {
	case Keyboard::W:
	case Keyboard::Up:
		if (m_snake.getDirection() != Direction::DOWN)
			m_snake.changeDirection(Direction::UP);
		break;
	case Keyboard::A:
	case Keyboard::Left:
		if (m_snake.getDirection() != Direction::RIGHT)
			m_snake.changeDirection(Direction::LEFT);
		break;
	case Keyboard::S:
	case Keyboard::Down:
		if (m_snake.getDirection() != Direction::UP)
			m_snake.changeDirection(Direction::DOWN);
		break;
	case Keyboard::D:
	case Keyboard::Right:
		if (m_snake.getDirection() != Direction::LEFT)
			m_snake.changeDirection(Direction::RIGHT);
		break;
	}
}

#include <iostream>
void Game::update(sf::Time dt)
{
	// I dont think we even need the dt

	m_snake.move();
	if (m_snake.eat(m_food)) {
		m_snake.grow();
		m_food.pos.x = rand() % 20;
		m_food.pos.y = rand() % 20;
	}
	
	if (m_snake.checkCollision()) {
		std::cout << "Game over!" << std::endl;
		m_window.close();
	}
}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_food);
	m_window.draw(m_snake);
	m_window.display();
}