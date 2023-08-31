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
	DrawString(350, 170 + end_pos, "タイトル　　　Shooting", 0xFFFFFF);
	DrawString(350, 220 + end_pos, "バージョン　　1.0", 0xFFFFFF);
	DrawString(350, 270 + end_pos, "最終更新日　　202x年xx月xx日", 0xFFFFFF);
	DrawString(350, 320 + end_pos, "制作者　　　　国際電子ビジネス専門学校", 0xFFFFFF);
	DrawString(350, 370 + end_pos, "　　　　　　　ＸＸＸ　ＸＸ", 0xFFFFFF);
	DrawString(350, 420 + end_pos, "素材利用", 0xFFFFFF);
	DrawString(350, 470 + end_pos, "　画像　　　 　イラストAC", 0xFFFFFF);
}
