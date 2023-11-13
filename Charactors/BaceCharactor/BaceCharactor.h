#pragma once
#include "CollisionSystem/Collider/Collider.h"
#include "Vector2.h"

class BaceCharactor : public Collider
{
public:

	virtual void Init();

	virtual void Update();

	virtual void Draw();

protected:

	Vector2 pos_;
	float radius_;
	Vector2 velocity_;
	unsigned int color_;

};

