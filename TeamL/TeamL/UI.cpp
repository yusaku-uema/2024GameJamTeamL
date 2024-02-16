#include "UI.h"
#include"DxLib.h"

//-----------------------------------
// コンストラクタ
//-----------------------------------
UI::UI()
{
	num = 0;
	image=LoadGraph("../imege/hp.png");
}

void UI::Update(int hp)
{
	num = hp;
}

void UI::Draw()
{

	//脳金眠い
	switch (num)
	{
	case 1:
		DrawRotaGraph(100, 35, 1, 0, image, TRUE);
		break;
	case 2:
		DrawRotaGraph(100, 35, 1, 0, image, TRUE);
		DrawRotaGraph(200, 35, 1, 0, image, TRUE);
		break;
	case 3:
		DrawRotaGraph(100, 35, 1, 0, image, TRUE);
		DrawRotaGraph(200, 35, 1, 0, image, TRUE);
		DrawRotaGraph(300, 35, 1, 0, image, TRUE);
		break;
	default:
		break;
	}
	DrawFormatString(10, 10, 0xFFFFFF, "HP");
	
}
