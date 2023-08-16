#include "GameOver.h"

GameOver::GameOver(GameState* gs, RenderWindow* hwnd, Input* in)
{
	gameState = gs;
	window = hwnd;
	input = in;

	gameOverBGTex.loadFromFile("gfx/GameOverScreen.png");

	gameOverBG.setSize(Vector2f(1000, 1000));
	gameOverBG.setPosition(-500, -500);
	gameOverBG.setTexture(&gameOverBGTex);
	
	setInput(input);
}


GameOver::~GameOver()
{
}


// handle user input
void GameOver::handleInput(float dt)
{
	// quit 
	if (input->isKeyDown(Keyboard::Enter))
	{
		window->close();
	}
}

// Update game objects
void GameOver::update(float dt)
{
	// resetting the screen view
	Vector2f position(0, 0);
	view.setCenter(position);
	window->setView(view);
}

// Render level
void GameOver::render()
{
	beginDraw();
	window->draw(gameOverBG);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void GameOver::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void GameOver::endDraw()
{
	window->display();
}