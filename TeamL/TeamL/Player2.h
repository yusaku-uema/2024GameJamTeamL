//國吉　康仁が担当したところ

#pragma once
#include"Collinder.h"
#include"stage.h"

class Player2 : public Collinder
{
private:
	float move_y;
	float radius;
	int Player2image;

	int view_charx; //上間　スクロール処理

public:
	Player2();
	~Player2();
	Player2(float mx, float my);

	void Update(int view_charx);
	void Draw();
	void Move();
};