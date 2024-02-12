#include "Main_Title.h"
#include "common.h"
#include "DxLib.h"
#include"PadInput.h"


//-----------------------------------
// コンストラクタ
// 宣言したメンバ変数を初期化する場所
//-----------------------------------
Main_Title::Main_Title()
{
	input_margin = 0;

	select_menu = static_cast<int>(MENU::PLAYER_GAME);

	cursor_y = 0;
	//title_image = LoadGraph("image/title.png");
	title_image = 0;
}

//-----------------------------------
// 更新処理
//-----------------------------------
AbstractScene* Main_Title::Update()
{
	// 操作間隔時間
	const int max_input_margin = 10;

	// スティックの感度
	const int stick_sensitivity = 20000;

	//操作時間、間隔
	if (input_margin < max_input_margin)
	{
		input_margin++;
	}
	else //操作
	{

		// スティックのY座標を取得
		//int stick_y = PadInput::GetLStick().y;
		stick_y = PadInput::GetLStick().y;

		//スティックの受付
		if (stick_y > stick_sensitivity || stick_y < stick_sensitivity * -1)
		{

			// スティックが上に移動した場合
			if (stick_y > 0) {
				// メニュー選択肢を一つ前に移動
				select_menu = (select_menu - 1 + static_cast<int>(MENU::MENU_SIZE)) % static_cast<int>(MENU::MENU_SIZE);
			}
			// スティックが下に移動した場合
			else if (stick_y < 0) {
				// メニュー選択肢を一つ次に移動
				select_menu = (select_menu + 1) % static_cast<int>(MENU::MENU_SIZE);
			}

			input_margin = 0;

		}

		if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_UP) || PadInput::OnPressed(XINPUT_BUTTON_DPAD_DOWN))
		{

			if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_UP))
			{
				// メニュー選択肢を一つ前に移動
				select_menu = (select_menu - 1 + static_cast<int>(MENU::MENU_SIZE)) % static_cast<int>(MENU::MENU_SIZE);
			}
			else if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_DOWN))
			{
				// メニュー選択肢を一つ次に移動
				select_menu = (select_menu + 1) % static_cast<int>(MENU::MENU_SIZE);
			}

			input_margin = 0;

		}

	}

	//カーソルの位置
	switch (select_menu)
	{
	case 0:
		cursor_y = 0; //スタートのカーソル位置
		break;
	case 1:
		cursor_y = 400; //EXITのカーソル位置
		break;
	default:
		break;
	}


	if (PadInput::GetNowKey(XINPUT_BUTTON_A) && (PadInput::OnButton(XINPUT_BUTTON_A) == true))
	{
		input_margin = 0;
		MENU current_selection = static_cast<MENU>(select_menu);

		switch (current_selection)
		{
		case MENU::PLAYER_GAME:
			//return new GameMain();
			break;

		case MENU::HELP:
			return this;
			break;

		default:
			printfDx("未実装な機能です。\n");
			break;
		}

	}

	return this;
}

void Main_Title::Draw()const
{
	DrawFormatString(100, 100, 0xff0000,"テスト", TRUE);
}
