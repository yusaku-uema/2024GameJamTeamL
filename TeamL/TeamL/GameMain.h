/****************************************************************/
/*	プロジェクト名:		Gamejam 　　チームL						*/
/*	ファイル名：メインヘッダー									*/
/*	内容：			ゲームのメイン								*/
/*	日付：					2024/02/14							*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：				名嘉真　愛斗						*/
/****************************************************************/
#pragma once
#include "AbstractScene.h"
#include"camerawork.h"
#include"Player2.h"
#include"stage.h"


class GameMain :
	public AbstractScene

{
	


private:
	//描画座標
	int rendering_coodinates_x;

	CameraWork* camerawork;//カメラワーク
	Stage* stage[25][111];//ステージの[縦][横]
	Player2* player2;

public:
	int gMileage ;//プレイヤーの走行距離
	int stageimg;

	GameMain();
	~GameMain();

	//描画以外の更新を実行
	AbstractScene* Update()override;

	//描画に関することを実装
	void Draw() const override;

};
