#pragma once
#define DIRECTINPUT_VERSION 0x0800 
#include <dinput.h>

class InputManager
{
public:

	static InputManager* GetInstance();

	void Init();

	void Update();

	bool PressedKey(BYTE keyNumber);

	bool PressingKey(BYTE keyNumber);

	bool ReleasedKey(BYTE keyNumber);

private:
	InputManager() = default;
	~InputManager() = default;
	InputManager(const InputManager&) = delete;
	const InputManager& operator=(const InputManager&) = delete;

private:
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};

