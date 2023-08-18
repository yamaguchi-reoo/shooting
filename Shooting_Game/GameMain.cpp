#include "GameMain.h"

GameMain::GameMain()
{
	player = new Player();
	enemy = new Enemy();
	bullet = new Bullet();
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	//�v���C���[�̍X�V����
	player->Update();
	//�e�̍X�V����
	bullet->Update();
	//�v���C���[�ƓG������������t���O��true��...
	if (player->HitSphere(enemy) == true) {
		player->Hit();
	}
	else
	{
		player->PlayerFlg();
	}
	if (bullet->HitSphere(enemy) == true) {
		enemy->Hit();
	}
	
	return this;
}

void GameMain::Draw() const
{
	//�G�̕`��
	enemy->Draw();
	//�v���C���[�̕`��
	player->Draw();
	//�e�̕`��
	bullet->Draw();
}

void GameMain::HitChaeck()
{

}
