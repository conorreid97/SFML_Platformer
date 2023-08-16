#include "Level.h"

Level::Level(GameState* gs, RenderWindow* hwnd, Input* in)
{
	gameState = gs;
	window = hwnd;
	input = in;

	view = window->getView();

	// calls tilemap function to set up map
	tileMap();
	
	// initialise game objects
	audio = new AudioManager();
	audio->addMusic("sfx/Cantina.ogg", "Cantina");
	audio->addSound("sfx/LifePickup.wav", "LifePickup");

	portalTex.loadFromFile("gfx/Portal.png");
	portalGunTex.loadFromFile("gfx/PortalGun.png");
	BGTex.loadFromFile("gfx/LevelBG.png");
	heartTex.loadFromFile("gfx/Heart.png");
	playerTex.loadFromFile("gfx/Player.png");
	enemyTex.loadFromFile("gfx/Enemy.png");

	for (int i = 0; i < 3; i++)
	{
		heart[i].setSize(Vector2f(70, 70));
		heart[i].setAlive(true);
		heart[i].setTexture(&heartTex);
		heart[i].setCollisionBox(FloatRect(0, 0, 70, 70));
	}
	
	heart[0].setPosition(3500, 200);
	heart[1].setPosition(5700, -100);
	heart[2].setPosition(9000, -0);

	for (int i = 0; i < 10; i++)
	{
		enemy[i].setSize(Vector2f(100, 80));
		enemy[i].setAlive(true);
		enemy[i].setTexture(&enemyTex);
		enemy[i].setCollisionBox(FloatRect(0, 0, 100, 80));
		enemy[i].setPlayer(&player);
	}
	enemyPos();

	portal.setSize(Vector2f(200, 200));
	portal.setPosition(11600, 300);
	portal.setAlive(false);
	portal.setTexture(&portalTex);
	portal.setCollisionBox(0, 0, 200, 200);

	portalGun.setSize(Vector2f(150, 150));
	portalGun.setPosition(10000, 500);
	portalGun.setAlive(true);
	portalGun.setTexture(&portalGunTex);
	portalGun.setCollisionBox(0, 0, 150, 150);

	BG.setSize(Vector2f(10000, 1850));
	BG.setPosition(-300, -1000);
	BG.setTexture(&BGTex);

	player.setSize(Vector2f(100, 100));
	player.setPosition(50, 200);
	player.setTexture(&playerTex);
	player.setInput(input);

	//enemy.setSize(Vector2f(100, 80));
	//enemy.setPosition(700, 520);
	//enemy.setTexture(&enemyTex);
	//enemy.setPlayer(&player);// where is the player
	//enemy.setInput(input);

	//collision boxes
	// floatRect (originx, originy, width, height);
	player.setCollisionBox(FloatRect(50, 0, 50, 100));

	//enemy.setCollisionBox(FloatRect(0, 0, 100, 80));
	audio->playMusicbyName("Cantina");
}

Level::~Level()
{
}
void Level::tileMap()
{
	// TILEMAP
	tilemap.loadTexture("gfx/Ground.png");
	std::vector<GameObject> tiles;

	// 0 to 14 meaans the amount of of tiles your using from the sheet
	for (int i = 0; i < 14; i++)
	{
		tile.setSize(Vector2f(100, 100));
		tile.setCollisionBox(0, 0, 100, 100);
		tile.setCollider(true);
		tiles.push_back(tile);
	}

	// intRect(xOrigin, yOrigin, xSize, ySize)
	tiles[0].setCollider(false);
	tiles[0].setTextureRect(IntRect(129, 385, 128, 128)); // blank 
	tiles[1].setTextureRect(IntRect(0, 0, 128, 128)); // top left
	tiles[2].setTextureRect(IntRect(129, 0, 128, 128)); // top middle
	tiles[3].setTextureRect(IntRect(257, 0, 128, 128)); // top right
	tiles[4].setTextureRect(IntRect(384, 0, 128, 128)); // left middle
	tiles[5].setTextureRect(IntRect(384, 256, 128, 128)); // left bottom
	tiles[6].setTextureRect(IntRect(0, 256, 128, 128)); // middle bottom
	tiles[7].setTextureRect(IntRect(0, 384, 128, 128)); // right bottom
	tiles[8].setTextureRect(IntRect(128, 128, 128, 128)); // right middle 
	tiles[9].setTextureRect(IntRect(0, 128, 128, 128)); // middle
	tiles[10].setTextureRect(IntRect(128, 256, 128, 128)); // left going up
	tiles[11].setTextureRect(IntRect(256, 256, 128, 128)); // left going up
	tiles[12].setTextureRect(IntRect(256, 128, 128, 128)); // right going up
	tiles[13].setTextureRect(IntRect(384, 128, 128, 128)); // right going up

	tilemap.setTileSet(tiles);
	//Creating the tile map
	//Map dimensions
	Vector2u mapSize(120, 8);
	//build map
	std::vector<int> map = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,12,13,9,9,9,9,9,10,11,2,2,2,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,12,13,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10,11,2,2,2,2,2,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,3,0,0,1,2,12,13,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10,11,2,2,2,2,2,2,3,0,0,0,1,2,2,12,13,9,9,9,9,9,9,9,9,9,9,9,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,12,13,9,9,9,9,8,0,0,4,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10,11,2,12,13,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,8,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,3,0,
		1,2,2,2,2,2,2,2,2,2,3,0,0,1,2,2,2,3,0,0,1,2,2,2,12,13,9,9,9,9,9,9,9,9,9,9,9,9,8,0,0,4,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10,11,3,0,0,1,2,2,2,2,2,2,2,12,13,9,9,9,9,8,0,
		5,6,6,6,6,6,6,6,6,6,7,0,0,5,6,6,6,7,0,0,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,0,0,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,0,0,5,6,6,6,6,6,6,6,6,6,6,6,6,6,7,0
	};
	tilemap.setTileMap(map, mapSize);
	tilemap.setPosition(Vector2f(0, 0));
	tilemap.buildLevel();
}

void Level::enemyPos()
{
	enemy[0].setPosition(700, 400);
	enemy[1].setPosition(2100, 300);
	enemy[2].setPosition(4200, 300);
	enemy[3].setPosition(1500, 300);
	enemy[4].setPosition(5300, -200);
	enemy[5].setPosition(6700, 0);
	enemy[6].setPosition(8100, 300);
	enemy[7].setPosition(9600, -300);
	enemy[8].setPosition(10900, 300);
	enemy[9].setPosition(11100, 300);
}

// handle user input
void Level::handleInput(float dt)
{
	// takes you to pause screen
	if (input->isKeyDown(Keyboard::P))
	{
		gameState->setCurrentState(State::PAUSE);
	}
}

// Update game objects
void Level::update(float dt)
{

	
	player.handleInput(dt);
	player.update(dt);
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i].isAlive())
		{
			enemy[i].update(dt);
		}
	}
	//bManager.update(dt);
	cManager.update(dt);

	// changes to end screen 
	if (player.getLives() <= 0) {
		gameState->setCurrentState(State::GAMEOVER);
	}
	// heart
	for (int i = 0; i < 3; i++){
		if (heart[i].isAlive()){
			heart[i].update(dt);
		}
	}
	//screen scrolling
	Vector2f position(window->getSize().x / 2, window->getSize().y / 2);
	position.x = player.getPosition().x + 300;
	position.y = player.getPosition().y - 25;
	view.setCenter(position);
	window->setView(view);

	// moving the background
	if (player.getPosition().x + 950 > BG.getPosition().x + BG.getSize().x){
		BG.setPosition(BG.getSize().x - 4000, -400);
	}

	// Collisions 
	// player & tiles
	std::vector<GameObject>* world = tilemap.getLevel();
	for (int i = 0; i < (int)world->size(); i++){
		if ((*world)[i].isCollider()){
			if (Collision::checkBoundingBox(&player, &(*world)[i])){
					player.groundCollision(&(*world)[i]);
			}
		}
	}
	// enemy & tiles
	for (int j = 0; j < 10; j++){
		for (int i = 0; i < (int)world->size(); i++){
			if (enemy[j].isAlive()){
				if ((*world)[i].isCollider()){
					if (Collision::checkBoundingBox(&enemy[j], &(*world)[i])){
						enemy[j].groundCollision(&(*world)[i]);
					}
				}

			}
		}
	}
	// player & enemy
	for (int i = 0; i < 10; i++){
		if (enemy[i].isAlive()){
			if (Collision::checkBoundingBox(&player, &enemy[i])){
				player.collisionResponse(NULL, dt);
				enemy[i].collisionResponse(NULL, dt);
			}
		}
	}
	// player & hearts
	for (int i = 0; i < 3; i++){
		if (heart[i].isAlive()){
			if (Collision::checkBoundingBox(&player, &heart[i])){
				audio->playSoundbyName("LifePickup");
				heart[i].collisionResponse(NULL);
			}
		}
	}
	// player & coins
	coin = cManager.getCoins();
	for (int i = 0; i < (int)coin->size(); i++){
		if ((*coin)[i].isAlive()){
			if (Collision::checkBoundingBox(&player, &(*coin)[i])){
				audio->playSoundbyName("LifePickup");
				player.points = player.points + 10;
				(*coin)[i].collisionResponse(NULL);
			}
		}
	}
	// player & portal
	if (portal.isAlive()){
		if (Collision::checkBoundingBox(&player, &portal)){
			gameState->setCurrentState(State::GAMEWIN);
		}
	}
	// player & portal gun
	if (Collision::checkBoundingBox(&player, &portalGun)){
		portal.setAlive(true);
		portalGun.setAlive(false);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(BG);
	tilemap.render(window);
	//player
	window->draw(player);
	// enemies
	for (int i = 0; i < 10; i++){
		if (enemy[i].isAlive()){
			window->draw(enemy[i]);
		}
	}
	// coins
	cManager.render(window);
	
	//heart
	for (int i = 0; i < 3; i++){
		if (heart[i].isAlive()){
			window->draw(heart[i]);
		}
	}
	// portal
	if (portal.isAlive()){
		window->draw(portal);
	}
	//portal gun
	if (portalGun.isAlive()){
		window->draw(portalGun);
	}
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}