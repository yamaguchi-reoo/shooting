#pragma once
struct Location {
	float x; // 中心座標(x)
	float y; // 中心座標(y)
	float r; // 半径
};
class SphereCollider {
protected:
	Location location;//当たり判定
	//int radius;
public:
	int HitSphere(SphereCollider* spherecollider);//当たり判定
	Location GetLocation();//中心座標を取得
};

