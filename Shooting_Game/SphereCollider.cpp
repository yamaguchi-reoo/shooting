#include"SphereCollider.h"
#include<math.h>

int SphereCollider::HitSphere(SphereCollider* spherecollider){
	bool ret = false;

	float distance;
	distance = sqrtf(powf(spherecollider->GetLocation().x - location.x, 2) + powf(spherecollider->GetLocation().y - location.y, 2));
	
	if (distance < location.r + spherecollider->GetLocation().r) //“–‚½‚è”»’è
	{
		ret = true;
	}
	return ret;
}
Location SphereCollider::GetLocation()
{
	return location;
}
