#pragma once
#include "AbstractScene.h"
class End :
    public AbstractScene
{
private:
    int wait_time;
    int end_pos;
public:
    End();
    ~End();

    // �`��ȊO�̍X�V������
    AbstractScene* Update() override;

    // �`��Ɋւ��邱�Ƃ�����
    void Draw() const override;
};

