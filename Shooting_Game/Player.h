#pragma once
#include "CharaBase.h"
#include "PadInput.h"
#include"SphereCollider.h"
class Player:public CharaBase,SphereCollider
{
private:
public:
	Player();
	~Player();

	void Update()override;
	void Draw()const override;
	void Hit()override;
};

