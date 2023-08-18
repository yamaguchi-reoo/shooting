#pragma once
#include"SphereCollider.h"
class Bullet : public SphereCollider
{
private:
	bool flg;
	int damege;//ダメージ
	int speed;//速度
	float angle;//角度
	float acceleration;//速度の変化量
	float anglevelocity;//角度の変化量
public:
	Bullet();
	~Bullet();

	void Update();
	void Draw()const;
};

