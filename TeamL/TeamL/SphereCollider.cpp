#include "SphereCollider.h"
#define _USE_MATH_DEFINES
#include <math.h>


bool SphereCollider::HitBox(const Collinder* collider) const
{
	bool ret = false; //�Ԃ�l
	float rad; //2�_�̊p�x
	float sphere_x; //�~�̍��W(x)
	float sphere_y; //�~�̍��W(y)

	//����̓����蔻��͈̔�
	float sub_x[2];
	float sub_y[2];

	//�p�x�̌v�Z
	rad = atan2f(collider->GetLocation().y - location.y, collider->GetLocation().x - location.x);

	//���W�̌v�Z
	sphere_x = location.x + (radius * cosf(rad));
	sphere_y = location.y + (radius * sinf(rad));

	//����̓����蔻��͈̔͂̌v�Z
	sub_x[0] = collider->GetLocation().x - (collider->GetArea().width / 2);
	sub_y[0] = collider->GetLocation().y - (collider->GetArea().height / 2);
	sub_x[1] = sub_x[0] + collider->GetArea().width;
	sub_y[1] = sub_y[0] + collider->GetArea().height;

	if ((sub_x[0] <= sphere_x) && (sphere_x <= sub_x[1]) && (sub_y[0] <= sphere_y) && (sphere_y <= sub_y[1])) //�����蔻��
	{
		ret = true;
	}

	return ret;
}

Location SphereCollider::GetLocation() const
{
    return Location();
}
