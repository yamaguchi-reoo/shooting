#pragma once
class CharaBase
{
public:
	int image;
	float speed;
private:
	virtual void Update();

	virtual void Draw()const;


};

