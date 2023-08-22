#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

#define ENEMY_MAX 8
#define ENEMY_DISTANCE 150

class Enemy:public CharaBase
{
	bool flg;		// フラグ
	int enemy_type;	// エネミーのタイプ(0..  1.. )
	bool spawn_flg;	// スポーン用フラグ
	int span;	//待ち時間
private:
public:
	Enemy(int pos_x,int pos_y);
	~Enemy();

	void Update()override;
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

