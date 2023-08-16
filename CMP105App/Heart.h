#pragma once
#include "Framework/GameObject.h"
#include "Framework\Animation.h"
#include "Player.h"
class Heart : public GameObject
{
public:
	Heart();
	~Heart();

	void update(float dt);
	void collisionResponse(GameObject* collider);

	Animation heart;

	Player player;
};

