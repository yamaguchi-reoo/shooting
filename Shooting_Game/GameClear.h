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

    // 描画に関することを実装
    void Draw() const override;
};

