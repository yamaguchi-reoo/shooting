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

	// �`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};

