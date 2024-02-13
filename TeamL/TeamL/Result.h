
/****************************************************************/
/*	プロジェクト名:		Gamejam 　　チームL*/
/*	ファイル名：		Title							*/
/*	内容：				各画面への遷移						*/
/*	日付：		２０２４年０２月１２日							*/
/*	コンパイラ:													*/
/*	note:		変なところあるかも報告ください	解説載せときますコメントで				*/
/*	作成者：	優咲											*/
/****************************************************************/


#pragma once
#include "AbstractScene.h"
class Result :
    public AbstractScene
{
private:
    int score; //スコア
    
public:

    //コンストラクタ
    Result();

    //スコアを確保する
    Result(int score);
    
    //デストラクタ
    ~Result();

    //描画以外の更新を実行
    AbstractScene* Update()override;

    //描画に関することを実装
    void Draw() const override;
};

