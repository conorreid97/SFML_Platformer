#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include <string>
#include <iostream>
#include "Framework/GameObject.h"
using namespace sf;

class GameOver : public GameObject
{
public:
	GameOver(GameState* gs, RenderWindow* hwnd, Input* in);
	~GameOver();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;

	//level objects
	Texture gameOverBGTex;
	GameObject gameOverBG;
	View view;
};

