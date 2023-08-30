#include "GameMain.h"

GameMain::GameMain()
{
	player = new Player();
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i] = nullptr;
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		int Rand = GetRand(4);
		enemy[i] = new Enemy(Rand * 100, i * 80 /** Rand * 100*/ /** ENEMY_DISTANCE*/);
	}

	life = 1;
	hit_time = 0;
	hit_flg = false;
	flash_flg = true;

	total_score = 0;
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
	player->Update(this);
	//�e�̍X�V����
	for (int i = 0; i <BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Update();
		}	
	}
	//�e����ʊO�ɍs���ƍ폜
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			if (bullet[i]->GetLocation() >= SCREEN_WIDTH || bullet[i]->GetLocation() <= 0) {
				bullet[i] = nullptr;
			}
		}
	}
	//�G�l�~�[�̍X�V����
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Update(this);
	}

	//�_���[�W���󂯂���_��
	if (hit_flg == true) {
		if (++hit_time % 20 == 0) {
			flash_flg =! flash_flg;
		}
		if (hit_time >= 120) {
			hit_flg = false;
			hit_time = 0;
		}
	}

	//�����������̏���
	HitCheck();
	//���C�t��0�ŃQ�[���I�[�o�[��
	if (life < 0) {
		return new GameOver();
	}
	//��ʓ��ɃG�l�~�[�����邩
	if (EnemyCheck() == 0) {
		return new GameClear();
	}

	return this;
}

void GameMain::Draw() const
{
	//�c�@�̕`��
	//DrawFormatString(60, 10, 0xffffff, "%d", life);
	// �X�R�A�`��
	DrawFormatString(400, 10, 0xffffff, "%d", total_score);
	//�G�̕`��
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i]->Draw();
	}
	//�v���C���[�̕`��
	if (flash_flg == true) {
		player->Draw();
	}
	//�e�̕`��
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}
	DrawFormatString(10, 190, 0xffffff, "%d", hit_time);
	DrawFormatString(10, 210, 0xffffff, "%d", hit_flg);
	DrawFormatString(10, 230, 0xffffff, "%d", flash_flg);
}

void GameMain::HitCheck()
{
	//�v���C���[�ƓG������������t���O��true��...
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (player->HitSphere(enemy[i]) == (int)true) {
			player->Hit();
			////life--;
		}
		else {
			player->PlayerFlg();
		}
	}
	//�v���C���[�̒e���G�Ɠ����������̏���
	for (int i = 0; i < ENEMY_MAX; i++) {
		for (int j = 0; j < BULLET_MAX; j++) {
			if (bullet[j] != nullptr) {
				if (bullet[j]->HitSphere(enemy[i]) == (int)true && bullet[j]->GetWho() == 0) {
					enemy[i]->Hit();
					total_score += 20;//enemy[i]->GetScore();
				}
			}
		}
	}
	//�G�l�~�[�̒e���v���C���[�ɓ���������
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			if (bullet[i]->HitSphere(player) == (int)true && bullet[i]->GetWho() == 1 && hit_flg == false) {
				//life--;
				hit_flg = true;
			}
		}
	}
}
void GameMain::BulletSpawn(int _x, int _y, int _r, int _speed, int _damege,int _who)
{
	//bullet���󂾂����������n��
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] == nullptr) {
			bullet[i] = new Bullet(_x, _y, _r, _speed, _damege,_who);
			break;
		}
	}
}
int GameMain::EnemyCheck()
{
	//�G�l�~�[����ʂɂ�����-1�A���Ȃ�������0��Ԃ�
	for (int i = 0; i < ENEMY_MAX; i++){
		if (enemy[i]->GetFlg() == false) {
			return -1;
		}
	}
	return 0;
}
