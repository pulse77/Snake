#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"

class Game {
public:
	Game();
	void run();

private:
	void handleEvents();
	void handleInput(sf::Keyboard::Key key);
	void update(sf::Time dt);
	void render();

private:
	static const sf::Time timePerFrame;

	sf::RenderWindow m_window;
	sf::View m_view;
};