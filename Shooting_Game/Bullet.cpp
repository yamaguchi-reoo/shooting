#include "Bullet.h"
#include"PadInput.h"
#include"Player.h"
#include"Enemy.h"

Bullet::Bullet()
{
	flg = false;
	location.x = 0;
	location.y = 0;
	location.r = 5;

	damege = 0;
	speed = 5;
	angle = 0.0f;
	acceleration = 0.0f;
	anglevelocity = 0.0f;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	//プレイヤーの弾
	PlayerBullet();
}

void Bullet::Draw() const
{
	if (flg == true) {
		DrawCircle((int)location.x, (int)location.y, (int)location.r, 0xff0000, TRUE);
	}
	//DrawCircle(location.x, location.y, location.r, 0xff000f, FALSE);
	DrawFormatString(10, 100, 0xffffff, "bullet %d", flg);
	DrawFormatString(10, 120, 0xffffff, "bullet %f", location.y);
	DrawFormatString(10, 140, 0xffffff, "bullet %f", location.x);
}

void Bullet::PlayerBullet()
{
	if (flg == false) {
		location.x = Player::LocationX;
	}
	//bの端を押したら弾発射
	if (PadInput::OnPressed(XINPUT_BUTTON_B) || KeyInput::OnPresed(KEY_INPUT_B)) {
		flg = true;
	}
	if (flg == true)
	{
		location.y -= speed;
		if (location.y < 0)
		{
			flg = false;
			location.y = Player::LocationY - 50;
		}
	}
}
