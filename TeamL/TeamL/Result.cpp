/****************************************************************/
/*	プロジェクト名:												*/
/*	ファイル名：												*/
/*	内容：														*/
/*	日付：														*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：													*/
/****************************************************************/
#include "Result.h"

//-----------------------------------
// コンストラクタ
// 宣言したメンバ変数を初期化する場所
//-----------------------------------
Result::Result()
{
    score = 0;
}


//-----------------------------------
// コンストラクタ
// 宣言したメンバ変数を初期化する場所
//-----------------------------------
Result::Result(int score)
{
    this->score = score;
}

//-----------------------------------
// デストラクタnewしたクラスをここに書く　じゃなけらばメモリリーク
//-----------------------------------
Result::~Result()
{

}

//-----------------------------------
// 更新処理
//-----------------------------------
AbstractScene* Result::Update()
{

    return this;
}

//-----------------------------------
// 描画のみ
//-----------------------------------
void Result::Draw() const
{
    
}
