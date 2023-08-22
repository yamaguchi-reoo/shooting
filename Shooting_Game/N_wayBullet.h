#pragma once
#include"BulletSpawner.h"
class N_wayBullet :public BulletSpawner
{
private:
	int null_bullets;// ”­Ë‚·‚é’e‚Ì”
	float base_angle;// ”­Ë‚·‚éÅ‰‚Ì’e‚ÌŒü‚«
	float angle_diff;// ’e“¯m‚ÌŠp“x·
public:
	void Shoot(GameMain* main, int _x, int _y)override;
};

