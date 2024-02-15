#include "UI.h"
#include"DxLib.h"

//-----------------------------------
// �R���X�g���N�^
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
	//�]������
	switch (num)
	{
	case 1:
		DrawRotaGraph(150, 30, 1, 0, image, TRUE);
		break;
	case 2:
		DrawRotaGraph(150, 30, 1, 0, image, TRUE);
		DrawRotaGraph(250, 30, 1, 0, image, TRUE);
		break;
	case 3:
		DrawRotaGraph(150, 30, 1, 0, image, TRUE);
		DrawRotaGraph(250, 30, 1, 0, image, TRUE);
		DrawRotaGraph(350, 30, 1, 0, image, TRUE);
		break;
	default:
		break;
	}
	DrawFormatString(10, 0, 0xFFFFFF, "HP");
}
