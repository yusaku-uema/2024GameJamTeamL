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
#include "Collinder.h"

class Stage:
	public Collinder

{

	int camerax;

	int tukiimage1;
	int tukiimage2;
	int tukiimage3;
	int tukiimage4;


private:

	int type;

public:

	Stage(float locationx,float locationy,int width,int height,int type);

	~Stage();

	//描画以外の更新を実行
	void Update(int camerax);

	//描画に関することを実装
	void Draw() const ;
};
