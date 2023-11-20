#include "StageScene.h"
#include "Novice.h"

StageScene::StageScene()
{
	player_ = std::make_unique<Player>();
	inputHandler_ = std::make_unique<InputHandler>();

	inputHandler_->AssignMoveLeftCommand2PressingKeyA();
	inputHandler_->AssignMoveRightCommand2PressingKeyD();
}

void StageScene::Init()
{
	player_->Init();
}

void StageScene::Update()
{

	ICommand* command = inputHandler_->HandleInput();

	if (command) {
		command->Exec(*player_.get());
	}

	player_->Update();

}

void StageScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x99ff99ff, kFillModeSolid);

	Novice::ScreenPrintf(0, 16, "Press AD : Move");

	player_->Draw();
}
