
#pragma once
#include "AbstractScene.h"
#include"camerawork.h"
#include"stage.h"

class GameMain :
	public AbstractScene

{



private:
	//びょうがざひょう
	int rendering_coodinates_x;

	CameraWork* camerawork;
	Stage* stage[25][111];

public:
	GameMain();
	~GameMain();

	//描画以外の更新を実行
	AbstractScene* Update()override;

	//描画に関することを実装
	void Draw() const override;
};
