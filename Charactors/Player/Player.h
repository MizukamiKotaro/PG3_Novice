#pragma once
#include "Charactors/BaceCharactor/BaceCharactor.h"
#include "Objects/Bullet/Bullet.h"
#include <list>
#include <memory>

class Player : public BaceCharactor
{
public:

	Player();

	void Init() override;

	void Update() override;

	void Draw() override;

	void OnCollision() override;

	void MoveRight();
	void MoveLeft();

private:


};

