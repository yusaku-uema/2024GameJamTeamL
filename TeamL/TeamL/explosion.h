#pragma once
#include "SphereCollider.h"
class Explosion :
    public SphereCollider
{
private:
    int image[10]; //画像
    long long int animation_time; //アニメーション時間
    int animation; //画像切り替え
    bool end;
    bool damage;
public:
    Explosion(int x,int y);
    void Update();    //更新処理
    void Draw();      //描画する処理
    bool GetEnd();
    void SetDamage();
    bool GetDamage();
    
};

