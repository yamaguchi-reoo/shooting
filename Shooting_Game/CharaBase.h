#pragma once
#include"SphereCollider.h"
class GameMain;

class CharaBase:public SphereCollider
{
protected:
	int image = 0;
	float speed = 0;
private:
	virtual void Update(GameMain* main) = 0;

	virtual void Draw()const = 0;

	virtual void Hit() = 0;
};

