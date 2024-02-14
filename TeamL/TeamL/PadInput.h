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
#include"DxLib.h"

#define BUTTONS 16

//�X�e�B�b�N
struct Stick
{
	short x;	//�����l
	short y;	//�c���l
};

class PadInput
{
private:

	static char now_key[2][BUTTONS]; //����̓��̓L�[
	static char old_key[2][BUTTONS]; //�O��̓��̓L�[
	static XINPUT_STATE input[2]; //�p�b�h
	static Stick r_stick[2]; //�E�X�e�B�b�N
	static Stick l_stick[2]; //���X�e�B�b�N
	static float L_trigger[2]; //���g���K�[
	static float R_trigger[2]; //�E�g���K�[

private:

	//�R���X�g���N�^
	PadInput() = default;
public:

	//�p�b�h���̍X�V
	static void UpdateKey();

	//�{�^���������ꂽ�u��
	static bool OnButton(int i ,int button);

	//�{�^���������Ă��
	static bool OnPressed(int i, int button);

	//�{�^���𗣂����u��
	static bool OnRelease(int i, int button);

	//�E�X�e�B�b�N�̎擾
	static Stick GetRStick(int i);

	//���X�e�B�b�N�̎擾
	static Stick GetLStick(int i);

	//���g���K�[�̎擾
	static float GetLTrigger(int i);
	
	//�E�g���K�[�̎擾
	static float GetRTrigger(int i);

	static char GetOldKey(const int i , const int j);

	static char GetNowKey(const int i, const int j);
};