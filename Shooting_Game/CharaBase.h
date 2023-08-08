#pragma once
class CharaBase
{
protected:
	int image;
	float speed;
private:
	virtual void Update();

	virtual void Draw()const;

	virtual void Hit();
};

