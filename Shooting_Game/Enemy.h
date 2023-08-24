#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
#include "N_wayBullet.h"

//仮想クラス
class N_wayBullet;

class Enemy:public CharaBase
{
private:
	N_wayBullet* warpon;

	bool flg;		// フラグ
	int enemy_type;	// エネミーのタイプ(0..  1.. )
	bool spawn_flg;	// スポーン用フラグ
	int span;	//待ち時間
public:
	Enemy(int pos_x,int pos_y);
	~Enemy();

	void Update(GameMain* main)override;
	void Draw()const override;
	void Hit()override;

	//エネミーのスポーン
	void EnemySpwan();

	void SetLocation(int _y);
	//座標の取得
	int GetLocation();
	//
	int GetFlg();

public:
	static float EnemyLocationX;
};

