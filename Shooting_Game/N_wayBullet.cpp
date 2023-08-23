#include "N_wayBullet.h"

void N_wayBullet::Shoot(GameMain* main, int _x, int _y)
{
	main->BulletSpawn(_x, _y, 100, 7, 100);
}
