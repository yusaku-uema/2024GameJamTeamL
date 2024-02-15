//š ‹g@Nm‚ª’S“–‚µ‚½‚Æ‚±‚ë

#pragma once
#include"Collinder.h"
#include"stage.h"

class Player2 : public Collinder
{
private:
	float move_y;
	float radius;
	int Player2image;
	int UFOimage;
	int MoveSE;

	int view_charx; //ãŠÔ@ƒXƒNƒ[ƒ‹ˆ—

public:
	Player2();
	~Player2();
	Player2(float mx, float my);

	void Update(int view_charx);
	void Draw();
	void Move();
};