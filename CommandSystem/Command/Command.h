#pragma once

class Player;

class ICommand
{
public:
	virtual ~ICommand();
	// 実行
	virtual void Exec(Player& player) = 0;
};

class MoveRightCommand : public ICommand 
{
public:
	void Exec(Player& player) override;
};

class MoveLeftCommand : public ICommand
{
public:
	void Exec(Player& player) override;
};

