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

	// 描画に関することを実装
	void Draw() const override;
};

