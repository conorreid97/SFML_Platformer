#pragma once
#include "Coin.h"
#include <math.h>
#include <vector>
#include "Framework/Collision.h"


class CoinManager
{
public:
	CoinManager();
	~CoinManager();

	void update(float dt);
	void render(sf::RenderWindow* window);
	void coinPos();
	std::vector<Coin>* getCoins();

private:
	std::vector<Coin> coin;
	sf::Texture coinTex;
};

