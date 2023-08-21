#include "GameOver.h"
#include "DxLib.h"
GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

AbstractScene* GameOver::Update()
{
	if (PadInput::OnButton(XINPUT_BUTTON_A)||KeyInput::OnKey(KEY_INPUT_SPACE)) {
		return new Title();
	}
	return this;
}

void GameOver::Draw() const
{
	SetFontSize(64);
	DrawString(520, 300, "GameOver", 0xff00000);
}
