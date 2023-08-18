#pragma once
#include "CharaBase.h"
#include "PadInput.h"
#include"SphereCollider.h"
class Player :public CharaBase
{
private:
	int flg;//ƒtƒ‰ƒO
public:
	Player();
	~Player();

	void Update()override;
	void Draw() const override;
	void Hit() override;
	void PlayerFlg();
public:
	static float LocationX;
	static float LocationY;
};

