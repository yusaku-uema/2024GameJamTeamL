#include "DxLib.h"



#define FRAMERATE 60 //�t���[�����[�g

#define SCREEN_WIDTH 640 //��ʃT�C�Y�i���j

#define SCREEN_HEIGHT 480 //��ʃT�C�Y�i�c�j

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	double dNextTime = GetNowCount();

	SetMainWindowText("Super Mario Bros");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	SetAlwaysRunFlag(TRUE);		//�E�B���h�E����A�N�e�B�u�łȂ��Ă��������p�����邩�ݒ�

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//��ʃT�C�Y�̐ݒ�

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	

	return 0;
}