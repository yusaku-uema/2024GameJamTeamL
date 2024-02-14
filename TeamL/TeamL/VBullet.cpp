#include "VBullet.h"
#include "DxLib.h"



VBullet::VBullet()   //初期化
{
	x = 320.0f;   //xの初期座標
	y = 240.0f;   //xの初期座標
	move_x = 1.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色
}

VBullet::VBullet(float mx, float my,float vx, float vy)
{
	x = mx;  //受け取った座標を反映させる
	y = my;  //受け取った座標を反映させる
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
	x += move_x;
	y += move_y;

	if (y <= 0)
	{
		move_y *= -1;
	}
	if (y >= 720)
	{
		move_y *= -1;
	}
}

void VBullet::Draw()//描画処理
{

	DrawCircleAA(x, y, radius, 100, color, TRUE);
}


void VBullet::Move()//移動処理
{

}