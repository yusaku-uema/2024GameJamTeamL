#include"DxLib.h"
#include"stage.h"


Stage::Stage(float locationx, float locationy, int width, int height)
{


	tukiimage1 = LoadGraph("../imege/tuki.png");
	tukiimage2 = LoadGraph("../imege/tuki2.png");
	tukiimage3 = LoadGraph("../imege/tuki5.png");


	int a = 0;
}
Stage::~Stage()
{

}


void Stage::Update()
{



}

void Stage::Draw()const
{



	DrawGraph(300, 100, tukiimage1, FALSE);
	DrawGraph(300, 200, tukiimage2, FALSE);
	DrawGraph(300, 300, tukiimage3, FALSE);

}