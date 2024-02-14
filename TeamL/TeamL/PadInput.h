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
#include"DxLib.h"

#define BUTTONS 16

//スティック
struct Stick
{
	short x;	//横軸値
	short y;	//縦軸値
};

class PadInput
{
private:

	static char now_key[2][BUTTONS]; //今回の入力キー
	static char old_key[2][BUTTONS]; //前回の入力キー
	static XINPUT_STATE input[2]; //パッド
	static Stick r_stick[2]; //右スティック
	static Stick l_stick[2]; //左スティック
	static float L_trigger[2]; //左トリガー
	static float R_trigger[2]; //右トリガー

private:

	//コンストラクタ
	PadInput() = default;
public:

	//パッド情報の更新
	static void UpdateKey();

	//ボタンを押された瞬間
	static bool OnButton(int i ,int button);

	//ボタンを押してる間
	static bool OnPressed(int i, int button);

	//ボタンを離した瞬間
	static bool OnRelease(int i, int button);

	//右スティックの取得
	static Stick GetRStick(int i);

	//左スティックの取得
	static Stick GetLStick(int i);

	//左トリガーの取得
	static float GetLTrigger(int i);
	
	//右トリガーの取得
	static float GetRTrigger(int i);

	static char GetOldKey(const int i , const int j);

	static char GetNowKey(const int i, const int j);
};