#pragma once
#include"SphereCollider.h"

#define BULLET_MAX 20
#define BULLET_DISTANCE 50

class Bullet : public SphereCollider
{
private:
	bool flg;
	int damege;//�_���[�W
	int speed;//���x
	float angle;//�p�x
	float acceleration;//���x�̕ω���
	float anglevelocity;//�p�x�̕ω���
public:
	Bullet();
	~Bullet();

	void Update();
	void Draw()const;

	void PlayerBullet();

};

