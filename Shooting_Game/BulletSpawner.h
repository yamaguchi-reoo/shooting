#pragma once
class BulletSpawner
{
protected:
	int speed;//���x
	float angle;//�p�x
	float acceleration;//���x�̕ω���
	float angle_velocity;//�p�x�̕ω���
public:
	virtual void Shoot();
};

