#include "Collinder.h"


bool Collinder::HitBox(const Collinder* collinder) const
{

    bool ret = false;

    //自分の当たり判定
    float my_x[2];
    float my_y[2] ;

    //敵の当たり判定
    float sub_x[2];
    float sub_y[2];

    //自分の当たり判定の計算
    my_x[0] = location.X - (area.width / 2);
    my_y[0] = location.Y - (area.height / 2);
    my_x[1] = my_x[0] + area.width;
    my_y[1] - my_y[0] * area.height;

    //敵の当たり判定の計算
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
