#pragma once
#include"DxLib.h"

#define KEY_MAX 256
#define BUTTONS 16

//�X�e�B�b�N
struct Stick
{
	short ThumbX;	//�����l
	short ThumbY;	//�c���l
};
class PadInput
{
private:
	static char NowKey[BUTTONS]; //����̓��̓L�[
	static char OldKey[BUTTONS]; //�O��̓��̓L�[
	static XINPUT_STATE Input; //�p�b�h
	static Stick Rstick; //�E�X�e�B�b�N
	static Stick Lstick; //���X�e�B�b�N
private:
	//�R���X�g���N�^
	PadInput() = default;
public:
	//�p�b�h���̍X�V
	static void UpdateKey()
	{
		// ���̓L�[�擾
		GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
		for (int i = 0; i < BUTTONS; i++)
		{
			OldKey[i] = NowKey[i];
			NowKey[i] = Input.Buttons[i];
		}

		//�E�X�e�B�b�N
		Rstick.ThumbX = Input.ThumbRX;
		Rstick.ThumbY = Input.ThumbRY;

		//���X�e�B�b�N
		Lstick.ThumbX = Input.ThumbLX;
		Lstick.ThumbY = Input.ThumbLY;
	}

	//�{�^���������ꂽ�u��
	static bool OnButton(int button)
	{
		bool ret = (NowKey[button] == 1 && OldKey[button] == 0);
		return ret;
	}

	//�{�^���������Ă��
	static bool OnPressed(int button)
	{
		bool ret = (NowKey[button] == 1);
		return ret;
	}

	//�{�^���𗣂����u��
	static bool OnRelease(int button)
	{
		bool ret = (NowKey[button] == 0 && OldKey[button] == 1);
		return ret;
	}

	//�E�X�e�B�b�N�̎擾
	static Stick GetRStick()
	{
		return Rstick;
	}

	//���X�e�B�b�N�̎擾
	static Stick GetLStick()
	{
		return Lstick;
	}
};
class KeyInput
{
private:
	static int NowKey[KEY_MAX];		//����̓��̓L�[
	static int OldKey[KEY_MAX];		//�O��̓��̓L�[
public:
	//�p�b�h���̍X�V
	static void UpdateKey() {
		// ���̓L�[�擾
		for (int i = 0; i < KEY_MAX; i++) {
			OldKey[i] = NowKey[i];
			NowKey[i] = CheckHitKey(i);
		}
	}
	//�{�^�����������u��
	static bool OnKey(int key) {
		return (NowKey[key] == 1 && OldKey[key] == 0);
	}

	//�{�^�����������u��
	static bool OnPresed(int key) {
		return (NowKey[key] == 1);

	}
	//�{�^�����������u��
	static bool OnRelease(int key) {
		return (NowKey[key] == 0 && OldKey[key] == 1);
	}
};


