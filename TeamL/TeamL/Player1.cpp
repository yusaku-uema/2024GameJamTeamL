#include"Player1.h"
#include"PadInput.h"
#include"DxLib.h"

#define FUEL (100.0f)

//コンストラクタ
Player1::Player1()
{
	location.X = 320;
	location.Y = 300;
	area.height = 30;
	area.width = 30;
	R = 30;
	is_jump = 0;
	is_fly = 1;
	count = 0;
	low = 0;
	high = 0;
	type = 0;
	abs = 0;
	fuel = FUEL;
	h = 0;
	ground = 400;
}

//デストラクタ
Player1::~Player1()
{

}

//更新処理
void Player1::Update()
{
	Move();
	Flg();
	Fly();
	Jump(type);
}

//描画処理
void Player1::Draw()
{
	DrawCircle(location.X, location.Y, R, 0xffffff, TRUE);
}

//移動処理
void Player1::Move()
{
	//左移動処理
	if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_LEFT) == 1)
	{
		if (location.X > 0 + area.width)
		{
			X -= 5;
		}
	}

	//右移動処理
	if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) == 1)
	{
		if (location.X < 1280 - area.width)
		{
			location.X += 5;
		}
	}
}

//判定処理
void Player1::Flg()
{
	//地面についたらフラグをtrueにする
	if (location.Y >= ground)
	{
		location.Y = ground;
		h = 0;
		SetJump(false);
		SetFly(true);
	}
	if (location.Y <= area.width)
	{
		location.Y = area.width;
	}

	//Aボタンを押したら小ジャンプ
	if (PadInput::OnPressed(XINPUT_BUTTON_A) == 1 && is_jump == false)
	{
		SetJump(true);
		low = -20;
		type = low;
		abs = -type;
	}

	//Bボタンを押して大ジャンプ
	if (PadInput::OnPressed(XINPUT_BUTTON_B) == 1 && is_jump == false)
	{
		SetJump(true);
		high = -30;
		type = high;
		abs = -type;
	}

	//Rトリガーを長押しして上昇
	if (PadInput::GetRTrigger() > 0)
	{
		SetFly(true);
		if (location.Y > area.width)
		{
			location.Y -= PadInput::GetRTrigger() * 5;
		}
		//ジャンプ中断
		if (is_jump == true)
		{
			SetJump(false);
		}
	}

	//Lトリガーを長押しして下降
	if (PadInput::GetLTrigger() != 0)
	{
		if (location.Y < ground)
		{
			location.Y += PadInput::GetLTrigger() * 5;
		}
	}

	//浮遊解除
	if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_DOWN) == 1)
	{
		SetFly(false);
	}
}

//ジャンプ処理
void Player1::Jump(int jump)
{
	if (is_jump == true)
	{
		if (jump < 0)
		{
			location.Y += jump / 2;
			type++;
		}
		else
		{
			if (ground - location.Y > 0)
			{
				location.Y += jump / 2;
				type++;
			}
		}
	}
}

//落下処理
void Player1::Fly()
{
	if (is_fly == false)
	{
		if (ground - location.Y > 0)
		{
			location.Y += h / 2;
			h++;
		}
	}
}

//ジャンプフラグ設定処理
void Player1::SetJump(bool flg)
{
	is_jump = flg;
}

//浮遊フラグ設定処理
void Player1::SetFly(bool flg)
{
	is_fly = flg;
}

//燃料ゲージ処理
void Player1::Fuel()
{
	if (is_jump != true)
	{
		if (location.Y < ground && fuel>0.0f)
		{
			fuel--;
		}
		else
		{
			SetFly(false);
		}
		if (location.Y >= ground && fuel < 100.0f)
		{
			fuel++;
		}
	}

}