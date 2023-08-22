#pragma once
#include"GameMain.h"
class GameMain;

class BulletSpawner
{
protected:
	int speed;//‘¬“x
	float angle;//Šp“x
	float acceleration;//‘¬“x‚Ì•Ï‰»—Ê
	float angle_velocity;//Šp“x‚Ì•Ï‰»—Ê
public:
	virtual void Shoot(GameMain* main, int _x, int _y) = 0;
};

