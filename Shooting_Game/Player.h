#pragma once
#include "CharaBase.h"
#include "PadInput.h"
#include "SphereCollider.h"
#include "N_wayBullet.h"
//仮想クラス
class N_wayBullet;

class Player :public CharaBase
{
private:
	N_wayBullet* warpon;
	bool flg;//フラグ
	int span;
public:
	Player();
	~Player();

	void Update(GameMain* main)override;
	void Draw() const override;
	void Hit() override;
	void PlayerFlg();
public:
	static float LocationX;
	static float LocationY;
};

