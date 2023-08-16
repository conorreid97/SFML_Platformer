#include "Heart.h"
#include <iostream>



Heart::Heart()
{
	heart.addFrame(sf::IntRect(0, 0, 493, 440));
	heart.addFrame(sf::IntRect(493, 0, 493, 440));
	heart.addFrame(sf::IntRect(986, 0, 493, 440));

	heart.addFrame(sf::IntRect(0, 440, 493, 440));
	heart.addFrame(sf::IntRect(493, 440, 493, 440));
	heart.addFrame(sf::IntRect(986, 440, 493, 440));

	heart.addFrame(sf::IntRect(0, 880, 493, 440));
	heart.addFrame(sf::IntRect(493, 880, 493, 440));
	heart.setFrameSpeed(1.f / 8.f);
	heart.setPlaying(true);
	heart.setLooping(true);
}


Heart::~Heart()
{
}

void Heart::update(float dt)
{
	heart.animate(dt);
	setTextureRect(heart.getCurrentFrame());
}


void Heart::collisionResponse(GameObject* collider)
{
	// take away heart from game
	// add 1 health to player
	player.setLives(1);
	setAlive(false);
}