#include "GameMain.h"

GameMain::GameMain()
{
	player = new Player();
	enemy = new Enemy();
	bullet = new Bullet();
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	//ƒvƒŒƒCƒ„[‚ÌXVˆ—
	player->Update();
	//’e‚ÌXVˆ—
	bullet->Update();
	//ƒvƒŒƒCƒ„[‚Æ“G‚ª“–‚½‚Á‚½‚çƒtƒ‰ƒO‚ðtrue‚É...
	if (player->HitSphere(enemy) == true) {
		player->Hit();
	}
	else
	{
		player->PlayerFlg();
	}
	if (bullet->HitSphere(enemy) == true) {
		enemy->Hit();
	}
	
	return this;
}

void GameMain::Draw() const
{
	//“G‚Ì•`‰æ
	enemy->Draw();
	//ƒvƒŒƒCƒ„[‚Ì•`‰æ
	player->Draw();
	//’e‚Ì•`‰æ
	bullet->Draw();
}

void GameMain::HitChaeck()
{

}
