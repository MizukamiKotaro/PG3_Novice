#include "Command.h"
#include "Charactors/Player/Player.h"

ICommand::~ICommand()
{
}

void MoveRightCommand::Exec(Player& player)
{
	player.MoveRight();
}

void MoveLeftCommand::Exec(Player& player)
{
	player.MoveLeft();
}
