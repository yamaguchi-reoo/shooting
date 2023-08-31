#include "Player.h"
#include"PadInput.h"
#define _USE_MATH_DEFINES
#include"math.h"

float Player::LocationX;
float Player::LocationY
;
Player::Player()
{
	warpon = new N_wayBullet();
	image = LoadGraph("images/player02.png");
	location.x = 600;
	location.y = 600;
	location.r = 35;

	speed = 4;
	span = 0;

	flg = false;
}
Player::~Player()
{
	delete warpon;
}
void Player::Update(GameMain* main)
{
	//右移動
	if (PadInput::GetLStick().ThumbX < -10000 || KeyInput::OnPresed(KEY_INPUT_A)) {
		//speed = 4;
		location.x = location.x - speed;
	}
	//左移動
	if (PadInput::GetLStick().ThumbX > 10000 || KeyInput::OnPresed(KEY_INPUT_D)) {
		//speed = 4;
		location.x = location.x + speed;
	}
	//上移動
	if (PadInput::GetLStick().ThumbY > 10000 || KeyInput::OnPresed(KEY_INPUT_W)) {
		//speed = 4;
		location.y = location.y - speed;
	}
	//下移動
	if (PadInput::GetLStick().ThumbY < -10000 || KeyInput::OnPresed(KEY_INPUT_S)) {
		//speed = 4;
		location.y = location.y + speed;
	}
	//下に当たったら止まる
	if (location.y > 720)
	{
		location.y = 720;
	}
	//上に当たったら止まる
	if (location.y < 22)
	{
		location.y = 22;
	}
	//左の壁に当たったら止まる
	if (location.x < 22)
	{
		location.x = 22;
	}
	//右の壁に当たったら止まる
	if (location.x > 1258)
	{
		location.x = 1258;
	}
	LocationX = location.x;
	LocationY = location.y;
	//Bボタンを押したら弾を発射
	if (PadInput::OnButton(XINPUT_BUTTON_B) || KeyInput::OnKey(KEY_INPUT_B)||PadInput::OnPressed(XINPUT_BUTTON_B)||KeyInput::OnPresed(KEY_INPUT_B)) {
		if (++span % 6 == 0) {
			warpon->Shoot(main, (int)location.x, (int)location.y, 0);
		}
		
	}
}
void Player::Draw() const
{
	DrawCircle((int)location.x, (int)location.y, (int)location.r, 0xff000f, FALSE);
	DrawRotaGraph((int)location.x, (int)location.y, 0.7, M_PI / 2, image, TRUE);
}
void Player::Hit()
{
	flg = true;
}

