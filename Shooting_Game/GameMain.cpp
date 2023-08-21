#include "GameMain.h"

GameMain::GameMain()
{
	player = new Player();
	bullet = new Bullet(); 
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i] = new Enemy(i*200.0f,0);
	}

	life = 1;
}

GameMain::~GameMain()
{
	delete player;
	for (int i = 0; i < ENEMY_MAX; i++) {
		delete enemy[i];
	}
	delete bullet;
}

AbstractScene* GameMain::Update()
{
	//�v���C���[�̍X�V����
	player->Update();
	//�e�̍X�V����
	bullet->Update();
	//�v���C���[�ƓG������������t���O��true��...
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (player->HitSphere(enemy[i]) == (int)true) {
			player->Hit();
			life--;
		}
		else {
			player->PlayerFlg();
		}
		if (bullet->HitSphere(enemy[i]) == (int)true) {
			enemy[i]->Hit();
		}
	}
	
	
	if (life < 0) {
		return new GameOver();
	}

	return this;
}

void GameMain::Draw() const
{
	//�c�@�̕`��
	DrawFormatString(60, 10, 0xffffff, "%d", life);
	//�G�̕`��
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Draw();
	}
	//�v���C���[�̕`��
	player->Draw();
	//�e�̕`��
	bullet->Draw();
	
}

void GameMain::HitChaeck()
{

}
