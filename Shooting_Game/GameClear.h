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

    // •`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ðŽÀ‘•
    void Draw() const override;
};

