/****************************************************************/
/*	�v���W�F�N�g��:		Gamejam �@�@�`�[��L						*/
/*	���e�F		�p�b�g����										*/
/*	���t�F		�Q�O�Q�S�N�O�Q���P�Q��							*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF	���Ð^�@���l									*/
/****************************************************************/

#include "PadInput.h"

char PAD_INPUT::now_key[BUTTONS];
char PAD_INPUT::old_key[BUTTONS];
XINPUT_STATE PAD_INPUT::input;
Stick PAD_INPUT::r_stick;
Stick PAD_INPUT::l_stick;