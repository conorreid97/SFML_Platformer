#include "Pause.h"



Pause::Pause(GameState* gs, RenderWindow* hwnd, Input* in)
{
	gameState = gs;
	window = hwnd;
	input = in;
	
	pauseBGTex.loadFromFile("gfx/PauseBG.png");

	pauseBG.setSize(sf::Vector2f(1000, 1000));
	pauseBG.setPosition(-500, -500);
	pauseBG.setTexture(&pauseBGTex);

	setInput(input);
	
}


Pause::~Pause()
{
}

// handle user input
void Pause::handleInput(float dt)
{
	// back to level
	if (input->isKeyDown(Keyboard::Enter))
	{
		gameState->setCurrentState(State::LEVEL);
	}
}

// Update game objects
void Pause::update(float dt)
{
	// resetting the screen view
	Vector2f position(0, 0);
	view.setCenter(position);
	window->setView(view);
}

// Render level
void Pause::render()
{
	beginDraw();
	window->draw(pauseBG);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Pause::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Pause::endDraw()
{
	window->display();
}
