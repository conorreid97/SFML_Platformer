#include "CoinManager.h"



CoinManager::CoinManager()
{
	// sets texture for coin
	coinTex.loadFromFile("gfx/Coin.png");

	//initialises coins
	for (int i = 0; i < 25; i++)
	{
		coin.push_back(Coin());
		coin[i].setSize(sf::Vector2f(70, 70));
		coin[i].setAlive(true);
		coin[i].setTexture(&coinTex);
		coin[i].setCollisionBox(sf::FloatRect(0, 0, 70, 70));
	}
	// calls coin position function to place all the coins
	coinPos();
}

CoinManager::~CoinManager()
{
}

void CoinManager::coinPos()
{
	// sets position for each coin
	coin[0].setPosition(2100, 300);
	coin[1].setPosition(2200, 300);
	coin[2].setPosition(2300, 300);
	coin[3].setPosition(1400, 300);
	coin[4].setPosition(1500, 300);
	coin[5].setPosition(1600, 300);
	coin[6].setPosition(2700, 200);
	coin[7].setPosition(2800, 200);
	coin[8].setPosition(2900, 200);
	coin[9].setPosition(4200, 100);
	coin[10].setPosition(4300, 100);
	coin[11].setPosition(6700, 0);
	coin[12].setPosition(5200, -200);
	coin[13].setPosition(5300, -200);
	coin[14].setPosition(5400, -200);
	coin[15].setPosition(6800, 0);
	coin[16].setPosition(6900, 0);
	coin[17].setPosition(8000, 420);
	coin[18].setPosition(8200, 420);
	coin[19].setPosition(9600, 0);
	coin[20].setPosition(9700, 0);
	coin[21].setPosition(9800, 0);
	coin[22].setPosition(10800, 300);
	coin[23].setPosition(10900, 300);
	coin[24].setPosition(11000, 300);
}


void CoinManager::update(float dt)
{
	//updates each coin thats alive
	for (int i = 0; i < coin.size(); i++)
	{
		if (coin[i].isAlive())
		{
			coin[i].update(dt);
		}
	}
}

void CoinManager::render(sf::RenderWindow* window)
{
	// draws each coin thats alive
	for (int i = 0; i < coin.size(); i++)
	{
		if (coin[i].isAlive())
		{
			window->draw(coin[i]);
		}
	}
}

// returns the coin that you want
std::vector<Coin>* CoinManager::getCoins()
{
	return &coin;
}
