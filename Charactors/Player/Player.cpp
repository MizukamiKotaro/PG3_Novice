#include "Player.h"
#include <cmath>
#include "Novice.h"

Player::Player()
{
	pos_ = { 640.0f,360.0f };
	radius_ = 15.0f;
	velocity_ = {};
	moveSpeed_ = { 5.0f,5.0f };
	color_ = 0xffffccff;
}

void Player::Init()
{
	pos_ = { 640.0f,360.0f };
	circle_.SetPos(pos_);
}

void Player::Update()
{
	pos_.x += velocity_.x;
	pos_.y += velocity_.y;

	velocity_ = {};
}

void Player::Draw()
{
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, color_, kFillModeSolid);
}

void Player::OnCollision()
{
	Init();
}

void Player::MoveRight()
{
	velocity_.x += moveSpeed_.x;
}

void Player::MoveLeft()
{
	velocity_.x -= moveSpeed_.x;
}
