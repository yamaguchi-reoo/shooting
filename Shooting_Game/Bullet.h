#pragma once
#include"SphereCollider.h"

#define BULLET_MAX 20
#define BULLET_DISTANCE 50

class Bullet : public SphereCollider
{
private:
	int damege;//�_���[�W
	int speed;//���x
	float angle;//�p�x
	float acceleration;//���x�̕ω���
	float anglevelocity;//�p�x�̕ω���y;
public:
	Bullet(int _x, int _y, int _r, int _speed, int _damege);
	~Bullet();

	void Update();
	void Draw()const;
};

