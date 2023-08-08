#include"SphereCollider.h"
#include<math.h>

SphereCollider::SphereCollider(){
}
int SphereCollider::HitSphere(SphereCollider* spherecollider){
	bool ret = false;

	//プレイヤーの当たり判定の範囲
	float player_circle_x = location.x;
	float player_circle_y = location.y;
	float player_circle_radius = location.r;

	//エネミーの当たり判定の範囲
	float enemy_circle_x = spherecollider->location.x;
	float enemy_circle_y = spherecollider->location.y;
	float enemy_circle_radius = spherecollider->location.r;

	float a = player_circle_x - enemy_circle_x;
	float b = player_circle_x - enemy_circle_y;
	float c = sqrt(a * a + b * b);;

	if (c <= player_circle_radius + enemy_circle_radius)
	{
		return true;
	}
	return ret;
}