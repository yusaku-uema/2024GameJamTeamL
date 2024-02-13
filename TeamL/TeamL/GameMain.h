
#pragma once
#include "AbstractScene.h"

class GameMain :s
	public AbstractScene
{

	int tukiimage1;
	int tukiimage2;
	int tukiimage3;


private:


public:
	GameMain();
	~GameMain();

	//描画以外の更新を実行
	AbstractScene* Update()override;

	//描画に関することを実装
	void Draw() const override;
};
