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
    PlayerWin_image = LoadGraph("../imege/win.mp3");
    PlayerWIN_BGM = LoadGraph("../BGM/lose.mp3");
}

PlayerWin::~PlayerWin()
{
    DeleteSoundMem(PlayerWIN_BGM);

}

//-----------------------------------
// 更新処理
//-----------------------------------
AbstractScene* PlayerWin::Update()
{
    if (CheckSoundMem(PlayerWIN_BGM) != 1)
    {   //BGMが流れていなかったら再生
        PlaySoundMem(PlayerWIN_BGM, DX_PLAYTYPE_LOOP, TRUE); //BGM再生
    }

    //Aボタンが押されたらタイトル移動
    if (PadInput::OnButton(0, XINPUT_BUTTON_A))
    {

        //BGMを止める
        StopSoundMem(PlayerWIN_BGM);

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


    DrawGraph(0, 0, PlayerWin_image, FALSE);

}
