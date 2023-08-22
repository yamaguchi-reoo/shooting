#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"GameOver.h"
#include"GameClear.h"
class GameMain :
    public AbstractScene{
private:
    Player* player;//�v���C���[ 
    Enemy* enemy[ENEMY_MAX];//�G�l�~�[
    Bullet* bullet[BULLET_MAX];//�e

    int life;//�c�@
    //bool spawn_flg;
    //bool CheckSpawn[8];
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
    void BulletSpawn();
    //�G�l�~�[�����邩���Ȃ����m�F
    int EnemyCheck();
};

