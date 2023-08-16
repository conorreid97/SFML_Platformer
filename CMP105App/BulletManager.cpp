#include "BulletManager.h"
#include "Player.h"

BulletManager::BulletManager()
{
	spawnPoint = Vector2f(300, 200/*p->getPosition().x, p->getPosition().y*/);
	texture.loadFromFile("gfx/Bullet.png");

	
	for (int i = 0; i < 3; i++)
	{
		bullets.push_back(Bullet());
		bullets[i].setAlive(false);
		bullets[i].setTexture(&texture);
		bullets[i].setSize(Vector2f(100, 100));
		bullets[i].setCollisionBox(sf::FloatRect(0, 0, 100, 100));
	}
}


BulletManager::~BulletManager()
{
}

void BulletManager::update(float dt)
{
	// update each bullet thats alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].update(dt);
		}
	}
	deathCheck();
}

void BulletManager::spawn()
{
	// sets velocity and positiion for each bullet thats alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i].isAlive()) {
			bullets[i].setAlive(true);
			bullets[i].setVelocity(20, 0);
			bullets[i].setPosition(spawnPoint);
			return;
		}
	}
}

void BulletManager::deathCheck()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			
			// right side
			if (bullets[i].getPosition().x < /*p->getPosition().x + */600) {
				bullets[i].setAlive(false);
			}
			// left side
			if (bullets[i].getPosition().x >/* p->getPosition().x -*/ 600) {
				bullets[i].setAlive(false);
			}
		}
	}
}

void BulletManager::render(RenderWindow* window)
{

	
	
	for (int i = 0; i < (int)bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			window->draw(bullets[i]);
		}
	}
}

std::vector<Bullet>* BulletManager::getBullets()
{
	return &bullets;
}
