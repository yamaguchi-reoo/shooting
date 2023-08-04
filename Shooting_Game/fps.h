#pragma once
#include"common.h"
#include"DxLib.h"

class Fps
{
private:
	int start_time;		//����J�n����
	int count;			//�J�E���g
	float fps;			//fps
	static const int average = 10;	//���ς��J�E���g��
	static const int frame = 60;//�t���[�����[�g�ݒ�
public:
	Fps()
	{
		start_time = 0;
		count = 0;
		fps = 0;
	}
	bool Update()
	{
		//1�t���[���ڂȂ玞�����L��
		if (count == 0)
		{
			start_time = GetNowCount();
		}
		//10�t���[���ڂȂ畽�ς��v�Z����
		if (count == average)
		{
			int t = GetNowCount();
			fps = 1000.f / ((t - start_time) / (float)average);;
			count = 0;
			start_time = t;
		}
		count++;
		return true;
	}
	void Draw()
	{
		//fps�`��
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", fps);
	}
	void Wait()
	{
		//������������
		int took_time = GetNowCount() - start_time;
		//�҂ׂ�����
		int wait_time = count * 1000 / frame - took_time;
		if (wait_time > 0)
		{
			//�ҋ@
			Sleep(wait_time);
		}
	}
};
#pragma once
