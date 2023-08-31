#pragma once
#include "AbstractScene.h"
class End :
    public AbstractScene
{
private:
    int wait_time;
    int end_pos;
public:
    End();
    ~End();

    // 描画以外の更新を実装
    AbstractScene* Update() override;

    // 描画に関することを実装
    void Draw() const override;
};

