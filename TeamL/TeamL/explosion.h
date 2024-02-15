#pragma once
#include "SphereCollider.h"
class Explosion :
    public SphereCollider
{
private:
    int image[10]; //�摜
    long long int animation_time; //�A�j���[�V��������
    int animation; //�摜�؂�ւ�
    bool end;
    bool damage;
public:
    Explosion(int x,int y);
    void Update();    //�X�V����
    void Draw();      //�`�悷�鏈��
    bool GetEnd();
    void SetDamage();
    bool GetDamage();
    
};

