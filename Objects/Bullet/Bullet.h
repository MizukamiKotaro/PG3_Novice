#pragma once
#include "CollisionSystem/Collider/Collider.h"

class Bullet : public Collider
{
public:

	Bullet(const Vector2& pos);

	void OnCollision() override;

	void Init();

	void Update();

	void Draw();

	bool GetIsDead();

private:

	Vector2 pos_;
	float radius_;
	Vector2 velocity_;
	unsigned int color_;

	bool isDead_;
};

