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


	//�v���C���[�����X�N���[��(�e�X�g�i�K)
	charx++;

	//�J�����̈ʒu���v�Z
	camerax = charx - 100; //�X�N���[���J�n
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
