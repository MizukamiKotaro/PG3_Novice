#pragma once
#include "Charactors/BaceCharactor/BaceCharactor.h"

class Enemy : public BaceCharactor
{
public:

	Enemy();

	void Init() override;

	void Update() override;

	void OnCollision() override;

	bool GetIsDead() const;

private:

	bool isDead_;
};

