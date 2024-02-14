#include "Bom.h"
#include "DxLib.h"



Bom::Bom()   //‰Šú‰»
{
	location.x = 320.0f;   //x‚Ì‰ŠúÀ•W
	location.y = 240.0f;   //x‚Ì‰ŠúÀ•W
	area.height = 20; //c•
	area.width = 20; //‰¡•
	move_x = 1.0f;   //‚˜²‚ğ“®‚©‚·
	move_y = 0.0f;   //‚™²‚ğ“®‚©‚·
	radius = 30.0f;  //”¼Œa
	color = GetColor(255, 0, 0); //F
	Bomimage = LoadGraph("../imege/bom.png");
}

Bom::Bom(float mx, float my)
{
	location.x = mx;  //ó‚¯æ‚Á‚½À•W‚ğ”½‰f‚³‚¹‚é
	location.y = my;  //ó‚¯æ‚Á‚½À•W‚ğ”½‰f‚³‚¹‚é
	move_x = -5.0f;   //‚˜²‚ğ“®‚©‚·
	move_y = 0.0f;   //‚™²‚ğ“®‚©‚·
	radius = 30.0f;  //”¼Œa
	color = GetColor(255, 0, 0); //F
	area.height = 100; //c•
	area.width = 100; //‰¡•
	Bomimage = LoadGraph("../imege/bom.png");
	descent = false;
}

Bom::~Bom()
{
}

void Bom::Update()//XVˆ—
{

	if (descent == false)
	{
		location.y++;
	}
	else
	{
		location.x += move_x;
	}
	
	
}

void Bom::Draw()//•`‰æˆ—
{
	DrawRotaGraph(location.x, location.y, 1.0, 0, Bomimage, TRUE);

}


void Bom::Move()//ˆÚ“®ˆ—
{

}

void Bom::Setdescent()
{
	descent = true;
}
