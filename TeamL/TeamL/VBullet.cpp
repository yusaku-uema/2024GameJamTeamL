#include "VBullet.h"
#include "DxLib.h"



VBullet::VBullet()   //初期化
{
	location.x = 320.0f;   //xの初期座標
	location.y = 240.0f;   //xの初期座標
	area.height = 20; //縦幅
	area.width = 20; //横幅
	move_x = 1.0f;   //ｘ軸を動かす
	move_y = 0.0f;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色
}

VBullet::VBullet(float mx, float my,float vx, float vy,int a)
{
	location.x = mx;  //受け取った座標を反映させる
	location.y = my;  //受け取った座標を反映させる
	move_x = vx;   //ｘ軸を動かす
	move_y = vy;   //ｙ軸を動かす
	radius = 10.0f;  //半径
	color = GetColor(255, 0, 0); //色

	VBulletimage = LoadGraph("../imege/beam.png");
	area.height = 20; //縦幅
	area.width = 20; //横幅

	LoadDivGraph("../imege/tktk_Laser_1.png", 15, 5, 3, 192, 192, image);
	animation_time = 0;
	animation = 0;
	angle = a;
	StageHit = false;
}

VBullet::~VBullet()
{
}

void VBullet::Update()//更新処理
{
	
	if (++animation_time % 1 == 0)
	{
		animation++;
		if (animation > 8)
		{
			animation = 4;
		}

	}

	if (animation >= 3)
	{
		location.x += move_x;
		location.y += move_y;

		if (location.y <= 0)
		{
			move_y *= -1;
			angle = -45;
			//StageHit = false;
		}

		/*if (StageHit==TRUE)
		{
			move_y *= -1;
			angle = 45;
			StageHit = false;
		}*/
		

		if (location.y >= 550)
		{
			move_y *= -1;
			angle = 45;
		}
	}

}

void VBullet::Draw()//描画処理
{
	//DrawRotaGraph(location.x, location.y, 1.0, 0, VBulletimage, TRUE);
	DrawRotaGraph(location.x, location.y, 2.0f, angle, image[animation], TRUE);

}


void VBullet::Move()//移動処理
{

}

bool VBullet::Get()
{
	return StageHit;
}

void VBullet::Set()
{
	StageHit = TRUE;
	
}