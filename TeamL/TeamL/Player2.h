//š ‹g@Nm‚ª’S“–‚µ‚½‚Æ‚±‚ë

#pragma once
#include "Bullet.h"
#include"VBullet.h"
#include"Bom.h"
#include"Collinder.h"
class Player2 : public Collinder
{
private:
	float x;
	float y;
	float move_y;
	float radius;
	int Player2image;

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