#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
//#include "bullet.h";
//#include "BulletManager.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void update(float dt);
	void handleInput(float dt);
	void collisionResponse(GameObject* collider, float dt );
	void groundCollision(GameObject* collider);
	void Jump(float dt);
	int getLives();
	int setLives(int i);
	int points;

protected:
	float gravity;
	sf::Vector2f direction;
	sf::Vector2f target;
	float speed;
	float scale;
	bool isJumping;
	bool facingLeft;
	int lives;

	Animation idle;
	Animation run;
	Animation jump;
	Animation die;
	Animation* currentAnimation;
};

