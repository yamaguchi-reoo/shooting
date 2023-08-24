#pragma once
#include"SphereCollider.h"


class Bullet : public SphereCollider
{
private:
	int damege;//ダメージ
	int speed;//速度
	float angle;//角度
	int who;//誰が弾を撃ったか
	float acceleration;//速度の変化量
	float anglevelocity;//角度の変化量y;
public:
	Bullet(int _x, int _y, int _r, int _speed, int _damege, int _who);
	~Bullet();

	void Update();
	void Draw()const;

	int GetLocation();
};

