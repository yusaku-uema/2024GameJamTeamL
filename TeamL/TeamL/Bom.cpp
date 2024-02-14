#include "Bom.h"
#include "DxLib.h"



Bom::Bom()   //初期化
{
	x = 320.0f;   //xの初期座標
	y = 240.0f;   //xの初期座標
	move_x = 1.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 30.0f;  //半径
	color = GetColor(255, 0, 0); //色
}

Bom::Bom(float mx, float my)
{
	x = mx;  //受け取った座標を反映させる
	y = my;  //受け取った座標を反映させる
	move_x = -5.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 30.0f;  //半径
	color = GetColor(255, 0, 0); //色
}

Bom::~Bom()
{
}

void Bom::Update()//更新処理
{
	x += move_x;
}

void Bom::Draw()//描画処理
{

	DrawCircleAA(x, y, radius, 100, color, TRUE);
}


void Bom::Move()//移動処理
{

}