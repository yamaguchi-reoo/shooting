#include "GameMain.h"

GameMain::GameMain()
{
	player = new Player();
	enemy = new Enemy();
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	player->Update();
	return this;
}

void GameMain::Draw() const
{
	enemy->Draw();
	player->Draw();
}
