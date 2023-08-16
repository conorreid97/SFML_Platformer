#include "Credits.h"

Credits::Credits(GameState* gs, RenderWindow* hwnd, Input* in)
{
	gameState = gs;
	window = hwnd;
	input = in;
	
	// textures
	creditsBGTex.loadFromFile("gfx/CreditsBG.png");
	backTex.loadFromFile("gfx/backButton.png");

	creditsBG.setSize(sf::Vector2f(1280, 720));
	creditsBG.setPosition(0, 0);
	creditsBG.setTexture(&creditsBGTex);

	backButton.setSize(Vector2f(150, 50));
	backButton.setPosition(50, 600);
	backButton.setTexture(&backTex);
	// lets you input stuff
	setInput(input);
}


Credits::~Credits()
{
}

// handle user input
void Credits::handleInput(float dt)
{
	// back button
	if (input->isMouseLDown() == true)
	{
		if (input->getMouseY() > backButton.getPosition().x && input->getMouseX() < backButton.getPosition().x + backButton.getSize().x) {
			if (input->getMouseY() > backButton.getPosition().y && input->getMouseY() < backButton.getPosition().y + backButton.getSize().y) {
				gameState->setCurrentState(State::MENU);
			}
		}
	}
}

// Update game objects
void Credits::update(float dt)
{
	
}

// Render level
void Credits::render()
{
	beginDraw();
	window->draw(creditsBG);
	window->draw(backButton);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Credits::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Credits::endDraw()
{
	window->display();
}
