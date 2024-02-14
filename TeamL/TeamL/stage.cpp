/****************************************************************/
/*	プロジェクト名:												*/
/*	ファイル名：												*/
/*	内容：														*/
/*	日付：														*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：													*/
/****************************************************************/
#include"DxLib.h"
#include"stage.h"


Stage::Stage(float locationx, float locationy, int width, int height,int type)
{

	//描画位置
	location.X = locationx * width;
	location.Y = locationy * height;

	//サイズ
	area.width = width;
	area.height = height;

	camerax = 0;

	tukiimage1 = LoadGraph("../imege/tuki.png");
	tukiimage2 = LoadGraph("../imege/tuki2.png");
	tukiimage3 = LoadGraph("../imege/tuki3.png");
	tukiimage4 = LoadGraph("../imege/tuki4.png");
	
	



	this->type = type;


}

Stage::~Stage()
{
}



void Stage::Update(int camerax)
{


	this->camerax = camerax;



}

void Stage::Draw()const
{

	switch (type)
	{
	
	case 1:
		DrawGraph(location.X - camerax, location.Y, tukiimage1, FALSE);
		break;
	case 2:
		DrawGraph(location.X - camerax, location.Y, tukiimage2, FALSE);
		break;
	case 3:
		DrawGraph(location.X - camerax, location.Y, tukiimage3, FALSE);
		break;
	case 4:
		DrawGraph(location.X - camerax, location.Y, tukiimage4, FALSE);
		break;
	}
	
	

}