#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

#define ENEMY_MAX 8

class Enemy:public CharaBase
{
	bool flg;
	int enemy_type;
private:
public:
	Enemy(int _x,int _type);
	~Enemy();

	void Update()override;
	void Draw()const override;
	void Hit()override;

	//エネミーのスポーン
	void EnemySpwan();

};

