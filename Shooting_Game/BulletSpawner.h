#pragma once
#include"GameMain.h"
//���z�N���X
class GameMain;

class BulletSpawner
{
protected:
	int speed;//���x
	float angle;//�p�x
	float acceleration;//���x�̕ω���
	float angle_velocity;//�p�x�̕ω���
public:
	virtual void Shoot(GameMain* main, int _x, int _y,int _who) = 0;
};

