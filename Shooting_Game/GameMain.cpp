#include "GameMain.h"

GameMain::GameMain()
{
	player = new Player();
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i] = nullptr;
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		int Rand = GetRand(4);
		enemy[i] = new Enemy(Rand * 100, i * 80 /** Rand * 100*/ /** ENEMY_DISTANCE*/);
	}

	life = 1;
	hit_time = 0;
	hit_flg = false;
	flash_flg = true;

	total_score = 0;
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
		if (bullet[i] != nullptr) {
			bullet[i]->Update();
		}	
	}
	//弾が画面外に行くと削除
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			if (bullet[i]->GetLocation() >= SCREEN_WIDTH || bullet[i]->GetLocation() <= 0) {
				bullet[i] = nullptr;
			}
		}
	}
	//エネミーの更新処理
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Update(this);
	}

	//ダメージを受けたら点滅
	if (hit_flg == true) {
		if (++hit_time % 20 == 0) {
			flash_flg =! flash_flg;
		}
		if (hit_time >= 120) {
			hit_flg = false;
			hit_time = 0;
		}
	}

	//当たった時の処理
	HitCheck();
	//ライフが0でゲームオーバーへ
	if (life < 0) {
		return new GameOver();
	}
	//画面内にエネミーがいるか
	if (EnemyCheck() == 0) {
		return new GameClear();
	}

	return this;
}

void GameMain::Draw() const
{
	//残機の描画
	//DrawFormatString(60, 10, 0xffffff, "%d", life);
	// スコア描画
	DrawFormatString(400, 10, 0xffffff, "%d", total_score);
	//敵の描画
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Draw();
	}
	//プレイヤーの描画
	if (flash_flg == true) {
		player->Draw();
	}
	//弾の描画
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}
	DrawFormatString(10, 190, 0xffffff, "%d", hit_time);
	DrawFormatString(10, 210, 0xffffff, "%d", hit_flg);
	DrawFormatString(10, 230, 0xffffff, "%d", flash_flg);
}

void GameMain::HitCheck()
{
	//プレイヤーと敵が当たったらフラグをtrueに...
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (player->HitSphere(enemy[i]) == (int)true) {
			player->Hit();
			////life--;
		}
		else {
			player->PlayerFlg();
		}
	}
	//プレイヤーの弾が敵と当たった時の処理
	for (int i = 0; i < ENEMY_MAX; i++) {
		for (int j = 0; j < BULLET_MAX; j++) {
			if (bullet[j] != nullptr) {
				if (bullet[j]->HitSphere(enemy[i]) == (int)true && bullet[j]->GetWho() == 0) {
					enemy[i]->Hit();
					total_score += 20;//enemy[i]->GetScore();
				}
			}
		}
	}
	//エネミーの弾がプレイヤーに当たった時
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			if (bullet[i]->HitSphere(player) == (int)true && bullet[i]->GetWho() == 1 && hit_flg == false) {
				//life--;
				hit_flg = true;
			}
		}
	}
}
void GameMain::BulletSpawn(int _x, int _y, int _r, int _speed, int _damege,int _who)
{
	//bulletが空だったら引数を渡す
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] == nullptr) {
			bullet[i] = new Bullet(_x, _y, _r, _speed, _damege,_who);
			break;
		}
	}
}
int GameMain::EnemyCheck()
{
	//エネミーが画面にいたら-1、いなかったら0を返す
	for (int i = 0; i < ENEMY_MAX; i++){
		if (enemy[i]->GetFlg() == false) {
			return -1;
		}
	}
	return 0;
}
