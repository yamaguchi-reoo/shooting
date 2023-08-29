#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"GameOver.h"
#include"GameClear.h"
#include"common.h"

//���z�N���X
class Player;
class Enemy;

class GameMain :
    public AbstractScene{
private:
    Player* player;//�v���C���[ 
    Enemy* enemy[ENEMY_MAX];//�G�l�~�[
    Bullet* bullet[BULLET_MAX];//�e

    int life;//�c�@

    int hit_time;//�G�Ɠ����������̌o�ߎ���
    bool hit_flg;//�����������������ĂȂ����̔��f�t���O
    bool flash_flg;//�_��
    int total_score;//���v�X�R�A
public:
    // �R���X�g���N�^
    GameMain();

    // �f�X�g���N�^
    ~GameMain();

    // �`��ȊO�̍X�V������
    AbstractScene* Update() override;

    // �`��Ɋւ��邱�Ƃ�����
    void Draw() const override;
    //�e/�v���C���[/�G�̓����蔻��̃`�F�b�N
    void HitCheck();
    //�e�̔z��ɐV�����f�[�^���쐬����
    void BulletSpawn(int _x,int _y,int _r,int _speed,int _damege, int _who);
    //�G�l�~�[�����邩���Ȃ����m�F
    int EnemyCheck();
};

