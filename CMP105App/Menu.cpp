#include "Menu.h"



Menu::Menu(GameState* gs, RenderWindow* hwnd, Input* in)
{
	gameState = gs;
	window = hwnd;
	input = in;

	menuBGTex.loadFromFile("gfx/MenuBG.png");
	playTex.loadFromFile("gfx/playButton.png");
	creditsTex.loadFromFile("gfx/CreditsButton.png");
	TutorialTex.loadFromFile("gfx/tutorialButton.png");
	quitTex.loadFromFile("gfx/QuitButton.png");
	
	menuBG.setSize(Vector2f(1280, 720));
	menuBG.setPosition(0, 0);
	menuBG.setTexture(&menuBGTex);
	setInput(input);

	// buttons
	playButton.setSize(Vector2f(150, 75));
	playButton.setPosition(50, 110);
	playButton.setTexture(&playTex);
	playButton.setCollisionBox(FloatRect(0, 0, 150, 75));

	creditsButton.setSize(Vector2f(150, 75));
	creditsButton.setPosition(50, 200);
	creditsButton.setTexture(&creditsTex);
	creditsButton.setCollisionBox(FloatRect(0, 0, 150, 75));

	TutorialButton.setSize(Vector2f(150, 75));
	TutorialButton.setPosition(50, 290);
	TutorialButton.setTexture(&TutorialTex);
	TutorialButton.setCollisionBox(FloatRect(0, 0, 150, 75));

	quitButton.setSize(Vector2f(150, 75));
	quitButton.setPosition(50, 380);
	quitButton.setTexture(&quitTex);
	quitButton.setCollisionBox(FloatRect(0, 0, 150, 75));
}


Menu::~Menu()
{
}


// handle user input
void Menu::handleInput(float dt)
{
	if (input->isMouseLDown() == true)
	{
		// play button
		if (input->getMouseX() > playButton.getPosition().x && input->getMouseX() < playButton.getPosition().x + playButton.getSize().x) {
			if (input->getMouseY() > playButton.getPosition().y && input->getMouseY() < playButton.getPosition().y + playButton.getSize().y) {

				gameState->setCurrentState(State::LEVEL);
			}
		}

		// options button
		if (input->getMouseX() > creditsButton.getPosition().x && input->getMouseX() < creditsButton.getPosition().x + creditsButton.getSize().x) {
			if (input->getMouseY() > creditsButton.getPosition().y && input->getMouseY() < creditsButton.getPosition().y + creditsButton.getSize().y) {
				gameState->setCurrentState(State::CREDITS);
			}
		}

		// tutorial button
		if (input->getMouseX() > TutorialButton.getPosition().x && input->getMouseX() < TutorialButton.getPosition().x + TutorialButton.getSize().x) {
			if (input->getMouseY() > TutorialButton.getPosition().y && input->getMouseY() < TutorialButton.getPosition().y + TutorialButton.getSize().y) {
				gameState->setCurrentState(State::TUTORIAL);
			}
		}

		// quit buttons
		if (input->getMouseX() > quitButton.getPosition().x && input->getMouseX() < quitButton.getPosition().x + quitButton.getSize().x) {
			if (input->getMouseY() > quitButton.getPosition().y && input->getMouseY() < quitButton.getPosition().y + quitButton.getSize().y) {
				window->close();
			}
		}
	}
}

// Update game objects
void Menu::update(float dt)
{

}

// Render level
void Menu::render()
{
	beginDraw();
	window->draw(menuBG);
	window->draw(playButton);
	window->draw(creditsButton);
	window->draw(TutorialButton);
	window->draw(quitButton);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Menu::beginDraw()
{
	window->clear(Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Menu::endDraw()
{
	window->display();
}
