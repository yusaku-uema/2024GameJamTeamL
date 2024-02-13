#include"DxLib.h"
#include"GameMain.h"


GameMain::GameMain()
{

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

}