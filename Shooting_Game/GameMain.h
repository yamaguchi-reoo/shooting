#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"GameOver.h"
#include"GameClear.h"
class GameMain :
    public AbstractScene{
private:
    Player* player;//プレイヤー 
    Enemy* enemy[ENEMY_MAX];//エネミー
    Bullet* bullet[BULLET_MAX];//弾

    int life;//残機
    //bool spawn_flg;
    //bool CheckSpawn[8];
public:
    // コンストラクタ
    GameMain();

    // デストラクタ
    ~GameMain();

    // 描画以外の更新を実装
    AbstractScene* Update() override;

    // 描画に関することを実装
    void Draw() const override;
    //弾/プレイヤー/敵の当たり判定のチェック
    void HitCheck();
    //弾の配列に新しくデータを作成する
    void BulletSpawn();
    //エネミーがいるかいないか確認
    int EnemyCheck();
};

