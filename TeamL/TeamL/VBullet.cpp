#include "VBullet.h"
#include "DxLib.h"



VBullet::VBullet()   //初期化
{
	location.X = 320.0f;   //xの初期座標
	location.Y = 240.0f;   //xの初期座標
	move_x = 1.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色
}

VBullet::VBullet(float mx, float my,float vx, float vy)
{
	location.X = mx;  //受け取った座標を反映させる
	location.Y = my;  //受け取った座標を反映させる
	move_x = vx;   //ｘ軸を動かす
	move_y = vy;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色
}

VBullet::~VBullet()
{
}

void VBullet::Update()//更新処理
{
	location.X += move_x;
	location.Y += move_y;

	if (location.Y <= 0)
	{
		move_y *= -1;
	}
	if (location.Y >= 720)
	{
		move_y *= -1;
	}
}

void VBullet::Draw()//描画処理
{

	DrawCircleAA(location.X, location.Y, radius, 100, color, TRUE);
}


void VBullet::Move()//移動処理
{

}

float VBullet::GetVBulletX()
{
	return location.X;
}

float VBullet::GetVBulletY()
{
	return location.Y;
}