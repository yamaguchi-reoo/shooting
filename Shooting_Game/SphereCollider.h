#pragma once
struct Location {
	float x; // ���S���W(x)
	float y; // ���S���W(y)
	float r; // ���a
};
class SphereCollider {
protected:
	Location location;//�����蔻��
	//int radius;
public:
	int HitSphere(SphereCollider* spherecollider);//�����蔻��
	Location GetLocation();//���S���W���擾
};

