#pragma once
#include"BulletSpawner.h"
class N_wayBullet :public BulletSpawner
{
private:
	int null_bullets;// ���˂���e�̐�
	float base_angle;// ���˂���ŏ��̒e�̌���
	float angle_diff;// �e���m�̊p�x��
public:
	void Shoot(GameMain* main, int _x, int _y)override;
};

