/****************************************************************/
/*	プロジェクト名:												*/
/*	ファイル名：												*/
/*	内容：														*/
/*	日付：														*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：													*/
/****************************************************************/
#include"DxLib.h"
#include"camerawork.h"
#include"common.h"

CameraWork::CameraWork()
{
	view_charx = 0;
	charx = 0;
	camerax = 0;


}
CameraWork::~CameraWork()
{



}

void CameraWork::Update(float Player_location)
{


	//プレイヤー自動スクロール(テスト段階)
	charx++;

	//カメラの位置を計算
	camerax = charx - 100; //スクロール開始
	//左右の補正
	if (camerax < 0) camerax = 0;
	//画面の位置を求める
	view_charx = charx - camerax;


}



int CameraWork::GetViewCharX()
{

	return view_charx;

}

int CameraWork::GetCameraX()
{

	return camerax;

}
