
/****************************************************************/
/*	�v���W�F�N�g��:		Gamejam �@�@�`�[��L*/
/*	�t�@�C�����F		Title							*/
/*	���e�F				�e��ʂւ̑J��						*/
/*	���t�F		�Q�O�Q�S�N�O�Q���P�Q��							*/
/*	�R���p�C��:													*/
/*	note:		�ςȂƂ��날�邩���񍐂�������	����ڂ��Ƃ��܂��R�����g��				*/
/*	�쐬�ҁF	�D��											*/
/****************************************************************/


#pragma once
#include "AbstractScene.h"
class Result :
    public AbstractScene
{
private:
    int score; //�X�R�A
    
public:

    //�R���X�g���N�^
    Result();

    //�X�R�A���m�ۂ���
    Result(int score);
    
    //�f�X�g���N�^
    ~Result();

    //�`��ȊO�̍X�V�����s
    AbstractScene* Update()override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;
};

