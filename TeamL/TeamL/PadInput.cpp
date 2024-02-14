/****************************************************************/
/*	プロジェクト名:		Gamejam 　　チームL						*/
/*	内容：		パット操作										*/
/*	日付：		２０２４年０２月１２日							*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：	上間							*/
/****************************************************************/

#include "PadInput.h"

#define TRIGGER_MAX (255.0f)

char PadInput::now_key[2][BUTTONS];
char PadInput::old_key[2][BUTTONS];
XINPUT_STATE PadInput::input[2];
Stick PadInput::r_stick[2];
Stick PadInput::l_stick[2];
float PadInput::L_trigger[2];
float PadInput::R_trigger[2];


//-----------------------------------
// コントローラの情報を更新
//-----------------------------------
void PadInput::UpdateKey()
{
	// 入力キー取得
	GetJoypadXInputState(DX_INPUT_PAD1, &input[0]);
	GetJoypadXInputState(DX_INPUT_PAD2, &input[1]);
	for (int j = 0; j < 2; j++)
	{


		for (int i = 0; i < BUTTONS; i++)
		{
			old_key[j][i] = now_key[j][i];
			now_key[j][i] = input[j].Buttons[i];
		}

		//右スティック
		r_stick[j].x = input[j].ThumbRX;
		r_stick[j].y = input[j].ThumbRY;

		//左スティック
		l_stick[j].x = input[j].ThumbLX;
		l_stick[j].y = input[j].ThumbLY;

		//トリガーの入力情報
		L_trigger[j] = (float)input[j].LeftTrigger / TRIGGER_MAX;
		R_trigger[j] = (float)input[j].RightTrigger / TRIGGER_MAX;
	}

}

bool PadInput::OnButton(int i ,int button)
{
	bool ret = (now_key[i][button] == 1 && old_key[i][button] == 0);
	return ret;
}

bool PadInput::OnPressed(int i, int button)
{
	bool ret = (now_key[i][button] == 1);
	return ret;
}

bool PadInput::OnRelease(int i, int button)
{
	bool ret = (now_key[button] == 0 && old_key[i][button] == 1);
	return ret;
}

Stick PadInput::GetRStick(int i)
{

	return r_stick[i];

}

Stick PadInput::GetLStick(int i)
{
	return l_stick[i];
}

float PadInput::GetLTrigger(int i)
{
	return  L_trigger[i];
}

float PadInput::GetRTrigger(int i)
{
	return  R_trigger[i];
}


char PadInput::GetOldKey(const int i, const int j)
{
	return old_key[i][j];
}

char PadInput::GetNowKey(const int i, const int j)
{
	return now_key[i][j];
}
