#pragma once

#include "CommandSystem/Command/Command.h"
#include <memory>

class InputHandler {
public:
	ICommand* HandleInput();

	// 2 = to
	void AssignMoveLeftCommand2PressingKeyA();
	void AssignMoveRightCommand2PressingKeyD();

private:
	std::unique_ptr<ICommand> pressingKeyA_;
	std::unique_ptr<ICommand> pressingKeyD_;

};

