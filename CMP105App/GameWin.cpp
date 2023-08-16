#include "GameWin.h"



GameWin::GameWin(GameState* gs, RenderWindow* hwnd, Input* in)
{
	gameState = gs;
	window = hwnd;
	input = in;


	gameWinBGTex.loadFromFile("gfx/GameWinScreen.png");

	gameWinBG.setSize(sf::Vector2f(1000, 1000));
	gameWinBG.setPosition(-500, -500);
	gameWinBG.setTexture(&gameWinBGTex);

	setInput(input);
}


GameWin::~GameWin()
{
}

void GameWin::handleInput(float dt)
{
	// quit 
	if (input->isKeyDown(Keyboard::Enter))
	{
		window->close();
	}
}

// Update game objects
void GameWin::update(float dt)
{
	// resetting the screen view
	Vector2f position(0, 0);
	view.setCenter(position);
	window->setView(view);
}

// Render level
void GameWin::render()
{
	beginDraw();
	window->draw(gameWinBG);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void GameWin::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void GameWin::endDraw()
{
	window->display();
}

