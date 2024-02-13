#include"DxLib.h"
#include"GameMain.h"


GameMain::GameMain()
{

	tukiimage1 = LoadGraph("../image/tuki.png");
	tukiimage2 = LoadGraph("../image/tuki2.png");
	tukiimage3 = LoadGraph("../image/tuki3.png");

	int a = 0;
}
GameMain::~GameMain()
{

}


AbstractScene* GameMain::Update()
{


	return this;


}

void GameMain::Draw()const
{



	DrawFormatString(100, 100, 0xff0000, "Main‚ª‚ß‚ñ‚¾‚¨", TRUE);


	DrawGraph(300, 100, tukiimage1, FALSE);
	DrawGraph(300, 200, tukiimage2, FALSE);
	DrawGraph(300, 300, tukiimage3, FALSE);

}