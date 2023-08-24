#pragma once
#include"GameMain.h"
//仮想クラス
class GameMain;

class BulletSpawner
{
protected:
	int speed;//速度
	float angle;//角度
	float acceleration;//速度の変化量
	float angle_velocity;//角度の変化量
public:
	virtual void Shoot(GameMain* main, int _x, int _y,int _who) = 0;
};

