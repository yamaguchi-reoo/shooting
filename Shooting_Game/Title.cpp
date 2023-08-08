#include "Title.h"
#include "DxLib.h"
#include "PadInput.h"
#include "GameMain.h"
enum class MENU {
	GAME_MAIN = 0,
	RANKING,
	END
};
Title::Title(){
	MenuNumber = 0;
}

Title::~Title(){
   
}

AbstractScene* Title::Update(){
    //メニューカーソル移動処理
    if (PadInput::OnButton(XINPUT_BUTTON_DPAD_DOWN)|| KeyInput::OnKey(KEY_INPUT_DOWN)) {
        MenuNumber++;
        if (MenuNumber > 2) MenuNumber = 0;
    }
    if (PadInput::OnButton(XINPUT_BUTTON_DPAD_UP)|| KeyInput::OnKey(KEY_INPUT_UP)) {
        MenuNumber--;
        if (MenuNumber < 0) MenuNumber = 2;
    }

    if (PadInput::OnButton(XINPUT_BUTTON_A)|| KeyInput::OnKey(KEY_INPUT_A)) {
        switch (static_cast<MENU>(MenuNumber))
        {
        case MENU::GAME_MAIN:
            return new GameMain();
            break;
        case MENU::RANKING:
            //return new Ranking();
            break;
        case MENU::END:
            // return new End();
        default:
            break;
        }
    }
	return this;
}

void Title::Draw() const{
	DrawString(100, 100, "Title", 0xffffff);
    //メニューの描画
    SetFontSize(64);
    DrawString(730, 240, "すたーと", 0xffffff);
    DrawString(730, 320, "らんきんぐ", 0xffffff);
    DrawString(730, 400, "えんど", 0xffffff);

    DrawTriangle(230, 255 + MenuNumber * 55, 250, 270 + MenuNumber * 55, 230, 285 + MenuNumber * 55, GetColor(255, 0, 0), TRUE);

    SetFontSize(16);
}
