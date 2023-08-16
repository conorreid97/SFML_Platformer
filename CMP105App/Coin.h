#pragma once
#include "Framework/GameObject.h"
#include "Framework\Animation.h"

class Coin : public GameObject
{
public:
	Coin();
	~Coin();
	
	void update(float dt);
	void collisionResponse(GameObject* collider);

	Animation coin;
};

