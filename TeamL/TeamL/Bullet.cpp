#include "Bullet.h"
#include "DxLib.h"



Bullet::Bullet()   //初期化
{
	location.x = 320.0f;   //xの初期座標
	location.y = 240.0f;   //xの初期座標
	area.height = 20; //縦幅
	area.width = 20; //横幅
	move_x = 1.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色
	Bulletimage = LoadGraph("../imege/beam.png");
}

Bullet::Bullet(float mx, float my)
{
	location.x = mx-200;  //受け取った座標を反映させる
	location.y = my;  //受け取った座標を反映させる
	move_x = -20.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色
	area.height = 20; //縦幅
	area.width = 20; //横幅
	Bulletimage = LoadGraph("../imege/beam.png");

	LoadDivGraph("../imege/tktk_Laser_3.png", 40, 5, 8, 192, 192, image);
	animation_time = 0;
	animation = 0;
}

Bullet::~Bullet()
{
}

void Bullet::Update()//更新処理
{
	
	if (++animation_time % 3 == 0)
	{
		animation++;
		if (animation > 28)
		{
			animation=20;
		}

	}

	if (animation >= 13)
	{
		location.x += move_x;
	}
}

void Bullet::Draw()//描画処理
{
	//DrawRotaGraph(location.x, location.y, 1.0, 0, Bulletimage, TRUE);
	DrawRotaGraph(location.x, location.y, 2.0f, 0, image[animation], TRUE,TRUE);
}


void Bullet::Move()//移動処理
{
	
}

