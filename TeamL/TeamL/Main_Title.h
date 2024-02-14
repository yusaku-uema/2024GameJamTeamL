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

class Main_Title :
	public AbstractScene
{
private:

    //���j���[,
    //�ꗗ
    enum class MENU
    {
        PLAYER_GAME,
        HELP,
        END,
        SETUMEI,
        MENU_SIZE
    };


    // �I�����Ă��郁�j���[
    int select_menu;

    //�J�[�\����Y���W
    int cursor_y;

    //����Ԋu����
    int input_margin;

    int stick_y;

    //�^�C�g���摜
    int title_image;

    //����SE
    int definite_se;

    //�I��SE
    int selection_se;

    //�^�C�g��BGM
    int title_bgm;
	

public:
    //�R���X�g���N�^ 
	Main_Title();

    //�f�X�g���N�^
    ~Main_Title();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};
