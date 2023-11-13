#include "Player.h"
#include "CollisionSystem/CollisionConfig/CollisionConfig.h"
#include "CollisionSystem/CollisionManager/CollisionManager.h"
#include "InputManager/InputManager.h"
#include <cmath>
#include "Novice.h"

Player::Player()
{
	pos_ = { 640.0f,360.0f };
	radius_ = 15.0f;
	velocity_ = {};
	color_ = 0xffffccff;
}

void Player::Init()
{
	bullets_.clear();
	pos_ = { 640.0f,360.0f };
	circle_.SetPos(pos_);
}

void Player::Update()
{
	InputManager* input = InputManager::GetInstance();

	Vector2 move = {};

	if (input->PressingKey(DIK_A)) {
		move.x--;
	}
	if (input->PressingKey(DIK_D)) {
		move.x++;
	}
	if (input->PressingKey(DIK_W)) {
		move.y--;
	}
	if (input->PressingKey(DIK_S)) {
		move.y++;
	}

	float speed = 5.0f;

	if (move.x == 0 || move.y == 0) {
		velocity_.x = move.x * speed;
		velocity_.y = move.y * speed;
	}
	else {
		velocity_.x = move.x * speed / std::sqrtf(2.0f);
		velocity_.y = move.y * speed / std::sqrtf(2.0f);
	}

	pos_.x += velocity_.x;
	pos_.y += velocity_.y;

	if (input->PressedKey(DIK_SPACE)) {
		bullets_.push_back(new Bullet(pos_));
	}

	for (Bullet* bullet : bullets_) {
		bullet->Update();
	}

	bullets_.remove_if([](Bullet* bullet) {
		if (bullet->GetIsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});
}

void Player::Draw()
{
	for (Bullet* bullet : bullets_) {
		bullet->Draw();
	}
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, color_, kFillModeSolid);
}

void Player::OnCollision()
{
	Init();
}
