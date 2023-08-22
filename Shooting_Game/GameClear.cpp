#include "GameClear.h"

GameClear::GameClear()
{
}

GameClear::~GameClear()
{
}

AbstractScene* GameClear::Update()
{
	if (PadInput::OnButton(XINPUT_BUTTON_A) || KeyInput::OnKey(KEY_INPUT_SPACE)) {
		return new Title();
	}
	return this;
}

void GameClear::Draw() const
{
	SetFontSize(64);
	DrawString(520, 300, "GameClear", 0xff00000);
}
