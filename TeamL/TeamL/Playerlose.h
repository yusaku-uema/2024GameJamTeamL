/****************************************************************/
/*	プロジェクト名:												*/
/*	ファイル名：												*/
/*	内容：														*/
/*	日付：														*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：													*/
/****************************************************************/
#pragma once
#include "AbstractScene.h"
#include"PadInput.h"

class PlayerLose :public AbstractScene
{
	//ヘルプの背景画像
	int PlayerLose_image;
	int PlayerLose_BGM;

public:
	//コンストラクタ 
	PlayerLose();
	~PlayerLose();
	//描画以外の更新を実行
	AbstractScene* Update()override;

	//描画に関することを実装
	void Draw() const override;
};

