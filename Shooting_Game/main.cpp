#include"DxLib.h"
#include"SceneManager.h"
#include"common.h"
#include"Title.h"
#include"PadInput.h"
#include"fps.h"

//メインプログラム 開始

int WINAPI WinMain(_In_ HINSTANCE  hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR LpCmdLine, _In_ int NCmdShow) {
    SetMainWindowText("");         // ウィンドウタイトルを設定

    ChangeWindowMode(TRUE);                        // ウインドウモードで起動

    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32); // ウインドウのサイズ

    if (DxLib_Init() == -1) return -1;             // DXライブラリの初期化処理

    SetDrawScreen(DX_SCREEN_BACK);                 // 描画先画面を裏にする（ダブルバッファリング）

    // タイトル シーンオブジェクト作成
    SceneManager* sceneMng = new SceneManager((AbstractScene*) new Title());
    Fps fps;

    // ゲームループし、シーンマネジャーでシーンの更新
    while ((ProcessMessage() == 0) && (sceneMng->Update() != nullptr)) {
        ClearDrawScreen(); // 画面の初期化

        PadInput::UpdateKey();
        KeyInput::UpdateKey();
        fps.Update();	//更新
        fps.Draw();		//描画
        
        // シーンマネジャーでシーンの描画開始
        sceneMng->Draw();

        fps.Wait();
        ScreenFlip(); // 裏画面の内容を表画面に反映する
    };

    DxLib_End(); // DXライブラリ使用の終了処理
    return 0;    // プログラムの終了
};