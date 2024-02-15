#pragma once
#include "Collinder.h"

class Bullet : public Collinder //クラス名
{
public: //アクセス指定子
	float radius;		// 半径
	float color;        //色情報
	float move_x;		// 進行方向ベクトル情報X
	float move_y;		// 進行方向ベクトル情報Y
	int Bulletimage;
	int image[40]; //レーザーエフェクト
	long long int animation_time; //アニメーション時間
	int animation; //画像切り替え
	int ChargeSE;
	int FiringSE;

	Bullet();
	Bullet(float mx, float my);   //初期化
	~Bullet();

	void Draw();      //描画する処理
	void Update();    //更新処理
	void Move();      //移動処理
};
