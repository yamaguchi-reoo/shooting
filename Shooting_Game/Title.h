#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
    int MenuNumber;//�J�[�\���p�ϐ�
    int Image;//�摜�p�ϐ�
public:
    // �R���X�g���N�^
    Title();

    // �f�X�g���N�^
    ~Title();

    // �`��ȊO�̍X�V������
    virtual AbstractScene* Update() override;

    // �`��Ɋւ��邱�Ƃ�����
    virtual void Draw() const override;
};

