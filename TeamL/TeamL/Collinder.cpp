#include "Collinder.h"


bool Collinder::HitBox(const Collinder* collinder) const
{

    bool ret = false;

    //�����̓����蔻��
    float my_x[2];
    float my_y[2] ;

    //�G�̓����蔻��
    float sub_x[2];
    float sub_y[2];

    //�����̓����蔻��̌v�Z
    my_x[0] = location.X - (area.width / 2);
    my_y[0] = location.Y - (area.height / 2);
    my_x[1] = my_x[0] + area.width;
    my_y[1] - my_y[0] * area.height;

    //�G�̓����蔻��̌v�Z
    sub_x[0] = collinder->Getlocation().X - (collinder->GetArea().width / 2);
    sub_y[0] = collinder->Getlocation().Y - (collinder->GetArea().height / 2);
    sub_x[1] = sub_x[0] + collinder->GetArea().width;
    sub_y[1] = sub_y[0] + collinder->GetArea().height;

    if ((my_x[0] <= sub_x[1]) && (sub_x[0] <= my_x[1])

         &&(my_y[0]<= sub_y[1])&&(sub_y[0<=my_y[1]]))
    {

        ret = true;
    }
    return ret;
}

Location Collinder::Getlocation() const
{
    return location;
}

Area Collinder::GetArea() const
{
    return area;
}
