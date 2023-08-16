#include "Coin.h"

Coin::Coin()
{
	// each part of the animation on spritesheet
	coin.addFrame(sf::IntRect(0, 0, 493, 495));
	coin.addFrame(sf::IntRect(493, 0, 493, 495));
	coin.addFrame(sf::IntRect(986, 0, 493, 495));
	coin.addFrame(sf::IntRect(0, 495, 493, 495));
	coin.addFrame(sf::IntRect(493, 495, 493, 495));
	coin.addFrame(sf::IntRect(986, 495, 493, 495));
	coin.addFrame(sf::IntRect(0, 990, 493, 495));
	coin.addFrame(sf::IntRect(493, 990, 493, 495));
	coin.addFrame(sf::IntRect(986, 990, 493, 495));
	coin.addFrame(sf::IntRect(0, 1485, 493, 495));
	coin.setFrameSpeed(1.f / 10.f);
	coin.setPlaying(true);
	coin.setLooping(true);
}

Coin::~Coin()
{
}

void Coin::update(float dt)
{
	//animates the coin
	coin.animate(dt);
	setTextureRect(coin.getCurrentFrame());
}


void Coin::collisionResponse(GameObject* collider)
{
	// take away coin from game
	setAlive(false);
}
