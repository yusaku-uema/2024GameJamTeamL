/****************************************************************/
/*	プロジェクト名:												*/
/*	ファイル名：												*/
/*	内容：														*/
/*	日付：														*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：													*/
/****************************************************************/
#pragma once

//サイズ
struct Area
{
	float height;
	float width;

};
//中心座標
struct Location
{
	float X;//ちゅうしんｘ
	float Y;//ちゅうしんｙ
};

class Collinder

{
protected:

	Area area;
	Location location;


public:

	bool HitBox(const class Collinder* collider)const;

	//中心座標の取得
	Location Getlocation()const;

	//画像のはんけいの取得
	Area GetArea()const;

};