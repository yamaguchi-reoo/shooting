#pragma once
class BulletsSpawner
{
protected:
	int speed;//���x
	float angle;//�p�x
	float acceleration;//���x�̕ω���
	float angulVelocity;//�p�x�̕ω���
public:
	virtual void Shoot();

};

