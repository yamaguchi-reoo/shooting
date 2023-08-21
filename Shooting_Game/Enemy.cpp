#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy(int _x,int _type)
{
	location.x = _x;
	location.y = 200;
	location.r = 20;

	enemy_type = _type;

	flg = false;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	
}

void Enemy::Draw() const
{
	if (enemy_type == 0) {
		DrawCircle(location.x, location.y, location.r, 0x00ffff, FALSE);
	}
	
	if (enemy_type == 1) {
		DrawCircle(location.x, location.y, location.r, 0xff00ff, FALSE);
	}
	if (flg == true) {
		DrawString(80, 20, "HIT!!!!!!!", 0xffffff);
	}
}

void Enemy::Hit()
{
	flg = true;
}
