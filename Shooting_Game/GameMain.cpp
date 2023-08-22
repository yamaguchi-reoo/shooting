#include "GameMain.h"

GameMain::GameMain()
{
	player = new Player();
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i] = new Bullet();
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		int Rand = GetRand(4);
		enemy[i] = new Enemy(Rand * 100, i * Rand * 100 /** ENEMY_DISTANCE*/);
	}

	life = 1;
}

GameMain::~GameMain()
{
	delete player;
	for (int i = 0; i < ENEMY_MAX; i++) {
		delete enemy[i];
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		delete bullet[i];
	}
}

AbstractScene* GameMain::Update()
{
	//プレイヤーの更新処理
	player->Update();
	//弾の更新処理
	for (int i = 0; i <BULLET_MAX; i++) {
		bullet[i]->Update();
	}
	//エネミーの更新処理
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Update();
	}
	//当たった時の処理
	HitCheck();
	//ライフが0でゲームオーバーへ
	if (life < 0) {
		return new GameOver();
	}

	if (EnemyCheck() == 0) {
		return new GameClear();
	}

	return this;
}

void GameMain::Draw() const
{
	//残機の描画
	//DrawFormatString(60, 10, 0xffffff, "%d", life);
	//敵の描画
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Draw();
	}
	//プレイヤーの描画
	player->Draw();
	//弾の描画
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i]->Draw();
	}
}

void GameMain::HitCheck()
{
	//プレイヤーと敵が当たったらフラグをtrueに...
	for (int i = 0; i < ENEMY_MAX; i++) {
		for (int j = 0; j < BULLET_MAX; j++) {
			if (player->HitSphere(enemy[i]) == (int)true) {
				player->Hit();
				//life--;
			}
			else {
				player->PlayerFlg();
			}
			if (bullet[j]->HitSphere(enemy[i]) == (int)true && bullet[j]->GetFlg() == (int)true) {
				enemy[i]->Hit();
			}
		}
	}
}

void GameMain::BulletSpawn()
{
}

int GameMain::EnemyCheck()
{
	for (int i = 0; i < ENEMY_MAX; i++){
		if (enemy[i]->GetFlg() == false) {
			return -1;
		}
	}
	return 0;
}
