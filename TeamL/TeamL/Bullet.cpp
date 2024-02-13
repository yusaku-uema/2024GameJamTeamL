#include "Bullet.h"
#include "DxLib.h"



Bullet::Bullet()   //初期化
{
	x = 320.0f;   //xの初期座標
	y = 240.0f;   //xの初期座標
	move_x = 1.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色
}

Bullet::Bullet(float mx, float my)
{
	x = mx;  //受け取った座標を反映させる
	y = my;  //受け取った座標を反映させる
	move_x = -10.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色
}

Bullet::~Bullet()
{
}

void Bullet::Update()//更新処理
{
	x += move_x;
}

void Bullet::Draw()//描画処理
{

	DrawCircleAA(x, y, radius, 100, color, TRUE);
}


void Bullet::Move()//移動処理
{
	
}