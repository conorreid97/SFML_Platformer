#include "Pickups.h"



Pickups::Pickups()
{
	spawnPoint = Vector2f(600, 400);
	coinTex.loadFromFile("gfx/Coin.png");

	for (int i = 0; i < 20; i++)
	{
		coins.push_back(Coin());
		coins[i].setAlive(true);
		coins[i].setTexture(&coinTex);
		coins[i].setSize(Vector2f(100, 100));
	}
}


Pickups::~Pickups()
{
}


void Pickups::update(float dt)
{
	for (int i = 0; i < coins.size(); i++)
	{
		if (coins[i].isAlive())
		{
			coins[i].update(dt);
		}
	}
}

void Pickups::render(RenderWindow* window)
{
	for (int i = 0; i < coins.size(); i++)
	{
		if (coins[i].isAlive())
		{
			window->draw(coins[i]);
		}
	}
}

void Pickups::collisionResponse(GameObject* collider)
{
	for (int i = 0; i < coins.size(); i++)
	{
		if (coins[i].isAlive())
		{
			coins[i].setAlive(false);
		}
	}

}