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


Stage::Stage(float locationx, float locationy, int width, int height)
{

	//描画位置
	location.X = locationx * width;
	location.Y = locationy * height;

	//サイズ
	area.width = width;
	area.height = height;

	camerax = 0;

	tukiimage1 = LoadGraph("../imege/tuki.png");




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

	DrawGraph(location.X - camerax, location.Y, tukiimage1, FALSE);

}