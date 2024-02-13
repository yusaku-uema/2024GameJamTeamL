
#pragma once
#include "AbstractScene.h"

class Collinder

{

private:


public:

	Collinder();

	~Collinder();

	//描画以外の更新を実行
	void Update();

	//描画に関することを実装
	void Draw() const;
};
