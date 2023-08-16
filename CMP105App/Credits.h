#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include <string>
#include <iostream>
#include "Framework/GameObject.h"
using namespace sf;

class Credits : public GameObject
{
public:
	Credits(GameState* gs, RenderWindow* hwnd, Input* in);
	~Credits();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;

	//level objects
	Texture creditsBGTex;
	Texture backTex;
	GameObject creditsBG;
	GameObject backButton;
};

