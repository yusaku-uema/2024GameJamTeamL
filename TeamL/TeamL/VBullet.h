#pragma once
#include "Collinder.h"

class VBullet : public Collinder //クラス名
{
public: //アクセス指定子
	float radius;		// 半径
	float color;        //色情報
	float move_x;		// 進行方向ベクトル情報X
	float move_y;		// 進行方向ベクトル情報Y
	int VBulletimage;
	bool StageHit;
	int ReflectionSE;

	int angle; 
	int image[15];
	long long int animation_time; //アニメーション時間
	int animation; //画像切り替え

	VBullet();
	VBullet(float mx, float my,float vx, float vy,int a);   //初期化
	~VBullet();

	void Draw();      //描画する処理
	void Update();    //更新処理
	void Move();      //移動処理
	bool Get();
	void Set();
};