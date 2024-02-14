/****************************************************************/
/*	プロジェクト名:		Gamejam 　　チームL						*/
/*	内容：		パット操作										*/
/*	日付：		２０２４年０２月１２日							*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：	名嘉真　愛斗									*/
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
// コントローラの情報を更新
//-----------------------------------
void PadInput::UpdateKey()
{
	// 入力キー取得
	GetJoypadXInputState(DX_INPUT_KEY_PAD1, &input);

	for (int i = 0; i < BUTTONS; i++)
	{
		old_key[i] = now_key[i];
		now_key[i] = input.Buttons[i];
	}

	//右スティック
	r_stick.x = input.ThumbRX;
	r_stick.y = input.ThumbRY;

	//左スティック
	l_stick.x = input.ThumbLX;
	l_stick.y = input.ThumbLY;

	//トリガーの入力情報
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
