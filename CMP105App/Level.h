#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/TileMap.h"
#include "Framework/Collision.h"
#include "Coin.h"
#include "Heart.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "CoinManager.h"
using namespace sf;

class Level : public GameObject
{
public:
	Level(GameState* gs, RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();
	void tileMap();
	void enemyPos();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;

	// level objects
	Texture BGTex;
	Texture playerTex;
	Texture enemyTex;
	Texture heartTex;
	Texture bulletTex;
	Texture portalTex;
	Texture portalGunTex;
	
	GameObject tile;
	View view;
	std::vector<Coin>* coin;
	Heart heart[3];
	GameObject portal;
	GameObject portalGun;
	GameObject BG;
	Player player;
	Enemy enemy[10];
	TileMap tilemap;
	CoinManager cManager;
	
};