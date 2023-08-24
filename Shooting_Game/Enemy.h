#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
#include "N_wayBullet.h"

//���z�N���X
class N_wayBullet;

class Enemy:public CharaBase
{
private:
	N_wayBullet* warpon;

	bool flg;		// �t���O
	int enemy_type;	// �G�l�~�[�̃^�C�v(0..  1.. )
	bool spawn_flg;	// �X�|�[���p�t���O
	int span;	//�҂�����
public:
	Enemy(int pos_x,int pos_y);
	~Enemy();

	void Update(GameMain* main)override;
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

