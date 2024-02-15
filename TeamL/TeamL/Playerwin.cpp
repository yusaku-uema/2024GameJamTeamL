/****************************************************************/
/*	プロジェクト名:												*/
/*	ファイル名：												*/
/*	内容：														*/
/*	日付：														*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：													*/
/****************************************************************/
#include "PlayerWin.h"
#include"Main_Title.h"

//-----------------------------------
// コンストラクタ
// 宣言したメンバ変数を初期化する場所
//-----------------------------------
PlayerWin::PlayerWin()
{
    //画像
    PlayerWin_image = LoadGraph("../imege/help.png");
}

//-----------------------------------
// 更新処理
//-----------------------------------
AbstractScene* PlayerWin::Update()
{
    //Aボタンが押されたらタイトル移動
    if (PadInput::OnButton(0, XINPUT_BUTTON_A))
    {
        return new Main_Title();
    }

    return this;
}

//-----------------------------------
// 描画以外
//-----------------------------------
void PlayerWin::Draw() const
{
    //文字大きさ変更
    SetFontSize(40);


    //DrawGraph(0, 0, PlayerLose_image, FALSE);
    DrawFormatString(300, 300, 0xff0000, "WIN", TRUE);

}
