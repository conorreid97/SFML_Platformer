#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include "Player.h"
using namespace sf;

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();
	void setPlayer(Player* p);
	void update(float dt);
	void collisionResponse(GameObject* collider, float dt);
	void groundCollision(GameObject* collider);

	Vector2f setDirection(Vector2f, Vector2f);
	bool seePlayer;
	bool hitTarget1;
	bool hitTarget2;

protected:
	Animation idle;
	Animation run;
	Animation attack;
	Animation* currentAnimation;

	float scale;
	float gravity;
	Vector2f direction;
	float targetDistance;
	Vector2f target2;
	Vector2f playerTarget;
	Player* player;

	float speed;
	float acceleration;
};

