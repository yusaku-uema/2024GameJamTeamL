/****************************************************************/
/*	�v���W�F�N�g��:			Gamejam �@�@�`�[��					*/
/*	�t�@�C�����F	�V�[���J��									*/
/*	���e�F			�V�[���J��									*/
/*	���t�F�Q�O�Q�S�N�O�Q���P�Q��								*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF	���Ð^�@���l										*/
/****************************************************************/
#include "SceneManager.h"
#include <stdio.h>
#include <time.h>

SceneManager* SceneManager::instance = nullptr;

/*
* �f�X�g���N�^
*/
SceneManager::~SceneManager()
{
	delete mScene;
	instance = nullptr; //�O����Ă΂��ꍇ����delete����Ă�ׁAnullptr�����邾����OK
}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* SceneManager::Update()
{

	AbstractScene* nextScene;
	try
	{
		nextScene = mScene->Update();
		if (nextScene != mScene)
		{
			delete mScene;
			mScene = nextScene;
		}
	}
	catch (const char* error_log)
	{
		FILE* fp = NULL;
		time_t timer = time(NULL);
		struct tm date;
		localtime_s(&date, &timer);


		//�t�@�C���I�[�v��
		fopen_s(&fp, "ErrorLog.txt", "a");
		//�G���[�f�[�^�̏�������
		fprintf_s(fp, "%02d�� %02d�� : %s\n", date.tm_hour, date.tm_min, error_log);
		fclose(fp);

		return nullptr;

	}


	return mScene;
}

/*
* �`��
*/
void SceneManager::Draw()const
{
	mScene->Draw();
}

/*
* ���N���X�̍쐬
* �ŏ��ɍX�V����V�[��
*/
SceneManager* SceneManager::Create(AbstractScene* scene)
{
	if (instance == nullptr)
	{
		instance = new SceneManager(scene);
	}
	return instance;
}

/*
* �C���X�^���X�̎擾
*/
SceneManager* SceneManager::GetInstance()
{
	if (instance != nullptr)
	{
		return instance;
	}
	else
	{
		return nullptr;
	}
}

/*
* �C���X�^���X�̍폜
*/
void SceneManager::Delete()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}