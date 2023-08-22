#include "GameMain.h"

GameMain::GameMain()
{
	player = new Player();
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i] = NULL;
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
	player->Update(this);
	//弾の更新処理
	for (int i = 0; i <BULLET_MAX; i++) {
		if (bullet[i] != NULL) {
			bullet[i]->Update();
		}	
	}
	//エネミーの更新処理
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Update(this);
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
		if (bullet[i] != NULL) {
			bullet[i]->Draw();
		}
	}
}

void GameMain::HitCheck()
{
	//プレイヤーと敵が当たったらフラグをtrueに...
	for (int i = 0; i < ENEMY_MAX; i++) {
		for (int j = 0; j < BULLET_MAX; j++) {
			if (bullet[i] != NULL) {
				if (player->HitSphere(enemy[i]) == (int)true) {
					player->Hit();
					//life--;
				}
				else {
					player->PlayerFlg();
				}
				if (bullet[j]->HitSphere(enemy[i]) == (int)true) {
					enemy[i]->Hit();
				}
			}
		}
	}
}
void GameMain::BulletSpawn(int _x, int _y, int _r, int _speed, int _damege)
{
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] == NULL) {
			bullet[i] = new Bullet(_x, _y, _r, _speed, _damege);
		}
		
	}
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
