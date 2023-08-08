#pragma once
struct Location {
	float x;
	float y;
	float r;
};
class SphereCollider {
protected:
	Location location;
	//int radius;
public:
	SphereCollider();
	bool HitSphere(SphereCollider* spherecollider)const;
};

