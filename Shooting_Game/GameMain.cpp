#include "GameMain.h"

GameMain::GameMain()
{
	player = new Player();
	bullet = new Bullet(); 
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i] = new Enemy(i*200.0f,0);
	}

	life = 1;
}

GameMain::~GameMain()
{
	delete player;
	for (int i = 0; i < ENEMY_MAX; i++) {
		delete enemy[i];
	}
	delete bullet;
}

AbstractScene* GameMain::Update()
{
	//プレイヤーの更新処理
	player->Update();
	//弾の更新処理
	bullet->Update();
	//プレイヤーと敵が当たったらフラグをtrueに...
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (player->HitSphere(enemy[i]) == (int)true) {
			player->Hit();
			life--;
		}
		else {
			player->PlayerFlg();
		}
		if (bullet->HitSphere(enemy[i]) == (int)true) {
			enemy[i]->Hit();
		}
	}
	
	
	if (life < 0) {
		return new GameOver();
	}

	return this;
}

void GameMain::Draw() const
{
	//残機の描画
	DrawFormatString(60, 10, 0xffffff, "%d", life);
	//敵の描画
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Draw();
	}
	//プレイヤーの描画
	player->Draw();
	//弾の描画
	bullet->Draw();
	
}

void GameMain::HitChaeck()
{

}
