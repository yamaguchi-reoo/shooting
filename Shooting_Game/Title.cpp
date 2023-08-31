#include "Title.h"
#include "DxLib.h"
#include "PadInput.h"
#include "GameMain.h"
#include "End.h"
enum class MENU {
	GAME_MAIN = 0,
    HELP,
	RANKING,
	END
};
Title::Title(){
	MenuNumber = 0;
}

Title::~Title(){
   
}

AbstractScene* Title::Update(){
    //���j���[�J�[�\���ړ�����
    if (PadInput::OnButton(XINPUT_BUTTON_DPAD_DOWN)|| KeyInput::OnKey(KEY_INPUT_DOWN)) {
        MenuNumber++;
        if (MenuNumber > 3) MenuNumber = 0;
    }
    if (PadInput::OnButton(XINPUT_BUTTON_DPAD_UP)|| KeyInput::OnKey(KEY_INPUT_UP)) {
        MenuNumber--;
        if (MenuNumber < 0) MenuNumber = 3;
    }

    if (PadInput::OnButton(XINPUT_BUTTON_A)|| KeyInput::OnKey(KEY_INPUT_A)) {
        switch (static_cast<MENU>(MenuNumber))
        {
        case MENU::GAME_MAIN:
            return new GameMain();
            break;
        case MENU::HELP:
            //return new Help();
            break;
        case MENU::RANKING:
            //return new Ranking();
            break;
        case MENU::END:
             return new End();
        default:
            break;
        }
    }
	return this;
}

void Title::Draw() const{
	DrawString(100, 100, "Title", 0xffffff);
    //���j���[�̕`��
    SetFontSize(64);
    DrawString(730, 240, "�����[��", 0xffffff);
    DrawString(730, 320, "�ւ��", 0xffffff);
    DrawString(730, 400, "��񂫂�", 0xffffff);
    DrawString(730, 480, "�����", 0xffffff);

    DrawTriangle(230, 255 + MenuNumber * 55, 250, 270 + MenuNumber * 55, 230, 285 + MenuNumber * 55, GetColor(255, 0, 0), TRUE);

}
