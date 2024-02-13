//š ‹g@Nm‚ª’S“–‚µ‚½‚Æ‚±‚ë

#pragma once
class Player2
{
private:
	float x;
	float y;
	float move_y;
	float radius;

public:
	Player2();
	Player2(float mx, float my);

	void Update();
	void Draw();
	void Move();
};