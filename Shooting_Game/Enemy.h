#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

#define ENEMY_MAX 6
#define ENEMY_DISTANCE 200

class Enemy:public CharaBase
{
	bool flg;		// �t���O
	int enemy_type;	// �G�l�~�[�̃^�C�v(0..  1.. )
	bool spawn_flg;	// �X�|�[���p�t���O
	int span;	//�҂�����
private:
public:
	Enemy(int pos_x);
	~Enemy();

	void Update()override;
	void Draw()const override;
	void Hit()override;

	//�G�l�~�[�̃X�|�[��
	void EnemySpwan();

	void SetLocation(int _x);

	int GetLocation();
public:
	static float EnemyLocationX;
};

