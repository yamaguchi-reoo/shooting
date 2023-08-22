#pragma once
#include "CharaBase.h"
#include "PadInput.h"
#include "SphereCollider.h"
#include "BulletSpawner.h"
#include"N_wayBullet.h"
class N_wayBullet;

class Player :public CharaBase
{
private:
	N_wayBullet* warpon;
	bool flg;//ƒtƒ‰ƒO
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

