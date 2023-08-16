#include "Player.h"



Player::Player()
{
	scale = 200.f;
	gravity = 9.8f*scale;
	isJumping = false;
	speed = 300;
	facingLeft = false;
	lives = 3;
	points = 0;

	//idle animation
	{
		idle.addFrame(sf::IntRect(0, 0, 200, 310));
		idle.addFrame(sf::IntRect(200, 0, 200, 310));
		idle.addFrame(sf::IntRect(400, 0, 200, 310));
		idle.addFrame(sf::IntRect(600, 0, 200, 310));
		idle.addFrame(sf::IntRect(800, 0, 200, 310));
		idle.addFrame(sf::IntRect(1000, 0, 200, 310));
		idle.addFrame(sf::IntRect(1200, 0, 200, 310));

		idle.addFrame(sf::IntRect(0, 310, 200, 310));
		idle.addFrame(sf::IntRect(200, 310, 200, 310));
		idle.addFrame(sf::IntRect(400, 310, 200, 310));
		idle.addFrame(sf::IntRect(600, 310, 200, 310));
		idle.addFrame(sf::IntRect(800, 310, 200, 310));
		idle.addFrame(sf::IntRect(1000, 310, 200, 310));
		idle.addFrame(sf::IntRect(1200, 310, 200, 310));

		idle.addFrame(sf::IntRect(0, 620, 200, 310));
		idle.addFrame(sf::IntRect(200, 620, 200, 310));
		idle.addFrame(sf::IntRect(400, 620, 200, 310));
		idle.addFrame(sf::IntRect(600, 620, 200, 310));
		idle.addFrame(sf::IntRect(800, 620, 200, 310));
		idle.addFrame(sf::IntRect(1000, 620, 200, 310));
		idle.addFrame(sf::IntRect(1200, 620, 200, 310));

		idle.addFrame(sf::IntRect(0, 930, 200, 310));
		idle.addFrame(sf::IntRect(200, 930, 200, 310));
		idle.addFrame(sf::IntRect(400, 930, 200, 310));
		idle.addFrame(sf::IntRect(600, 930, 200, 310));
		idle.addFrame(sf::IntRect(800, 930, 200, 310));
		idle.addFrame(sf::IntRect(1000, 930, 200, 310));
		idle.addFrame(sf::IntRect(1200, 930, 200, 310));
		idle.setFrameSpeed(1.f / 28.f);
	}
	//run animation
	{
		// (xAxis_origin, yAxis_origin, xAxis_size, yAxis_size) //
		run.addFrame(sf::IntRect(1405, 0, 235, 320));
		run.addFrame(sf::IntRect(1640, 0, 235, 320));
		run.addFrame(sf::IntRect(1875, 0, 235, 320));
		run.addFrame(sf::IntRect(2110, 0, 235, 320));
		run.addFrame(sf::IntRect(2345, 0, 235, 320));
		run.addFrame(sf::IntRect(2580, 0, 235, 320));

		run.addFrame(sf::IntRect(1405, 320, 235, 320));
		run.addFrame(sf::IntRect(1640, 320, 235, 320));
		run.addFrame(sf::IntRect(1875, 320, 235, 320));
		run.addFrame(sf::IntRect(2110, 320, 235, 320));
		run.addFrame(sf::IntRect(2345, 320, 235, 320));
		run.addFrame(sf::IntRect(2580, 320, 235, 320));

		run.addFrame(sf::IntRect(1405, 640, 235, 320));
		run.addFrame(sf::IntRect(1640, 640, 235, 320));
		run.addFrame(sf::IntRect(1875, 640, 235, 320));
		run.addFrame(sf::IntRect(2110, 640, 235, 320));	
		run.addFrame(sf::IntRect(2345, 640, 235, 320));
		run.addFrame(sf::IntRect(2580, 640, 235, 320));

		run.addFrame(sf::IntRect(1405, 960, 235, 320));
		run.addFrame(sf::IntRect(1640, 960, 235, 320));
		run.addFrame(sf::IntRect(1875, 960, 235, 320));
		run.addFrame(sf::IntRect(2110, 960, 235, 320));
		run.addFrame(sf::IntRect(2345, 960, 235, 320));
		run.addFrame(sf::IntRect(2580, 960, 235, 320));
		run.setFrameSpeed(1.f / 24.f);
		run.setPlaying(true);
		run.setLooping(true);
	}
	//jump animation
	{
		jump.addFrame(sf::IntRect(2820, 0, 220, 350));			//220 Xaxis 347 Yaxis
		jump.addFrame(sf::IntRect(3040, 0, 220, 350));
		jump.addFrame(sf::IntRect(3260, 0, 220, 350));
		jump.addFrame(sf::IntRect(3480, 0, 220, 350));
		jump.addFrame(sf::IntRect(3700, 0, 220, 350));
		jump.addFrame(sf::IntRect(3920, 0, 220, 350));
		jump.addFrame(sf::IntRect(4140, 0, 220, 350));

		jump.addFrame(sf::IntRect(2820, 347, 220, 350));
		jump.addFrame(sf::IntRect(3040, 347, 220, 350));
		jump.addFrame(sf::IntRect(3260, 347, 220, 350));
		jump.addFrame(sf::IntRect(3480, 347, 220, 350));
		jump.addFrame(sf::IntRect(3700, 347, 220, 350));
		jump.addFrame(sf::IntRect(3920, 347, 220, 350));
		jump.addFrame(sf::IntRect(4140, 347, 220, 350));

		jump.addFrame(sf::IntRect(2820, 694, 220, 350));
		jump.addFrame(sf::IntRect(3040, 694, 220, 350));
		jump.addFrame(sf::IntRect(3260, 694, 220, 350));
		jump.addFrame(sf::IntRect(3480, 694, 220, 350));
		jump.addFrame(sf::IntRect(3700, 694, 220, 350));
		jump.addFrame(sf::IntRect(3920, 694, 220, 350));
		jump.addFrame(sf::IntRect(4140, 694, 220, 350));

		jump.addFrame(sf::IntRect(2820, 1041, 220, 350));
		jump.addFrame(sf::IntRect(3040, 1041, 220, 350));
		jump.addFrame(sf::IntRect(3260, 1041, 220, 350));
		jump.addFrame(sf::IntRect(3480, 1041, 220, 350));
		jump.addFrame(sf::IntRect(3700, 1041, 220, 350));
		jump.addFrame(sf::IntRect(3920, 1041, 220, 350));
		jump.addFrame(sf::IntRect(4140, 1041, 220, 350));
		jump.setFrameSpeed(1.f / 28.f);
	}
	//die animation
	{
		die.addFrame(sf::IntRect(600, 1290, 420, 350));
		die.addFrame(sf::IntRect(1020, 1290, 420, 350));
		die.addFrame(sf::IntRect(1440, 1290, 420, 350));

		die.addFrame(sf::IntRect(600, 1640, 420, 350));
		die.addFrame(sf::IntRect(1020, 1640, 420, 350));
		die.addFrame(sf::IntRect(1040, 1640, 420, 350));

		die.addFrame(sf::IntRect(600, 1990, 420, 350));
		die.addFrame(sf::IntRect(1020, 1990, 420, 350));
		die.addFrame(sf::IntRect(1040, 1990, 420, 350));

		die.addFrame(sf::IntRect(600, 2340, 420, 350));
		die.addFrame(sf::IntRect(1020, 2340, 420, 350));
		die.addFrame(sf::IntRect(1040, 2340, 420, 350));

		die.addFrame(sf::IntRect(600, 2690, 420, 350));
		die.addFrame(sf::IntRect(1020, 2690, 420, 350));
		die.setFrameSpeed(1.f / 14.f);
	}
		
	setTextureRect(idle.getCurrentFrame());
}


Player::~Player()
{
}

void Player::update(float dt)
{	
	// kills player if they fall off tiles
	if (getPosition().y > 700)
	{
		setPosition(50, 200);
		lives--;
	}
}

// deals with jumping
void Player::Jump(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		jump.setFlipped(false);
		if (!isJumping)
		{
			jump.animate(dt);
			setTextureRect(jump.getCurrentFrame());		
			velocity.y = -4.f*scale;
			isJumping = true;	
		}
	}
}

void Player::handleInput(float dt)
{
	// sets gravity
	velocity.y += gravity * dt;

	// move right
	if (input->isKeyDown(sf::Keyboard::D))
	{
		setPosition(getPosition().x + speed * dt, getPosition().y);
		run.animate(dt);
		setTextureRect(run.getCurrentFrame());
		run.setFlipped(false);
		Jump(dt);
	}
	// move left
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		setPosition(getPosition().x - speed * dt, getPosition().y);
		run.animate(dt);
		setTextureRect(run.getCurrentFrame());
		run.setFlipped(true);
		facingLeft = true;
		Jump(dt);
		jump.setFlipped(true);
	}
	// idle
	else
	{
		idle.animate(dt);
		setTextureRect(idle.getCurrentFrame());
		Jump(dt);
	}

	// move shape by new velocity
	move(velocity*dt);
}

void Player::collisionResponse(GameObject* collider, float dt)
{
	// kills player taking off life and resetting position
	die.animate(dt);
	setTextureRect(die.getCurrentFrame());
	setPosition(50, 200);
	lives--;
}

void Player::groundCollision(GameObject* collider)
{
	// keeps player on ground
	isJumping = false;
	velocity.y = 0;
	setPosition(getPosition().x, collider->getPosition().y - getSize().y);
}

int Player::getLives()
{
	return lives;
}

int Player::setLives(int i)
{
	lives = getLives() + i;
	return lives;
}
