#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
class GameMain :
    public AbstractScene{
private:
    Player* player;
    Enemy* enemy;
    Bullet* bullet;
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

