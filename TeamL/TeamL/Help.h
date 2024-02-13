#pragma once
#include "AbstractScene.h"
#include"PadInput.h"

class Help :
    public AbstractScene
{
	//ヘルプの背景画像
	int help_image;


public:
	//コンストラクタ 
	Help();

	//描画以外の更新を実行
	AbstractScene* Update()override;

	//描画に関することを実装
	void Draw() const override;
};

