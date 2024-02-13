
#pragma once

class CameraWork 
{
private:

	int camerax;
	int charx;
	int view_charx;

public:
	CameraWork();
	~CameraWork();

	//描画以外の更新を実行
	void  Update(float Player_location);

	
	int  GetViewCharX();

	int GetCameraX();
};
