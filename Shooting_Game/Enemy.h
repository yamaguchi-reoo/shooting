#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
class Enemy:public CharaBase
{
	bool flg;
private:
public:
	Enemy();
	~Enemy();

	void Update()override;
	void Draw()const override;
	void Hit()override;

};

