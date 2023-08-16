#include "Tutorial.h"



Tutorial::Tutorial(GameState* gs, RenderWindow* hwnd, Input* in)
{
	gameState = gs;
	window = hwnd;
	input = in;

	tutorialBGTex.loadFromFile("gfx/TutorialBG.png");
	backTex.loadFromFile("gfx/backButton.png");

	tutorialBG.setSize(sf::Vector2f(1280, 720));
	tutorialBG.setPosition(0, 0);
	tutorialBG.setTexture(&tutorialBGTex);

	backButton.setSize(Vector2f(150, 50));
	backButton.setPosition(50, 600);
	backButton.setTexture(&backTex);

	setInput(input);
}


Tutorial::~Tutorial()
{ 
}

void Tutorial::handleInput(float dt)
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

void Tutorial::update(float dt)
{
}

void Tutorial::render()
{
	beginDraw();
	window->draw(tutorialBG);
	window->draw(backButton);
	endDraw();
}

void Tutorial::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

void Tutorial::endDraw()
{
	window->display();
}