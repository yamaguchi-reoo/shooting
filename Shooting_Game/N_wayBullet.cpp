#include "N_wayBullet.h"

void N_wayBullet::Shoot(GameMain* main, int _x, int _y, int _who)
{
	main->BulletSpawn(_x, _y, 10, 7, 100,_who);


}
