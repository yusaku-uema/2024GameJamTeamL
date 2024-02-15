#include "explosion.h"
#include"DxLib.h"

Explosion::Explosion(int x,int y)
{
	this->location.x = x;
	this->location.y = y;

	radius = 100;
	LoadDivGraph("../imege/tktk_Impact_14.png", 10, 5, 2, 192, 192, image);
	animation_time = 0;
	animation = 0;
	end = false;
	damage = true;
}

void Explosion::Update()
{
	if (++animation_time % 3 == 0)
	{
		animation++;
		if (animation >= 9)
		{
			end = true;
		}

	}
}

void Explosion::Draw()
{
	DrawRotaGraph(location.x, location.y, 2.0f, 0, image[animation], TRUE);
}

bool Explosion::GetEnd()
{
	return end;
}

void Explosion::SetDamage()
{
	damage=false;
}

bool Explosion::GetDamage()
{
	return damage;
}
