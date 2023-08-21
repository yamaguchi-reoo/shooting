#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"GameOver.h"
class GameMain :
    public AbstractScene{
private:
    Player* player;//�v���C���[ 
    Enemy* enemy[8];//�G�l�~�[
    Bullet* bullet;//�e

    int life;//�c�@
public:
    // �R���X�g���N�^
    GameMain();

    // �f�X�g���N�^
    ~GameMain();

    // �`��ȊO�̍X�V������
    AbstractScene* Update() override;

    // �`��Ɋւ��邱�Ƃ�����
    void Draw() const override;

    void HitChaeck();
};

