#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
class GameMain :
    public AbstractScene{
private:
    Player* player;
    Enemy* enemy;
    Bullet* bullet;
public:
    // コンストラクタ
    GameMain();

    // デストラクタ
    ~GameMain();

    // 描画以外の更新を実装
    virtual AbstractScene* Update() override;

    // 描画に関することを実装
    virtual void Draw() const override;

    void HitChaeck();
};

