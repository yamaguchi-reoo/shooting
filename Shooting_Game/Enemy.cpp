#include "Enemy.h"
#include "DxLib.h"

float Enemy::EnemyLocationX;

Enemy::Enemy(int pos_x,int pos_y)
{
	warpon = new N_wayBullet();
	location.x = (float)pos_x + 1300;//_x;
	location.y = (float)pos_y + 80;
	location.r = 21;

	speed = 10;
	flg = false;
	spawn_flg = true;
	enemy_type = -1;
	span = 0;
}

Enemy::~Enemy()
{
}

void Enemy::Update(GameMain* main)
{
	//ÉXÉ|Å[ÉìÇµÇƒÇ¢ÇÈÇ»ÇÁç∂Ç…å¸Ç©Ç¡ÇƒÇ≠ÇÈ
	if (spawn_flg == true){
		location.x = location.x - speed;
		//location.y = 0;
	}

	if (location.x < -20) {
		int Rand = GetRand(700);
		location.x = (float)Rand + 1300.0f;;
		location.y = (float)Rand + 80.0f;
	}
	if (PadInput::OnButton(XINPUT_BUTTON_A) || KeyInput::OnKey(KEY_INPUT_N)) {
		warpon->Shoot(main, (int)location.x, (int)location.y, 1);
	}

}

void Enemy::Draw() const
{
	if (spawn_flg == true && flg == false) {
		DrawCircle((int)location.x, (int)location.y, (int)location.r, 0x00ffff, TRUE);
	}
	if (flg == true) {
		DrawString(80, 25, "HIT!!!!!!!", 0xffffff);
	}
	DrawFormatString(150, 10, 0xffffff, "%f", location.y);
}

void Enemy::Hit()
{
	flg = true;
	spawn_flg = false;

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
	location.x = (float)_x;
}
int Enemy::GetLocation()
{
	return (int)location.x;
}

int Enemy::GetFlg()
{
	return flg;
}
