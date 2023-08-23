#pragma once
#include"SphereCollider.h"

#define BULLET_MAX 20
#define BULLET_DISTANCE 50

class Bullet : public SphereCollider
{
private:
	int damege;//ダメージ
	int speed;//速度
	float angle;//角度
	float acceleration;//速度の変化量
	float anglevelocity;//角度の変化量y;
public:
	Bullet(int _x, int _y, int _r, int _speed, int _damege);
	~Bullet();

	void Update();
	void Draw()const;
};

