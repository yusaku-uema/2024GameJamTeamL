#pragma once
#include"Collinder.h"

class SphereCollider
{
protected:

	int radius;			//���a

	Location location;

public:
	bool HitBox(const class Collinder* collider) const;

	//���S���W�̎擾
	Location GetLocation()const;

};

