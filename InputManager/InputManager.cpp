#include "InputManager.h"
#include "Novice.h"
#include <memory>

InputManager* InputManager::GetInstance()
{
	static InputManager instance;
	return &instance;
}

void InputManager::Init()
{
	keys[256] = { 0 };
	preKeys[256] = { 0 };
}

void InputManager::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

bool InputManager::PressedKey(BYTE keyNumber)
{

	if (!preKeys[keyNumber] && keys[keyNumber]) {
		return true;
	}
	return false;
}

bool InputManager::PressingKey(BYTE keyNumber)
{
	if (preKeys[keyNumber] && keys[keyNumber]) {
		return true;
	}
	return false;
}

bool InputManager::ReleasedKey(BYTE keyNumber)
{
	if (!preKeys[keyNumber] && !keys[keyNumber]) {
		return true;
	}
	return false;
}
