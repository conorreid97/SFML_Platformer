#include "Enemy.h"

Enemy::Enemy()
{
	// sets up gravity
	scale = 200.f;
	gravity = 9.8f*scale;
	// (xAxis_origin, yAxis_origin, xAxis_size, yAxis_size) //
	idle.addFrame(IntRect(1300, 0, 355, 395));
	idle.addFrame(IntRect(1655, 0, 355, 395));
	idle.addFrame(IntRect(2010, 0, 355, 395));
	idle.addFrame(IntRect(1300, 395, 355, 395));
	idle.addFrame(IntRect(1655, 395, 355, 395));
	idle.addFrame(IntRect(2010, 395, 355, 395));
	idle.addFrame(IntRect(1300, 790, 355, 395));
	idle.addFrame(IntRect(1655, 790, 355, 395));
	idle.addFrame(IntRect(2010, 790, 355, 395));
	idle.setFrameSpeed(1.f / 9.f);

	run.addFrame(IntRect(0, 0, 405, 430));
	run.addFrame(IntRect(405, 0, 405, 430));
	run.addFrame(IntRect(810, 0, 405, 430));
	run.addFrame(IntRect(0, 430, 405, 430));
	run.addFrame(IntRect(450, 430, 405, 430));
	run.addFrame(IntRect(900, 430, 405, 430));
	run.addFrame(IntRect(0, 860, 405, 430));
	run.addFrame(IntRect(370, 860, 405, 430));
	run.addFrame(IntRect(890, 860, 405, 430));
	run.setFrameSpeed(1.f / 9.f);
	run.setPlaying(true);
	run.setLooping(true);

	attack.addFrame(IntRect(1820, 1190, 476, 430));
	attack.addFrame(IntRect(2296, 1190, 476, 430));
	attack.addFrame(IntRect(2772, 1190, 476, 430));
	attack.addFrame(IntRect(1820, 1620, 476, 430));
	attack.addFrame(IntRect(2296, 1620, 476, 430));
	attack.addFrame(IntRect(2772, 1620, 476, 430));
	attack.addFrame(IntRect(1820, 2050, 476, 430));
	attack.addFrame(IntRect(2296, 2050, 476, 430));
	attack.addFrame(IntRect(2772, 2050, 476, 430));
	attack.setFrameSpeed(1.f / 9.f);
	attack.setPlaying(true);
	attack.setLooping(true);

	// sets animation to idle at the start
	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());

	// moving to target
	speed = 50.f;
	acceleration = 50.f;
}


Enemy::~Enemy()
{
}

void Enemy::setPlayer(Player * p)
{
	player = p;
}

void Enemy::update(float dt)
{
	velocity.y += gravity * dt;
	move(velocity*dt);
	idle.animate(dt);
	setTextureRect(idle.getCurrentFrame());
	playerTarget = Vector2f(player->getPosition().x, player->getPosition().y);

	// sets player as a target 
	if (Vector::magnitude(playerTarget - getPosition()) < 500.f)
	{
		//find distance in x axis between enemy and player
		targetDistance = player->getPosition().x - getPosition().x;

		//if distance is negative move left and swing
		if (targetDistance < -50.f)
		{
			run.setFlipped(true);
			run.animate(dt);
			setTextureRect(run.getCurrentFrame());
			setPosition(getPosition().x - speed * dt, getPosition().y);
			move(velocity * dt);
			if (targetDistance > -180.f) {
				attack.setFlipped(true);
				attack.animate(dt);
				setTextureRect(attack.getCurrentFrame());
			}
		}
		//if distance is positive then move right and swing
		if (targetDistance > 50.f)
		{
			run.setFlipped(false);
			run.animate(dt);
			setTextureRect(run.getCurrentFrame());
			setPosition(getPosition().x + speed * dt, getPosition().y);
			move(velocity*dt);
			if (targetDistance < 150.f) {
				attack.setFlipped(false);
				attack.animate(dt);
				setTextureRect(attack.getCurrentFrame());
			}
		}
		// changes animation to idle
		if (targetDistance > 500.f)
		{
			idle.animate(dt);
		}
	
	}
}

void Enemy::collisionResponse(GameObject* collider, float dt)
{
}

void Enemy::groundCollision(GameObject* collider)
{
	// keeps it on ground
	velocity.y = 0;
	setPosition(getPosition().x, collider->getPosition().y - getSize().y);
}

Vector2f Enemy::setDirection(Vector2f target, Vector2f pos)
{
	direction = target - pos;
	return direction;
}