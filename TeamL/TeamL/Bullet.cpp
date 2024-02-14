#include "Bullet.h"
#include "DxLib.h"



Bullet::Bullet()   //初期化
{
	location.X = 320.0f;   //xの初期座標
	location.Y = 240.0f;   //xの初期座標
	move_x = 1.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色
}

Bullet::Bullet(float mx, float my)
{
	location.X = mx;  //受け取った座標を反映させる
	location.Y = my;  //受け取った座標を反映させる
	move_x = -20.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色
}

Bullet::~Bullet()
{
}

void Bullet::Update()//更新処理
{
	location.X += move_x;
	
}

void Bullet::Draw()//描画処理
{
	Bulletimage = LoadGraph("../imege/beam.png");
	DrawRotaGraph(location.X, location.Y, 1.0, 0, Bulletimage, TRUE);
}


void Bullet::Move()//移動処理
{
	
}

float Bullet::GetBulletX()
{
	return location.X;
}

float Bullet::GetBulletY()
{
	return location.Y;
}