#include "Enemy.h"
#include "DxLib.h"

float Enemy::EnemyLocationX;

Enemy::Enemy(int pos_x,int pos_y)
{
	warpon = new N_wayBullet();

	location.x = (float)pos_x + 1300;//_x;
	location.y = (float)pos_y + 130;
	location.r = 21;

	speed = 4;
	flg = false;
	spawn_flg = true;
	enemy_type = -1;
	span = 0;

	score = 20;
}
Enemy::~Enemy()
{
	delete warpon;
}
void Enemy::Update(GameMain* main)
{
	//スポーンしているなら左に向かってくる
	if (spawn_flg == true){
		location.x = location.x - speed;
		//location.y = 0;
		if (++span % 60 == 0) {
			warpon->Shoot(main, (int)location.x, (int)location.y, 1);
		}
	}
	//x座標が-20よりた小さくなったらランダムリスポーン
	if (location.x < -20) {
		int Rand = GetRand(700);
		location.x = (float)Rand + 1300.0f;;
		location.y = (float)Rand + 80.0f;
	}
}

void Enemy::Draw() const
{
	if (spawn_flg == true && flg == false) {
		DrawCircle((int)location.x, (int)location.y, (int)location.r, 0x00ffff, TRUE);
	}
	if (flg == true) {
		//DrawString(80, 25, "HIT!!!!!!!", 0xffffff);
	}
}

void Enemy::Hit()
{
	flg = true;
	spawn_flg = false;

}
int Enemy::GetFlg()
{
	return flg;
}
int Enemy::GetScore()
{
	return score;
}
