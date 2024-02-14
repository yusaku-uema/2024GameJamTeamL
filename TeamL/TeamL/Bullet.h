#pragma once

class Bullet //クラス名
{
public: //アクセス指定子
	float x;           //X座標情報
	float y;           //Y座標情報
	float radius;		// 半径
	float color;        //色情報
	float move_x;		// 進行方向ベクトル情報X
	float move_y;		// 進行方向ベクトル情報Y

	Bullet();
	Bullet(float mx, float my);   //初期化
	~Bullet();

	void Draw();      //描画する処理
	void Update();    //更新処理
	void Move();      //移動処理
};
