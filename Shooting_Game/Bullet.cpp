#include "Bullet.h"
#include"PadInput.h"
#include"Player.h"
#include"Enemy.h"
#define _USE_MATH_DEFINES
#include"math.h"

Bullet::Bullet(int _x, int _y, int _r, int _speed, int _damege, int _who)
{
	location.x = (float)_x;
	location.y = (float)_y;
	location.r = (float)_r;

	damege = _damege;
	speed = _speed;
	who = _who;
	angle = 0.0f;
	acceleration = 0.0f;
	anglevelocity = 0.0f;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (who == 0) {
		location.x = location.x + speed;
		location.r = 8.0f;
	}
	if (who == 1) {
		speed = 6;
		location.x = location.x - speed;
		location.r = 8.0f;
	}
}
void Bullet::Draw() const
{
	if (who == 0) {
		DrawCircle((int)location.x, (int)location.y, (int)location.r, 0xff0000, TRUE);
	}
	if (who == 1) {
		DrawCircle((int)location.x, (int)location.y, (int)location.r, 0x00ffff, TRUE);
	}
	//DrawCircle(location.x, location.y, location.r, 0xff000f, FALSE);
	DrawFormatString(10, 120, 0xffffff, "bullet %f", location.y);
	DrawFormatString(10, 140, 0xffffff, "bullet %f", location.x);
}
float Bullet::GetLocation()
{
	return location.x;
}
int Bullet::GetWho()
{
	return who;
}

