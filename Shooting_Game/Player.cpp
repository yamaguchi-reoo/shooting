#include "Player.h"
#include"PadInput.h"

float Player::LocationX;
float Player::LocationY
;
Player::Player()
{
	image = LoadGraph("images/player02.png");
	location.x = 600;
	location.y = 600;
	location.r = 50;

	speed = 4;

	flg = false;
}

Player::~Player()
{
}

void Player::Update()
{
	//âEà⁄ìÆ
	if (PadInput::GetLStick().ThumbX < -10000 || KeyInput::OnPresed(KEY_INPUT_A)) {
		//speed = 4;
		location.x = location.x - speed;
	}
	//ç∂à⁄ìÆ
	if (PadInput::GetLStick().ThumbX > 10000 || KeyInput::OnPresed(KEY_INPUT_D)) {
		//speed = 4;
		location.x = location.x + speed;
	}
	//è„à⁄ìÆ
	if (PadInput::GetLStick().ThumbY > 10000 || KeyInput::OnPresed(KEY_INPUT_W)) {
		//speed = 4;
		location.y = location.y - speed;
	}
	//â∫à⁄ìÆ
	if (PadInput::GetLStick().ThumbY < -10000 || KeyInput::OnPresed(KEY_INPUT_S)) {
		//speed = 4;
		location.y = location.y + speed;
	}
	//â∫Ç…ìñÇΩÇ¡ÇΩÇÁé~Ç‹ÇÈ
	if (location.y > 720)
	{
		location.y = 720;
	}
	//è„Ç…ìñÇΩÇ¡ÇΩÇÁé~Ç‹ÇÈ
	if (location.y < 22)
	{
		location.y = 22;
	}
	//ç∂ÇÃï«Ç…ìñÇΩÇ¡ÇΩÇÁé~Ç‹ÇÈ
	if (location.x < 22)
	{
		location.x = 22;
	}
	//âEÇÃï«Ç…ìñÇΩÇ¡ÇΩÇÁé~Ç‹ÇÈ
	if (location.x > 1258)
	{
		location.x = 1258;
	}
	LocationX = location.x;
	LocationY = location.y;
}
void Player::Draw() const
{
	DrawCircle(location.x, location.y, location.r, 0xff000f, FALSE);
	DrawGraph(location.x - 55, location.y - 45, image, TRUE);
	DrawFormatString(10, 40, 0xffffff, "%d",flg);
	DrawFormatString(10, 60, 0xffffff, "%f", location.y);
	DrawFormatString(10, 80, 0xffffff, "%f", location.x);
	if (flg == 1)
	{
		DrawString(10, 20, "HIT!!!!!!!",0xffffff);
	} 
}
void Player::Hit()
{
	flg = true;
}

void Player::PlayerFlg()
{
	flg = false;
}

