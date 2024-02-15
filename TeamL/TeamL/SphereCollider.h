#pragma once
#include"Collinder.h"

class SphereCollider
{
protected:

	int radius;			//半径

	Location location;

public:
	bool HitBox(const class Collinder* collider) const;

	//中心座標の取得
	Location GetLocation()const;

};

