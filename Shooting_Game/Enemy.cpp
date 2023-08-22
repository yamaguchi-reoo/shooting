#include "Enemy.h"
#include "DxLib.h"

float Enemy::EnemyLocationX;

Enemy::Enemy(int pos_x,int pos_y)
{
	location.x = pos_x + 1300;//_x;
	location.y = pos_y + 80;
	location.r = 31;

	speed = 10;
	flg = false;
	spawn_flg = true;
	enemy_type = -1;
	span = 0;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (spawn_flg == true){
		location.x = location.x - speed;
	}

	if (location.x < -20) {
		location.x = 1300.0f;
	}
}

void Enemy::Draw() const
{
	if (flg == false) {
		DrawCircle((int)location.x, (int)location.y, (int)location.r, 0x00ffff, FALSE);
	}
	if (flg == true) {
		DrawString(80, 25, "HIT!!!!!!!", 0xffffff);
	}
	DrawFormatString(150, 10, 0xffffff, "%f", location.y);
}

void Enemy::Hit()
{
	flg = true;
}

void Enemy::EnemySpwan()
{
	int Rand = GetRand(3);
	spawn_flg = true;
	enemy_type = Rand;
	location.y = 0;
	switch (Rand) {
	case 0:
		speed = 1;
		span = 100;
		break;
	case 1:
		break;
	}
}

void Enemy::SetLocation(int _x)
{
	location.x = (int)_x;
}
int Enemy::GetLocation()
{
	return location.x;
}
