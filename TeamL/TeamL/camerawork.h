
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

	//�`��ȊO�̍X�V�����s
	void  Update(float Player_location);

	
	int  GetViewCharX();

	int GetCameraX();
};
