
#pragma once
#include "Collinder.h"

class Stage:
	public Collinder

{

	int camerax;

	int tukiimage1;
	int tukiimage2;
	int tukiimage3;


private:


public:

	Stage(float locationx,float locationy,int width,int height);

	~Stage();

	//描画以外の更新を実行
	void Update(int camerax);

	//描画に関することを実装
	void Draw() const ;
};
