#include "Main_Title.h"
#include "common.h"
#include "DxLib.h"
#include"PadInput.h"


Main_Title::Main_Title()
{

}

AbstractScene* Main_Title::Update()
{
	
	return this;
}

void Main_Title::Draw()const
{
	DrawFormatString(100, 100, 0xff0000,"ƒeƒXƒg", TRUE);
}
