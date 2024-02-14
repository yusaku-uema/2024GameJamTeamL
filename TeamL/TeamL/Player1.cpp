#include"Player1.h"
#include"PadInput.h"
#include"DxLib.h"

//�R���X�g���N�^
Player1::Player1()
{
	X = 0;
	Y = 0;
	R = 30;
	is_jump = 0;
	is_fly = 1;
	count = 0;
	low = 0;
	high = 0;
	type = 0;
	abs = 0;
	fuel = 100.0f;
	h = 0;
	ground = 400;
}

//�f�X�g���N�^
Player1::~Player1()
{

}

//�X�V����
void Player1::Update()
{
	Move();
	Flg();
	Fly();
	Jump(type);
}

//�`�揈��
void Player1::Draw()
{
	DrawCircle(X, Y, R, 0xffffff, TRUE);
}

//�ړ�����
void Player1::Move()
{
	//���ړ�����
	if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_LEFT) == 1)
	{
		if (X > 0 + R)
		{
			X -= 5;
		}
	}

	//�E�ړ�����
	if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) == 1)
	{
		if (X < 1280 - R)
		{
			X += 5;
		}
	}
}

//���菈��
void Player1::Flg()
{
	//�n�ʂɂ�����t���O��true�ɂ���
	if (Y >= ground)
	{
		Y = ground;
		h = 0;
		SetJump(false);
		SetFly(true);
	}
	if (Y <= R)
	{
		Y = R;
	}

	//A�{�^�����������珬�W�����v
	if (PadInput::OnPressed(XINPUT_BUTTON_A) == 1 && is_jump == false)
	{
		SetJump(true);
		low = -20;
		type = low;
		abs = -type;
	}

	//B�{�^���������đ�W�����v
	if (PadInput::OnPressed(XINPUT_BUTTON_B) == 1 && is_jump == false)
	{
		SetJump(true);
		high = -30;
		type = high;
		abs = -type;
	}

	//R�g���K�[�𒷉������ď㏸
	if (PadInput::GetRTrigger() > 0)
	{
		SetFly(true);
		if (Y > R)
		{
			Y -= PadInput::GetRTrigger() * 5;
		}
		//�W�����v���f
		if (is_jump == true)
		{
			SetJump(false);
		}
	}

	//L�g���K�[�𒷉������ĉ��~
	if (PadInput::GetLTrigger() != 0)
	{
		if (Y < ground)
		{
			Y += PadInput::GetLTrigger() * 5;
		}
	}

	//���V����
	if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_DOWN) == 1)
	{
		SetFly(false);
	}
}

//�W�����v����
void Player1::Jump(int jump)
{
	if (is_jump == true)
	{
		if (jump < 0)
		{
			Y += jump / 2;
			type++;
		}
		else
		{
			if (ground - Y > 0)
			{
				Y += jump / 2;
				type++;
			}
		}
	}
}

//��������
void Player1::Fly()
{
	if (is_fly == false)
	{
		if (ground - Y > 0)
		{
			Y += h / 2;
			h++;
		}
	}
}

//�W�����v�t���O�ݒ菈��
void Player1::SetJump(bool flg)
{
	is_jump = flg;
}

//���V�t���O�ݒ菈��
void Player1::SetFly(bool flg)
{
	is_fly = flg;
}