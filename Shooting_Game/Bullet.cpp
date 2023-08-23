#include "Bullet.h"
#include"PadInput.h"
#include"Player.h"
#include"Enemy.h"
#define _USE_MATH_DEFINES
#include"math.h"

Bullet::Bullet(int _x, int _y, int _r, int _speed, int _damege)
{
	location.x = _x;
	location.y = _y;
	location.r = _r;

	damege = _damege;
	speed = _speed;
	angle = 0.0f;
	acceleration = 0.0f;
	anglevelocity = 0.0f;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	location.x = location.x + speed;
}

void Bullet::Draw() const
{
	DrawCircle((int)location.x, (int)location.y, (int)location.r, 0xff0000, TRUE);
	//DrawCircle(location.x, location.y, location.r, 0xff000f, FALSE);
	DrawFormatString(10, 120, 0xffffff, "bullet %f", location.y);
	DrawFormatString(10, 140, 0xffffff, "bullet %f", location.x);
}

