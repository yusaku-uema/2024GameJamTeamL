/****************************************************************/
/*	�v���W�F�N�g��:												*/
/*	�t�@�C�����F												*/
/*	���e�F														*/
/*	���t�F														*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF													*/
/****************************************************************/
#include "PlayerWin.h"
#include"Main_Title.h"

//-----------------------------------
// �R���X�g���N�^
// �錾���������o�ϐ�������������ꏊ
//-----------------------------------
PlayerWin::PlayerWin()
{
    //�摜
    PlayerWin_image = LoadGraph("../imege/help.png");
}

//-----------------------------------
// �X�V����
//-----------------------------------
AbstractScene* PlayerWin::Update()
{
    //A�{�^���������ꂽ��^�C�g���ړ�
    if (PadInput::OnButton(0, XINPUT_BUTTON_A))
    {
        return new Main_Title();
    }

    return this;
}

//-----------------------------------
// �`��ȊO
//-----------------------------------
void PlayerWin::Draw() const
{
    //�����傫���ύX
    SetFontSize(40);


    //DrawGraph(0, 0, PlayerLose_image, FALSE);
    DrawFormatString(300, 300, 0xff0000, "WIN", TRUE);

}
