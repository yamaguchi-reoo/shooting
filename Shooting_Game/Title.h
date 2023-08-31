#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
    int MenuNumber;//カーソル用変数
    //int Image;//画像用変数
public:
    // コンストラクタ
    Title();

    // デストラクタ
    ~Title();

    // 描画以外の更新を実装
    AbstractScene* Update() override;

    // 描画に関することを実装
    void Draw() const override;
};

