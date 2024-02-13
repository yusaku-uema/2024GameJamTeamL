#include "Help.h"
#include"Main_Title.h"

//-----------------------------------
// コンストラクタ
// 宣言したメンバ変数を初期化する場所
//-----------------------------------
Help::Help()
{
    //画像
    help_image = 0;
}

//-----------------------------------
// 更新処理
//-----------------------------------
AbstractScene* Help::Update()
{
    //Aボタンが押されたらタイトル移動
    if(PadInput::OnButton(XINPUT_BUTTON_A))
    {
        return new Main_Title();
    }

    return this;
}

//-----------------------------------
// 描画以外
//-----------------------------------
void Help::Draw() const
{
    //文字大きさ変更
    SetFontSize(40);

    
    DrawFormatString(550, 300, 0xFFFFFF, "Aボタンでタイトルへ戻る");
}
