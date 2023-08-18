#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{
	location.x = 600;
	location.y = 200;
	location.r = 40;

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
	DrawCircle(location.x, location.y, location.r, 0x00ffff, FALSE);
	if (flg == true) {
		DrawString(80, 20, "HIT!!!!!!!", 0xffffff);
	}
}

void Enemy::Hit()
{
	flg = true;
}
