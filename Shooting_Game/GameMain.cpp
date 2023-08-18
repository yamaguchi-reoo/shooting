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
	//プレイヤーの更新処理
	player->Update();
	//弾の更新処理
	bullet->Update();
	//プレイヤーと敵が当たったらフラグをtrueに...
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
	//敵の描画
	enemy->Draw();
	//プレイヤーの描画
	player->Draw();
	//弾の描画
	bullet->Draw();
}

void GameMain::HitChaeck()
{

}
