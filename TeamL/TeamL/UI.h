#pragma once

class UI
{
private: //メンバ変数はプライベートで宣言
	int num; //表示するHPの数
	int image; //表示する画像
public:
	UI();
	void Update(int hp);				//更新処理
	void Draw();				//描画処理
};

