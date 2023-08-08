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
	if (player->HitSphere(enemy) == true) {
		player->Hit();
	}
	
	return this;
}

void GameMain::Draw() const
{
	enemy->Draw();
	player->Draw();
}

void GameMain::HitChaeck()
{

}
