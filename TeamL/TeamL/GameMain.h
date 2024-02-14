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
#include"Player1.h"
#include"UI.h"
#include"explosion.h"

#include "Bullet.h"
#include"VBullet.h"
#include"Bom.h"


class GameMain :
	public AbstractScene

{
	int BGM;


private:
	//描画座標
	int rendering_coodinates_x;

	CameraWork* camerawork;//カメラワーク
	Stage* stage[25][111];//ステージの[縦][横]
	Player1* player1;
	Player2* player2;
	UI* ui; 
	Explosion* explosion;


	//Player2の弾丸計
	Bullet* p_bullet;
	VBullet* p_vbullet;
	Bom* p_bom;


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
