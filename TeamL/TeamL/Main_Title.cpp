/****************************************************************/
/*	プロジェクト名:												*/
/*	ファイル名：												*/
/*	内容：														*/
/*	日付：														*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：													*/
/****************************************************************/
#include "Main_Title.h"
#include"GameMain.h"
#include "common.h"
#include "DxLib.h"
#include"Help.h"
#include"PadInput.h"
#include"setumei.h"

//-----------------------------------
// コンストラクタ
// 宣言したメンバ変数を初期化する場所
//-----------------------------------
Main_Title::Main_Title()
{
	input_margin = 0;

	select_menu = static_cast<int>(MENU::PLAYER_GAME);

	stick_y = 0;

	cursor_y = 300;

	
		

	title_image = LoadGraph("../imege/title.png");

	title_bgm = LoadSoundMem("../BGM/Noesis_2.mp3");

	definite_se = LoadSoundMem("../BGM/決定ボタンを押す1.mp3");

	selection_se = LoadSoundMem("../BGM/カーソル移動1.mp3");

}

//-----------------------------------
// デストラクタ
// メモリ解放    
//-----------------------------------
Main_Title::~Main_Title()
{
	DeleteGraph(title_image);
	DeleteSoundMem(title_bgm);
	DeleteSoundMem(definite_se);
	DeleteSoundMem(selection_se);

}

//-----------------------------------
// 更新処理
//-----------------------------------
AbstractScene* Main_Title::Update()
{
	
	if (CheckSoundMem(title_bgm) != 1)
	{   //BGMが流れていなかったら再生
		PlaySoundMem(title_bgm, DX_PLAYTYPE_LOOP, TRUE); //BGM再生
	}



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

				PlaySoundMem(selection_se, DX_PLAYTYPE_BACK, TRUE); //SE再生

				// メニュー選択肢を一つ前に移動
				select_menu = (select_menu - 1 + static_cast<int>(MENU::MENU_SIZE)) % static_cast<int>(MENU::MENU_SIZE);
			}
			// スティックが下に移動した場合
			else if (stick_y < 0) {

				PlaySoundMem(selection_se, DX_PLAYTYPE_BACK, TRUE); //SE再生

				// メニュー選択肢を一つ次に移動
				select_menu = (select_menu + 1) % static_cast<int>(MENU::MENU_SIZE);
			}

			//連続操作を受け付けないように
			input_margin = 0;

		}


		//十字キーで操作
		if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_UP) || PadInput::OnPressed(XINPUT_BUTTON_DPAD_DOWN))
		{

			if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_UP))
			{

				PlaySoundMem(selection_se, DX_PLAYTYPE_BACK, TRUE); //SE再生

				// メニュー選択肢を一つ前に移動
				select_menu = (select_menu - 1 + static_cast<int>(MENU::MENU_SIZE)) % static_cast<int>(MENU::MENU_SIZE);
			}
			else if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_DOWN))
			{

				PlaySoundMem(selection_se, DX_PLAYTYPE_BACK, TRUE); //SE再生

				// メニュー選択肢を一つ次に移動
				select_menu = (select_menu + 1) % static_cast<int>(MENU::MENU_SIZE);
			}

			//連続入力しないように
			input_margin = 0;

		}

	}

	//カーソルの位置
	switch (select_menu)
	{
	case 0:
		cursor_y = 150; //スタートのカーソル位置
		break;
	case 1:
		cursor_y = 250; //EXITのカーソル位置
		break;
	case 2:
		cursor_y = 350; //EXITのカーソル位置
		break;
	case 3:
		cursor_y = 450;//SETUMEIのカーソル位置
	default:
		break;
	}


	//Aボタンが押されたとき
	if (PadInput::GetNowKey(XINPUT_BUTTON_A) && (PadInput::OnButton(XINPUT_BUTTON_A) == true))
	{


		//BGMを止める
		StopSoundMem(title_bgm);

		PlaySoundMem(definite_se, DX_PLAYTYPE_NORMAL, TRUE); //SE再生

		input_margin = 0;
		MENU current_selection = static_cast<MENU>(select_menu);

		//選択されていたシーンに遷移する
		switch (current_selection)
		{
		case MENU::PLAYER_GAME:
			return new GameMain(); //ゲームメインへ
			break;

		case MENU::HELP:
			return new Help(); //ヘルプ画面
			break;

		case MENU::END: //ゲーム終了
			return 0;
		case MENU::SETUMEI:
			return new Setumei;
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

	SetFontSize(40);

	DrawGraph(0, 0, title_image, FALSE);

	DrawFormatString(850, 150, 0xFFFFFF, "Game Start");

	DrawFormatString(850, 250, 0xFFFFFF, "Help");

	DrawFormatString(850, 350, 0xFFFFFF, "End");

	DrawFormatString(850, 450, 0xFFFFFF, "EXPLANATION");

	//カーソル
	DrawString(800, cursor_y, "■", GetColor(255, 0, 0));
}
