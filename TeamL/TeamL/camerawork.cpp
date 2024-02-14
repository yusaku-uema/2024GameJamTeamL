/****************************************************************/
/*	�v���W�F�N�g��:												*/
/*	�t�@�C�����F												*/
/*	���e�F														*/
/*	���t�F														*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF													*/
/****************************************************************/
#include"DxLib.h"
#include"camerawork.h"
#include"common.h"

CameraWork::CameraWork()
{
	view_charx = 0;
	charx = 0;
	camerax = 0;


}
CameraWork::~CameraWork()
{



}

void CameraWork::Update(float Player_location)
{
	//���L�����̍��W�̑��
	charx = Player_location;
	//�J�����̈ʒu���v�Z
	camerax = camerax - D_SCREEN_WIDTH / 2;
	//���E�̕␳
	if (camerax < 0) camerax = 0;
	//��ʂ̈ʒu�����߂�
	view_charx = charx - camerax;


}



int CameraWork::GetViewCharX()
{

	return view_charx;

}

int CameraWork::GetCameraX()
{

	return camerax;

}
