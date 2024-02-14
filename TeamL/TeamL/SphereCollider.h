#pragma once
#include"Collinder.h"

class SphereCollider
{
protected:

	int radius;			//”¼Œa

	Location location;

public:
	bool HitBox(const class Collinder* collider) const;

	//’†SÀ•W‚Ìæ“¾
	Location GetLocation()const;

};

