#include "Player.h"
#include"PadInput.h"

Player::Player()
{
	location.x = 600;
	location.y = 420;
	location.r = 40;

	speed = 5;
}

Player::~Player()
{
}

void Player::Update()
{
	//右移動
	if (PadInput::GetLStick().ThumbX < -10000){
		speed = 4;
		location.x = location.x - speed;
	}
	//左移動
	if (PadInput::GetLStick().ThumbX > 10000) {
		speed = 4;
		location.x = location.x + speed;
	}
	//上移動
	if (PadInput::GetLStick().ThumbY > 10000) {
		speed = 4;
		location.y = location.y - speed;
	}
	//下移動
	if (PadInput::GetLStick().ThumbY < -10000) {
		speed = 4;
		location.y = location.y + speed;
	}
}
void Player::Draw() const
{
	DrawCircle(location.x, location.y, location.r, 0xff000f, TRUE);

	//DrawBox(40, 40, 90, 90, 0xffffff, FALSE);
}
void Player::Hit()
{
	
}
