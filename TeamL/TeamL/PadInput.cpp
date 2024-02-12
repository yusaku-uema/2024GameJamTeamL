/****************************************************************/
/*	プロジェクト名:		Gamejam 　　チームL						*/
/*	内容：		パット操作										*/
/*	日付：		２０２４年０２月１２日							*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：	名嘉真　愛斗									*/
/****************************************************************/

#include "PadInput.h"

char PAD_INPUT::now_key[BUTTONS];
char PAD_INPUT::old_key[BUTTONS];
XINPUT_STATE PAD_INPUT::input;
Stick PAD_INPUT::r_stick;
Stick PAD_INPUT::l_stick;