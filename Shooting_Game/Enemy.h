#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

#define ENEMY_MAX 8
#define ENEMY_DISTANCE 150

class Enemy:public CharaBase
{
	bool flg;		// �t���O
	int enemy_type;	// �G�l�~�[�̃^�C�v(0..  1.. )
	bool spawn_flg;	// �X�|�[���p�t���O
	int span;	//�҂�����
private:
public:
	Enemy(int pos_x,int pos_y);
	~Enemy();

	void Update()override;
	void Draw()const override;
	void Hit()override;

	//�G�l�~�[�̃X�|�[��
	void EnemySpwan();

	void SetLocation(int _y);
	//���W�̎擾
	int GetLocation();
	//
	int GetFlg();

public:
	static float EnemyLocationX;
};

