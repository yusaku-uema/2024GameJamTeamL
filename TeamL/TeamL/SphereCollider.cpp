#include "SphereCollider.h"
#define _USE_MATH_DEFINES
#include <math.h>


bool SphereCollider::HitBox(const Collinder* collider) const
{
	bool ret = false; //•Ô‚è’l
	float rad; //2“_‚ÌŠp“x
	float sphere_x; //‰~‚ÌÀ•W(x)
	float sphere_y; //‰~‚ÌÀ•W(y)

	//‘ŠŽè‚Ì“–‚½‚è”»’è‚Ì”ÍˆÍ
	float sub_x[2];
	float sub_y[2];

	//Šp“x‚ÌŒvŽZ
	rad = atan2f(collider->GetLocation().y - location.y, collider->GetLocation().x - location.x);

	//À•W‚ÌŒvŽZ
	sphere_x = location.x + (radius * cosf(rad));
	sphere_y = location.y + (radius * sinf(rad));

	//‘ŠŽè‚Ì“–‚½‚è”»’è‚Ì”ÍˆÍ‚ÌŒvŽZ
	sub_x[0] = collider->GetLocation().x - (collider->GetArea().width / 2);
	sub_y[0] = collider->GetLocation().y - (collider->GetArea().height / 2);
	sub_x[1] = sub_x[0] + collider->GetArea().width;
	sub_y[1] = sub_y[0] + collider->GetArea().height;

	if ((sub_x[0] <= sphere_x) && (sphere_x <= sub_x[1]) && (sub_y[0] <= sphere_y) && (sphere_y <= sub_y[1])) //“–‚½‚è”»’è
	{
		ret = true;
	}

	return ret;
}

Location SphereCollider::GetLocation() const
{
    return Location();
}
