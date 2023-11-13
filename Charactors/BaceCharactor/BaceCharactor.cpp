#include "BaceCharactor.h"
#include "Novice.h"
#include "CollisionSystem/CollisionManager/CollisionManager.h"

void BaceCharactor::Init()
{
}

void BaceCharactor::Update()
{
	
	CollisionManager::GetInstance()->SetCollider(this);
}

void BaceCharactor::Draw()
{
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, color_, kFillModeSolid);
}
