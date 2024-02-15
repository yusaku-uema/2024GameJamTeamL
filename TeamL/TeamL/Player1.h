#pragma once

#include"Collinder.h"

class Player1:public Collinder
{
public:
	bool is_jump;	//ジャンプ可能か？
	bool is_fly;	//浮遊可能か？
	bool is_fuel;	//燃料があるか？
	int X;			//プレイヤーのX座標
	int Y;			//プレイヤーのY座標
	int R;			//プレイヤーの半径
	int low;		//小ジャンプの高さ
	int high;		//大ジャンプの高さ
	int count;		//
	int type;		//ジャンプのタイプ
	int abs;		//ジャンプの高さの絶対値
	float speed;	//スピード
	float fuel;		//燃料
	float g;		//落下変数
	float ground;	//床の座標

	int view_charx; //上間　スクロール処理
	int hp; //上間　HP管理
	int imgae1; //上間　画像
	int imgae2; //画像
	int se1;
	int se5count;
	int se2;
	int se3;
	int se4;
	int se5;

public:
	Player1();		//コンストラクタ
	~Player1();		//デストラクタ

	void Update(int view_charx);//更新処理
	void Draw();				//描画処理
	void Move();				//移動処理
	void Flg();					//判定処理
	void Jump(int jump);		//ジャンプ処理
	void Fall();				//落下処理
	void Fuel();				//燃料ゲージ処理
	void SetJump(bool flg);		//ジャンプフラグ設定処理
	void SetFly(bool flg);		//浮遊フラグ設定処理
	void Damage(); //上間　この関数呼ばれるとHPを減らす
	int GetHP(); //HPの値を参照出来るように
	void SetFuel(bool flg);		//燃料フラグ設定処理
	void SetGround(float y);

private:

};

///****************************************************************/
///*	プロジェクト名:		テスト									*/
///*	内容：		playerクラスの作成								*/
///*	日付：		２０２４年０２月１4日							*/
///*	コンパイラ:													*/
///*	note:														*/
///*	作成者：	上間											*/
///****************************************************************/
//
//class Player1 :public Collinder
//{
//private:
//	bool is_jump;	//ジャンプ可能か？
//	bool is_fly;	//浮遊可能か？
//	bool is_fuel;	//燃料があるか？
//	int X;			//プレイヤーのX座標
//	int Y;			//プレイヤーのY座標
//	int R;			//プレイヤーの半径
//	int low;		//小ジャンプの高さ
//	int high;		//大ジャンプの高さ
//	int count;		//
//	int type;		//ジャンプのタイプ
//	int abs;		//ジャンプの高さの絶対値
//	float speed;	//スピード
//	float fuel;		//燃料
//	float g;		//落下変数
//	float ground;	//床の座標
//
//	int view_charx; //上間　スクロール処理
//	int hp; //上間　HP管理
//	int imgae; //上間　画像
//
//public:
//	Player1();		//コンストラクタ
//	~Player1();		//デストラクタ
//
//	void Update(int view_charx);//更新処理
//	void Draw();				//描画処理
//	void Move();				//移動処理
//	void Flg();					//判定処理
//	void Jump(int jump);		//ジャンプ処理
//	void Fly();					//落下処理
//	void Fuel();				//燃料ゲージ処理
//	void SetJump(bool flg);		//ジャンプフラグ設定処理
//	void SetFly(bool flg);		//浮遊フラグ設定処理
//	void Damage(); //上間　この関数呼ばれるとHPを減らす
//	int GetHP(); //HPの値を参照出来るように
//	void SetFuel(bool flg);		//燃料フラグ設定処理
//
//
//};