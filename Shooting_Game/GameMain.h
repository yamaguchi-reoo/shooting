#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"GameOver.h"
#include"GameClear.h"
#include"common.h"

//仮想クラス
class Player;
class Enemy;

class GameMain :
    public AbstractScene{
private:
    Player* player;//プレイヤー 
    Enemy* enemy[ENEMY_MAX];//エネミー
    Bullet* bullet[BULLET_MAX];//弾

    int life;//残機

    int hit_time;//敵と当たった時の経過時間
    bool hit_flg;//当たったか当たってないかの判断フラグ
    bool flash_flg;//点滅
    int total_score;//合計スコア
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
    void BulletSpawn(int _x,int _y,int _r,int _speed,int _damege, int _who);
    //エネミーがいるかいないか確認
    int EnemyCheck();
};

