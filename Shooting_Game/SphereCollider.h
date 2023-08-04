#pragma once
struct Location {
	float x;
	float y;
};
class SphereCollider {
protected:
	Location location;
	int radius;
public:
	SphereCollider();
	bool HitSphere(SphereCollider* spherecollider)const;
};

