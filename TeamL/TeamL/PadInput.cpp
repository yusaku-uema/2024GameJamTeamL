/****************************************************************/
/*	�v���W�F�N�g��:		Gamejam �@�@�`�[��L						*/
/*	���e�F		�p�b�g����										*/
/*	���t�F		�Q�O�Q�S�N�O�Q���P�Q��							*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF	���Ð^�@���l									*/
/****************************************************************/

#include "PadInput.h"

#define TRIGGER_MAX (255.0f)

char PadInput::now_key[BUTTONS];
char PadInput::old_key[BUTTONS];
XINPUT_STATE PadInput::input;
Stick PadInput::r_stick;
Stick PadInput::l_stick;
float PadInput::L_trigger;
float PadInput::R_trigger;


//-----------------------------------
// �R���g���[���̏����X�V
//-----------------------------------
void PadInput::UpdateKey()
{
	// ���̓L�[�擾
	GetJoypadXInputState(DX_INPUT_KEY_PAD1, &input);

	for (int i = 0; i < BUTTONS; i++)
	{
		old_key[i] = now_key[i];
		now_key[i] = input.Buttons[i];
	}

	//�E�X�e�B�b�N
	r_stick.x = input.ThumbRX;
	r_stick.y = input.ThumbRY;

	//���X�e�B�b�N
	l_stick.x = input.ThumbLX;
	l_stick.y = input.ThumbLY;

	//�g���K�[�̓��͏��
	L_trigger = (float)input.LeftTrigger / TRIGGER_MAX;
	R_trigger = (float)input.RightTrigger / TRIGGER_MAX;

}

bool PadInput::OnButton(int button)
{
	bool ret = (now_key[button] == 1 && old_key[button] == 0);
	return ret;
}

bool PadInput::OnPressed(int button)
{
	bool ret = (now_key[button] == 1);
	return ret;
}

bool PadInput::OnRelease(int button)
{
	bool ret = (now_key[button] == 0 && old_key[button] == 1);
	return ret;
}

Stick PadInput::GetRStick()
{

	return r_stick;

}

Stick PadInput::GetLStick()
{
	return l_stick;
}

float PadInput::GetLTrigger()
{
	return  L_trigger;
}

float PadInput::GetRTrigger()
{
	return  R_trigger;
}


char PadInput::GetOldKey(const int i)
{
	return old_key[i];
}

char PadInput::GetNowKey(const int i)
{
	return now_key[i];
}
