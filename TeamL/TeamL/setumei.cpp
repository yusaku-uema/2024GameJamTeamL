/****************************************************************/
/*	�v���W�F�N�g��:												*/
/*	�t�@�C�����F												*/
/*	���e�F														*/
/*	���t�F														*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF													*/
/****************************************************************/
#include "setumei.h"
#include"Main_Title.h"
Setumei::Setumei()
{
	//�摜
	Setumei_image = LoadGraph("../imege/Setumei.png");
}

AbstractScene* Setumei::Update()
{
    //A�{�^���������ꂽ��^�C�g���ړ�
    if (PadInput::OnButton(0,XINPUT_BUTTON_A))
    {
        return new Main_Title();
    }

    return this;
}

void Setumei::Draw()const
{
    DrawGraph(0, 0, Setumei_image, FALSE);

}