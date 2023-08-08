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
	//‰EˆÚ“®
	if (PadInput::GetLStick().ThumbX < -10000){
		speed = 4;
		location.x = location.x - speed;
	}
	//¶ˆÚ“®
	if (PadInput::GetLStick().ThumbX > 10000) {
		speed = 4;
		location.x = location.x + speed;
	}
	//ãˆÚ“®
	if (PadInput::GetLStick().ThumbY > 10000) {
		speed = 4;
		location.y = location.y - speed;
	}
	//‰ºˆÚ“®
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
