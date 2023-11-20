#include "InputHandler.h"
#include "InputManager/InputManager.h"

ICommand* InputHandler::HandleInput()
{
	InputManager* input = InputManager::GetInstance();
	if (input->PressingKey(DIK_A)) {
		return pressingKeyA_.get();
	}

	if (input->PressingKey(DIK_D)) {
		return pressingKeyD_.get();
	}

	return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressingKeyA()
{
	pressingKeyA_.reset();
	pressingKeyA_ = std::make_unique<MoveLeftCommand>();
}

void InputHandler::AssignMoveRightCommand2PressingKeyD()
{
	pressingKeyD_.reset();
	pressingKeyD_ = std::make_unique<MoveRightCommand>();
}
