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

class Main_Title :
	public AbstractScene
{
private:

    //メニュー,
    //一覧
    enum class MENU
    {
        PLAYER_GAME,
        HELP,
        END,
        SETUMEI,
        MENU_SIZE
    };


    // 選択しているメニュー
    int select_menu;

    //カーソルのY座標
    int cursor_y;

    //操作間隔時間
    int input_margin;

    int stick_y;

    //タイトル画像
    int title_image;

    //決定SE
    int definite_se;

    //選択SE
    int selection_se;

    //タイトルBGM
    int title_bgm;
	

public:
    //コンストラクタ 
	Main_Title();

    //デストラクタ
    ~Main_Title();

	//描画以外の更新を実行
	AbstractScene* Update()override;

	//描画に関することを実装
	void Draw() const override;
};
