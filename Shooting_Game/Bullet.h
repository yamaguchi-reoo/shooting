#pragma once
#include"SphereCollider.h"
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
};

