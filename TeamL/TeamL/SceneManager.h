/****************************************************************/
/*	�v���W�F�N�g��:												*/
/*	�t�@�C�����F												*/
/*	���e�F														*/
/*	���t�F														*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF													*/
/****************************************************************/
#pragma once
#include "AbstractScene.h"
class SceneManager :
    public AbstractScene
{
private:
    //�R���X�g���N�^
    SceneManager(AbstractScene* scene) :mScene(scene) {};

    static SceneManager* instance;
    AbstractScene* mScene;
public:

    //�f�X�g���N�^
    ~SceneManager();


    //�`��ȊO�̍X�V�����s
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;

    //�V���O���g��
    static SceneManager* Create(AbstractScene* scene);
    static SceneManager* GetInstance();
    static void Delete();
};

