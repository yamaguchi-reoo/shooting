#pragma once
class BulletsSpawner
{
protected:
	int speed;//速度
	float angle;//角度
	float acceleration;//速度の変化量
	float angulVelocity;//角度の変化量
public:
	virtual void Shoot();

};

