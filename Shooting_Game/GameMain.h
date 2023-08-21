#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"GameOver.h"
class GameMain :
    public AbstractScene{
private:
    Player* player;//プレイヤー 
    Enemy* enemy[8];//エネミー
    Bullet* bullet;//弾

    int life;//残機
public:
    // コンストラクタ
    GameMain();

    // デストラクタ
    ~GameMain();

    // 描画以外の更新を実装
    AbstractScene* Update() override;

    // 描画に関することを実装
    void Draw() const override;

    void HitChaeck();
};

