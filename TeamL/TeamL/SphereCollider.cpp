#include "SphereCollider.h"
#define _USE_MATH_DEFINES
#include <math.h>


bool SphereCollider::HitBox(const Collinder* collider) const
{
	bool ret = false; //返り値
	float rad; //2点の角度
	float sphere_x; //円の座標(x)
	float sphere_y; //円の座標(y)

	//相手の当たり判定の範囲
	float sub_x[2];
	float sub_y[2];

	//角度の計算
	rad = atan2f(collider->GetLocation().y - location.y, collider->GetLocation().x - location.x);

	//座標の計算
	sphere_x = location.x + (radius * cosf(rad));
	sphere_y = location.y + (radius * sinf(rad));

	//相手の当たり判定の範囲の計算
	sub_x[0] = collider->GetLocation().x - (collider->GetArea().width / 2);
	sub_y[0] = collider->GetLocation().y - (collider->GetArea().height / 2);
	sub_x[1] = sub_x[0] + collider->GetArea().width;
	sub_y[1] = sub_y[0] + collider->GetArea().height;

	if ((sub_x[0] <= sphere_x) && (sphere_x <= sub_x[1]) && (sub_y[0] <= sphere_y) && (sphere_y <= sub_y[1])) //当たり判定
	{
		ret = true;
	}

	return ret;
}

Location SphereCollider::GetLocation() const
{
    return Location();
}
