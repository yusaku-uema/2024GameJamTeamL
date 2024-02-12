/****************************************************************/
/*	�v���W�F�N�g��:		Gamejam �@�@�`�[��L*/
/*	�t�@�C�����F		�Q�[�����C��							*/
/*	���e�F				�S�Ă̑匳�̏���						*/
/*	���t�F		�Q�O�Q�S�N�O�Q���P�Q��							*/
/*	�R���p�C��:													*/
/*	note:		�ςȂƂ��날�邩���񍐂�������					*/
/*	�쐬�ҁF	���l											*/
/****************************************************************/



#include "DxLib.h"
#include"common.h"
#include"SceneManager.h"
#include"AbstractScene.h"
#include"PadInput.h"
#include"Main_Title.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	double dNextTime = GetNowCount();

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	SetAlwaysRunFlag(true);		//��ɃA�N�e�B�u�ɂ���

	SetGraphMode(D_SCREEN_WIDTH, D_SCREEN_HEIGHT, 32);	//��ʃT�C�Y�̐ݒ�

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���


	AbstractScene* firstScene = new Main_Title();						//FirstScene�̍쐬

	SceneManager* sceneManager = SceneManager::Create(firstScene);	//�V�[���}�l�[�W���[�̋N��

	// �Q�[�����[�v
	while ((ProcessMessage() == 0) &&
		sceneManager->Update() != nullptr
		)
	{
		PadInput::UpdateKey();

		ClearDrawScreen();		// ��ʂ̏�����

		sceneManager->Draw();


		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

		//�t���[�����[�g�̐ݒ�
		dNextTime += 1.0 / 60.0 * 1000.0;

		if (dNextTime > GetNowCount())
		{
			WaitTimer(static_cast<int>(dNextTime) - GetNowCount());
		}
		else { dNextTime = GetNowCount(); }		//�␳
	}
	delete sceneManager;		//�V�[���}�l�[�W���[�̍폜

	return 0;
}