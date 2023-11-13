#include "Bullet.h"
#include "Novice.h"
#include "CollisionSystem/CollisionConfig/CollisionConfig.h"
#include "CollisionSystem/CollisionManager/CollisionManager.h"

Bullet::Bullet(const Vector2& pos)
{
	pos_ = pos;
	radius_ = 10.0f;
	velocity_ = { 0.0f,-5.0f };
	color_ = 0xffffffff;

	InitCircle(pos_, radius_);
	SetCollisionAttribute(kCollisionAttributePlayer);
	SetCollisionMask(kCollisionAttributeEnemy);

	isDead_ = false;
}

void Bullet::OnCollision()
{
	isDead_ = true;
}

void Bullet::Init()
{
}

void Bullet::Update()
{
	pos_.y += velocity_.y;

	if (pos_.y + radius_ <= 0) {
		isDead_ = true;
	}

	circle_.SetPos(pos_);
	CollisionManager::GetInstance()->SetCollider(this);
}

void Bullet::Draw()
{
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, color_, kFillModeSolid);
}

bool Bullet::GetIsDead()
{
	return isDead_;
}
