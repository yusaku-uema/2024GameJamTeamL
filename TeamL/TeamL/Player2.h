//���g�@�N�m���S�������Ƃ���

#pragma once
#include "Bullet.h"
class Player2
{
private:
	float x;
	float y;
	float move_y;
	float radius;

public:
	Bullet* p_bullet;
	Player2();
	~Player2();
	Player2(float mx, float my);

	void Update();
	void Draw();
	void Move();
};