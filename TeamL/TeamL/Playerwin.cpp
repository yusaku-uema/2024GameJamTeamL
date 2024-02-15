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
    PlayerWin_image = LoadGraph("../imege/win.mp3");
    PlayerWIN_BGM = LoadGraph("../BGM/lose.mp3");
}

PlayerWin::~PlayerWin()
{
    DeleteSoundMem(PlayerWIN_BGM);

}

//-----------------------------------
// �X�V����
//-----------------------------------
AbstractScene* PlayerWin::Update()
{
    if (CheckSoundMem(PlayerWIN_BGM) != 1)
    {   //BGM������Ă��Ȃ�������Đ�
        PlaySoundMem(PlayerWIN_BGM, DX_PLAYTYPE_LOOP, TRUE); //BGM�Đ�
    }

    //A�{�^���������ꂽ��^�C�g���ړ�
    if (PadInput::OnButton(0, XINPUT_BUTTON_A))
    {

        //BGM���~�߂�
        StopSoundMem(PlayerWIN_BGM);

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


    DrawGraph(0, 0, PlayerWin_image, FALSE);

}
