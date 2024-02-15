#include"Player1.h"
#include"PadInput.h"
#include"DxLib.h"

#define FUEL (1000.0f)
#define LOW (-23)
#define HIGH (-35)

//コンストラクタ
Player1::Player1()
{
	view_charx = 0;
	location.x = 80.0f;
	location.y = 300.0f;
	area.height = 200.0f;
	area.width = 200.0f;
	R = 30;
	speed = 5.0f;
	count = 0;
	g = 0.0f;
	ground = 690.0f;

	hp = 3;
	imgae= LoadGraph("../imege/Player1.png");

	fuel = FUEL;
	low = LOW;
	high = HIGH;
	type = 0;
	abs = 0;
	is_jump = false;
	is_fly = false;
	is_fuel = false;
}

//デストラクタ
Player1::~Player1()
{

}

//更新処理
void Player1::Update(int view_charx)
{
	this->view_charx = view_charx;
	Move();
	Flg();
	Jump(type);
	Fly();
	Fuel();
}

//描画処理
void Player1::Draw()
{
	DrawRotaGraph(location.x + view_charx, location.y, 1.0, 0, imgae, TRUE);
}

//移動処理
void Player1::Move()
{
	//左移動処理
	if (PadInput::OnPressed(0,XINPUT_BUTTON_DPAD_LEFT) == 1)
	{
		if (location.x > 0.0f + area.width)
		{
			location.x -= speed;
		}
	}

	//右移動処理
	if (PadInput::OnPressed(0,XINPUT_BUTTON_DPAD_RIGHT) == 1)
	{
		if (location.x < 1280.0f - area.width)
		{
			location.x += speed;
		}
	}
}

//判定処理
void Player1::Flg()
{
	//着地した時の処理と画面外に行かないようにする処理
	if (location.y >= ground)
	{
		location.y = ground;
		g = 0.0f;
		count = 0;
		SetJump(false);
		SetFly(false);
		SetFuel(true);
	}
	if (location.y <= area.height)
	{
		location.y = area.height;
	}

	//Aボタンを押したら＆ジャンプ中でないなら、小ジャンプをする
	if (PadInput::OnPressed(0,XINPUT_BUTTON_A) == 1 && is_jump == false)
	{		
		//空中でジャンプすると燃料を消費する
		if (is_fly == true)
		{
			fuel += LOW;
		}

		//ジャンプ中にする
		SetJump(true);
		low = LOW;
		type = low;
		abs = -type;
	}

	//Bボタンを押しら＆ジャンプ中でないなら、大ジャンプ
	if (PadInput::OnPressed(0,XINPUT_BUTTON_B) == 1 && is_jump == false)
	{
		//燃料を消費する
		fuel += HIGH;

		//ジャンプ中にする
		SetJump(true);
		high = HIGH;
		type = high;
		abs = -type;
	}

	//Rトリガーを押した値によって上昇
	if (PadInput::GetRTrigger(0) != 0 )
	{
		//浮遊中にする
		SetFly(true);

		//燃料があったら上昇する
		if (location.y > area.height&&is_fuel==true)
		{
			location.y -= PadInput::GetRTrigger(0) * 5;
		}

		//ジャンプ中だったらジャンプ中断
		if (is_jump == true)
		{
			SetJump(false);
		}
		count = 1;
	}

	//Lトリガーを押した値によって下降
	if (PadInput::GetLTrigger(0) != 0)
	{
		//下降処理
		if (location.y < ground)
		{
			location.y += PadInput::GetLTrigger(0) * 5;
		}
	}

	//下ボタンを押して浮遊解除
	if (PadInput::OnPressed(0,XINPUT_BUTTON_DPAD_DOWN) == 1)
	{
		SetFuel(false);
	}
}

//ジャンプ処理
void Player1::Jump(int jump)
{
	if (is_jump==true)
	{
		//上昇する
		if (jump < 0)
		{
			location.y += jump / 2;
			type++;
		}
		//下降する
		else
		{
			if (ground - location.y > 0)
			{
				location.y += jump / 2;
				type++;
			}
		}
	}
}

//落下処理
void Player1::Fly()
{
	//燃料がなかったら落下する
	if (is_fuel == false && ground - location.y > 0)
	{
		location.y += g / 2;
		g++;
	}
}

//燃料ゲージ処理
void Player1::Fuel()
{
	if (is_jump == false)
	{
		//ジャンプ中でなく空中にいれば燃料を消費する
		if (location.y < ground && fuel>0.0f)
		{
			fuel--;
		}

		//燃料が無くなったフラグを立てる
		if (fuel<=0.0f)
		{
			SetFuel(false);
		}

		//着地していると燃料を回復する
		if (location.y >= ground && fuel < FUEL)
		{
			fuel++;
		}
	}
	//ジャンプ中なら燃料を回復する
	else if (fuel < FUEL)
	{
		fuel++;
	}
}

//ジャンプフラグ設定処理(ジャンプ中＝true、着地＝false)
void Player1::SetJump(bool flg)
{
	is_jump = flg;
}

//浮遊フラグ設定処理(浮遊中＝true、着地＝false)
void Player1::SetFly(bool flg)
{
	is_fly = flg;
}

//燃料フラグ設定処理(ある＝true、ない＝false)
void Player1::SetFuel(bool flg)
{
	is_fuel = flg;
}

//-----------------------------------
// この関数呼ぶとHPが減る
//-----------------------------------
void Player1::Damage()
{
	hp--;
}

//-----------------------------------
// HP取得
//-----------------------------------
int  Player1::GetHP()
{
	return hp;
}




///****************************************************************/
///*	プロジェクト名:		テスト					*/
///*	内容：		playerクラスの作成									*/
///*	日付：		２０２４年０２月１4日							*/
///*	コンパイラ:													*/
///*	note:														*/
///*	作成者：	上間							*/
///****************************************************************/
//
//Player1::Player1()
//{
//	view_charx = 0;
//	location.x = 80.0f;
//	location.y = 300.0f;
//	area.height = 200.0f;
//	area.width = 200.0f;
//	speed = 5.0f;
//	hp = 3;
//	imgae= LoadGraph("../imege/Player1.png");
//
//}
//
//Player1::~Player1()
//{
//}
//
//void Player1::Update(int view_charx)
//{
//}
//
//void Player1::Draw()
//{
//
//}
//
//void Player1::Move()
//{
//	// スティックの感度
//	const int stick_sensitivity = 200;
//
//	stick_x = PadInput::GetLStick(0).x;
//
//	//スティックの受付
//	if (stick_x > stick_sensitivity || stick_x < stick_sensitivity * -1)
//	{
//		if (stick_x > 0)
//		{
//			location.x
//		}
//	}
//}
//
//void Player1::Flg()
//{
//
//}
//
//void Player1::Descent()
//{
//
//}
//
//void Player1::Damage()
//{
//
//}
//
//int Player1::GetHP()
//{
//	return 0;
//}
