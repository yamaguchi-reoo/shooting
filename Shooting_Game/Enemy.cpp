#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{
	location.x = 800;
	location.y = 560;
	location.r = 40;
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
}

void Enemy::Hit()
{
}
