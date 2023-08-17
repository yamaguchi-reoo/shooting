#pragma once
#include"SphereCollider.h"
class Bullet : public SphereCollider
{
private:
	int damega;//ダメージ
	int speed;//速度
	float angle;//角度
	float acceleration;//速度の変化量
	float angulVelocity;//角度の変化量
public:
	void Update();
	void Draw()const;
};

