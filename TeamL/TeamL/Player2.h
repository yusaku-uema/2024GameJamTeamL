//���g�@�N�m���S�������Ƃ���

#pragma once
#include "Bullet.h"
#include"VBullet.h"
#include"Bom.h"
class Player2
{
private:
	float x;
	float y;
	float move_y;
	float radius;

public:
	Bullet* p_bullet;
	VBullet* p_vbullet;
	Bom* p_bom;
	Player2();
	~Player2();
	Player2(float mx, float my);

	void Update();
	void Draw();
	void Move();
};