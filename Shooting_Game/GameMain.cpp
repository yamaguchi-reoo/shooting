#include "GameMain.h"

GameMain::GameMain()
{
	player = new Player();
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i] = new Bullet();
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		int Rand = GetRand(700);
		enemy[i] = new Enemy(Rand,i * ENEMY_DISTANCE);
	}

	life = 1;
}

GameMain::~GameMain()
{
	delete player;
	for (int i = 0; i < ENEMY_MAX; i++) {
		delete enemy[i];
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		delete bullet[i];
	}
}

AbstractScene* GameMain::Update()
{
	//�v���C���[�̍X�V����
	player->Update();
	//�e�̍X�V����
	for (int i = 0; i <BULLET_MAX; i++) {
		bullet[i]->Update();
	}
	//�G�l�~�[�̍X�V����
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Update();
	}
	//�����������̏���
	HitCheck();
	
	/*if (life < 0) {
		return new GameOver();
	}*/

	return this;
}

void GameMain::Draw() const
{
	//�c�@�̕`��
	//DrawFormatString(60, 10, 0xffffff, "%d", life);
	//�G�̕`��
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Draw();
	}
	//�v���C���[�̕`��
	player->Draw();
	//�e�̕`��
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i]->Draw();
	}
}

void GameMain::HitCheck()
{
	//�v���C���[�ƓG������������t���O��true��...
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (player->HitSphere(enemy[i]) == (int)true) {
			player->Hit();
			life--;
		}
		else {
			player->PlayerFlg();
		}
		for (int j = 0; j < BULLET_MAX; j++) {
			if (bullet[j]->HitSphere(enemy[i]) == (int)true&&bullet[j]->GetFlg() == true) {
				enemy[i]->Hit();
			}
		}	
	}
}
