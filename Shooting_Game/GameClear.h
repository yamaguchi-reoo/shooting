#pragma once
#include "AbstractScene.h"
#include "PadInput.h"
#include "Title.h"

class GameClear :
    public AbstractScene
{
private:
public:
    GameClear();
    ~GameClear();

    AbstractScene* Update() override;

    // �`��Ɋւ��邱�Ƃ�����
    void Draw() const override;
};

