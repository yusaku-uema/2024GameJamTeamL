/****************************************************************/
/*	プロジェクト名:												*/
/*	ファイル名：												*/
/*	内容：														*/
/*	日付：														*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：													*/
/****************************************************************/
#include "Playerlose.h"
#include"Main_Title.h"

//-----------------------------------
// コンストラクタ
// 宣言したメンバ変数を初期化する場所
//-----------------------------------
PlayerLose::PlayerLose()
{
    //画像
    PlayerLose_image = LoadGraph("../imege/2win.png");
    PlayerLose_BGM = LoadGraph("../BGM/lose.mp3");
}

PlayerLose::~PlayerLose()
{

    DeleteSoundMem(PlayerLose_BGM);

}

//-----------------------------------
// 更新処理
//-----------------------------------
AbstractScene* PlayerLose::Update()
{
    //Aボタンが押されたらタイトル移動
    if (PadInput::OnButton(0, XINPUT_BUTTON_A))
    {
        //BGMを止める
        StopSoundMem(PlayerLose_BGM);

        return new Main_Title();
    }

    return this;
}

//-----------------------------------
// 描画以外
//-----------------------------------
void PlayerLose::Draw() const
{
    //文字大きさ変更
    SetFontSize(40);


    DrawGraph(0, 0, PlayerLose_image, FALSE);

}
