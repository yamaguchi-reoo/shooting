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

    // •`‰æˆÈŠO‚ÌXV‚ğÀ‘•
    AbstractScene* Update() override;

    // •`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•
    void Draw() const override;
};

