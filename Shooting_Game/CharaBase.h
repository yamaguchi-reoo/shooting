#pragma once
#include"SphereCollider.h"
class CharaBase:public SphereCollider
{
protected:
	int image;
	float speed;
private:
	virtual void Update() = 0;

	virtual void Draw()const = 0;

	virtual void Hit() = 0;
};

