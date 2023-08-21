#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

#define ENEMY_MAX 6
#define ENEMY_DISTANCE 200

class Enemy:public CharaBase
{
	bool flg;		// フラグ
	int enemy_type;	// エネミーのタイプ(0..  1.. )
	bool spawn_flg;	// スポーン用フラグ
	int span;	//待ち時間
private:
public:
	Enemy(int pos_x);
	~Enemy();

	void Update()override;
	void Draw()const override;
	void Hit()override;

	//エネミーのスポーン
	void EnemySpwan();

	void SetLocation(int _x);

	int GetLocation();
public:
	static float EnemyLocationX;
};

