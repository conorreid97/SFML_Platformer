#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include <string>
#include <iostream>
#include "Framework/GameObject.h"
using namespace sf;

class Menu : public GameObject
{
public:
	Menu(GameState* gs, RenderWindow* hwnd, Input* in);
	~Menu();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
    RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;

	//level objects
	Texture menuBGTex;
	Texture playTex;
	Texture creditsTex;
	Texture TutorialTex;
	Texture quitTex;

	GameObject menuBG;
	GameObject playButton;
	GameObject creditsButton;
	GameObject TutorialButton;
	GameObject quitButton;
};

