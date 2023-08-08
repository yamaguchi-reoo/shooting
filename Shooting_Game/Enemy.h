#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
class Enemy:public CharaBase,SphereCollider
{
	
private:
public:
	Enemy();
	~Enemy();

	void Update()override;
	void Draw()const override;
	void Hit()override;;

};

