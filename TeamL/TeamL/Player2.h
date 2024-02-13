#pragma once
class Player2
{
private:
	float x;
	float y;

public:
	Player2();

	void Update();
	void Draw();

	void SetLocation(float mx, float my);
};