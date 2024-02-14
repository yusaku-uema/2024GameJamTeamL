/****************************************************************/
/*	プロジェクト名:												*/
/*	ファイル名：												*/
/*	内容：														*/
/*	日付：														*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：													*/
/****************************************************************/
#include "setumei.h"
#include"Main_Title.h"
Setumei::Setumei()
{
	//画像
	Setumei_image = LoadGraph("../imege/Setumei.png");
}

AbstractScene* Setumei::Update()
{
    //Aボタンが押されたらタイトル移動
    if (PadInput::OnButton(0,XINPUT_BUTTON_A))
    {
        return new Main_Title();
    }

    return this;
}

void Setumei::Draw()const
{
    DrawGraph(0, 0, Setumei_image, FALSE);

}