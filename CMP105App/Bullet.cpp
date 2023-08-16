#include "Bullet.h"



Bullet::Bullet()
{
	spawnPoint = sf::Vector2f(player.getPosition().x, player.getPosition().y);

}


Bullet::~Bullet()
{
}

void Bullet::update(float dt)
{
	setPosition(spawnPoint);
	velocity.x = 100.f;
	move(velocity*dt);
}

void Bullet::collisionResponse(GameObject* collider)
{
	// take away coin from game
	// add points to player
	// update ui
	setAlive(false);
}
