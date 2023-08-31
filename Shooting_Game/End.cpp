#include "End.h"
#include "DxLib.h"

End::End()
{
	wait_time = 0;
	end_pos = 0;
}

End::~End()
{
}

AbstractScene* End::Update()
{
	if (++wait_time < 600) {
		end_pos = 300 - wait_time / 2;
	}
	if (++wait_time > 900) {
		return nullptr;
	}
	return this;
}

void End::Draw() const
{
	SetFontSize(32);
	DrawString(350, 170 + end_pos, "�^�C�g���@�@�@Shooting", 0xFFFFFF);
	DrawString(350, 220 + end_pos, "�o�[�W�����@�@1.0", 0xFFFFFF);
	DrawString(350, 270 + end_pos, "�ŏI�X�V���@�@202x�Nxx��xx��", 0xFFFFFF);
	DrawString(350, 320 + end_pos, "����ҁ@�@�@�@���ۓd�q�r�W�l�X���w�Z", 0xFFFFFF);
	DrawString(350, 370 + end_pos, "�@�@�@�@�@�@�@�w�w�w�@�w�w", 0xFFFFFF);
	DrawString(350, 420 + end_pos, "�f�ޗ��p", 0xFFFFFF);
	DrawString(350, 470 + end_pos, "�@�摜�@�@�@ �@�C���X�gAC", 0xFFFFFF);
}
