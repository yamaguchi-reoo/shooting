#pragma once
#include"DxLib.h"

#define KEY_MAX 256
#define BUTTONS 16

//スティック
struct Stick
{
	short ThumbX;	//横軸値
	short ThumbY;	//縦軸値
};
class PadInput
{
private:
	static char NowKey[BUTTONS]; //今回の入力キー
	static char OldKey[BUTTONS]; //前回の入力キー
	static XINPUT_STATE Input; //パッド
	static Stick Rstick; //右スティック
	static Stick Lstick; //左スティック
private:
	//コンストラクタ
	PadInput() = default;
public:
	//パッド情報の更新
	static void UpdateKey()
	{
		// 入力キー取得
		GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
		for (int i = 0; i < BUTTONS; i++)
		{
			OldKey[i] = NowKey[i];
			NowKey[i] = Input.Buttons[i];
		}

		//右スティック
		Rstick.ThumbX = Input.ThumbRX;
		Rstick.ThumbY = Input.ThumbRY;

		//左スティック
		Lstick.ThumbX = Input.ThumbLX;
		Lstick.ThumbY = Input.ThumbLY;
	}

	//ボタンを押された瞬間
	static bool OnButton(int button)
	{
		bool ret = (NowKey[button] == 1 && OldKey[button] == 0);
		return ret;
	}

	//ボタンを押してる間
	static bool OnPressed(int button)
	{
		bool ret = (NowKey[button] == 1);
		return ret;
	}

	//ボタンを離した瞬間
	static bool OnRelease(int button)
	{
		bool ret = (NowKey[button] == 0 && OldKey[button] == 1);
		return ret;
	}

	//右スティックの取得
	static Stick GetRStick()
	{
		return Rstick;
	}

	//左スティックの取得
	static Stick GetLStick()
	{
		return Lstick;
	}
};
class KeyInput
{
private:
	static int NowKey[KEY_MAX];		//今回の入力キー
	static int OldKey[KEY_MAX];		//前回の入力キー
public:
	//パッド情報の更新
	static void UpdateKey() {
		// 入力キー取得
		for (int i = 0; i < KEY_MAX; i++) {
			OldKey[i] = NowKey[i];
			NowKey[i] = CheckHitKey(i);
		}
	}
	//ボタンを押した瞬間
	static bool OnKey(int key) {
		return (NowKey[key] == 1 && OldKey[key] == 0);
	}

	//ボタンを押した瞬間
	static bool OnPresed(int key) {
		return (NowKey[key] == 1);

	}
	//ボタンを押した瞬間
	static bool OnRelease(int key) {
		return (NowKey[key] == 0 && OldKey[key] == 1);
	}
};


