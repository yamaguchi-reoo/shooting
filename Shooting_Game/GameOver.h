#pragma once
#include"AbstractScene.h"
#include"PadInput.h"
#include"Title.h"
class GameOver:public AbstractScene
{
private:
public:
	GameOver();
	~GameOver();

	AbstractScene* Update() override;

	// •`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ðŽÀ‘•
	void Draw() const override;
};

