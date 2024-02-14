#pragma once

#include"Collinder.h"

class Player1:public Collinder
{
public:
	bool is_jump;	//ジャンプ可能か？
	bool is_fly;	//浮遊可能か？
	int X;			//プレイヤーのX座標
	int Y;			//プレイヤーのY座標
	int R;			//プレイヤーの半径
	int low;		//小ジャンプの高さ
	int high;		//大ジャンプの高さ
	int count;		//ジャンプの最高点
	int type;		//ジャンプのタイプ
	int abs;		//ジャンプの高さの絶対値
	float fuel;		//燃料
	int h;			//高さ
	int ground;		//床の座標


public:
	Player1();		//コンストラクタ
	~Player1();		//デストラクタ

	void Update();				//更新処理
	void Draw();				//描画処理
	void Move();				//移動処理
	void Flg();					//ジャンプ判定処理
	void Jump(int jump);		//ジャンプ処理
	void SetJump(bool flg);		//ジャンプフラグ設定処理
	void Fly();					//浮遊処理
	void SetFly(bool flg);		//浮遊フラグ設定処理
	void Fuel();				//燃料ゲージ処理

private:

};