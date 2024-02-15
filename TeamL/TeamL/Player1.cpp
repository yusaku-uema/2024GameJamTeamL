#include"Player1.h"
#include"PadInput.h"
#include"DxLib.h"

#define FUEL (1000.0f)
#define LOW (-23)
#define HIGH (-35)

//�R���X�g���N�^
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

//�f�X�g���N�^
Player1::~Player1()
{

}

//�X�V����
void Player1::Update(int view_charx)
{
	this->view_charx = view_charx;
	Move();
	Flg();
	Jump(type);
	Fly();
	Fuel();
}

//�`�揈��
void Player1::Draw()
{
	DrawRotaGraph(location.x + view_charx, location.y, 1.0, 0, imgae, TRUE);
}

//�ړ�����
void Player1::Move()
{
	//���ړ�����
	if (PadInput::OnPressed(0,XINPUT_BUTTON_DPAD_LEFT) == 1)
	{
		if (location.x > 0.0f + area.width)
		{
			location.x -= speed;
		}
	}

	//�E�ړ�����
	if (PadInput::OnPressed(0,XINPUT_BUTTON_DPAD_RIGHT) == 1)
	{
		if (location.x < 1280.0f - area.width)
		{
			location.x += speed;
		}
	}
}

//���菈��
void Player1::Flg()
{
	//���n�������̏����Ɖ�ʊO�ɍs���Ȃ��悤�ɂ��鏈��
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

	//A�{�^�����������灕�W�����v���łȂ��Ȃ�A���W�����v������
	if (PadInput::OnPressed(0,XINPUT_BUTTON_A) == 1 && is_jump == false)
	{		
		//�󒆂ŃW�����v����ƔR���������
		if (is_fly == true)
		{
			fuel += LOW;
		}

		//�W�����v���ɂ���
		SetJump(true);
		low = LOW;
		type = low;
		abs = -type;
	}

	//B�{�^���������灕�W�����v���łȂ��Ȃ�A��W�����v
	if (PadInput::OnPressed(0,XINPUT_BUTTON_B) == 1 && is_jump == false)
	{
		//�R���������
		fuel += HIGH;

		//�W�����v���ɂ���
		SetJump(true);
		high = HIGH;
		type = high;
		abs = -type;
	}

	//R�g���K�[���������l�ɂ���ď㏸
	if (PadInput::GetRTrigger(0) != 0 )
	{
		//���V���ɂ���
		SetFly(true);

		//�R������������㏸����
		if (location.y > area.height&&is_fuel==true)
		{
			location.y -= PadInput::GetRTrigger(0) * 5;
		}

		//�W�����v����������W�����v���f
		if (is_jump == true)
		{
			SetJump(false);
		}
		count = 1;
	}

	//L�g���K�[���������l�ɂ���ĉ��~
	if (PadInput::GetLTrigger(0) != 0)
	{
		//���~����
		if (location.y < ground)
		{
			location.y += PadInput::GetLTrigger(0) * 5;
		}
	}

	//���{�^���������ĕ��V����
	if (PadInput::OnPressed(0,XINPUT_BUTTON_DPAD_DOWN) == 1)
	{
		SetFuel(false);
	}
}

//�W�����v����
void Player1::Jump(int jump)
{
	if (is_jump==true)
	{
		//�㏸����
		if (jump < 0)
		{
			location.y += jump / 2;
			type++;
		}
		//���~����
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

//��������
void Player1::Fly()
{
	//�R�����Ȃ������痎������
	if (is_fuel == false && ground - location.y > 0)
	{
		location.y += g / 2;
		g++;
	}
}

//�R���Q�[�W����
void Player1::Fuel()
{
	if (is_jump == false)
	{
		//�W�����v���łȂ��󒆂ɂ���ΔR���������
		if (location.y < ground && fuel>0.0f)
		{
			fuel--;
		}

		//�R���������Ȃ����t���O�𗧂Ă�
		if (fuel<=0.0f)
		{
			SetFuel(false);
		}

		//���n���Ă���ƔR�����񕜂���
		if (location.y >= ground && fuel < FUEL)
		{
			fuel++;
		}
	}
	//�W�����v���Ȃ�R�����񕜂���
	else if (fuel < FUEL)
	{
		fuel++;
	}
}

//�W�����v�t���O�ݒ菈��(�W�����v����true�A���n��false)
void Player1::SetJump(bool flg)
{
	is_jump = flg;
}

//���V�t���O�ݒ菈��(���V����true�A���n��false)
void Player1::SetFly(bool flg)
{
	is_fly = flg;
}

//�R���t���O�ݒ菈��(���遁true�A�Ȃ���false)
void Player1::SetFuel(bool flg)
{
	is_fuel = flg;
}

//-----------------------------------
// ���̊֐��ĂԂ�HP������
//-----------------------------------
void Player1::Damage()
{
	hp--;
}

//-----------------------------------
// HP�擾
//-----------------------------------
int  Player1::GetHP()
{
	return hp;
}




///****************************************************************/
///*	�v���W�F�N�g��:		�e�X�g					*/
///*	���e�F		player�N���X�̍쐬									*/
///*	���t�F		�Q�O�Q�S�N�O�Q���P4��							*/
///*	�R���p�C��:													*/
///*	note:														*/
///*	�쐬�ҁF	���							*/
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
//	// �X�e�B�b�N�̊��x
//	const int stick_sensitivity = 200;
//
//	stick_x = PadInput::GetLStick(0).x;
//
//	//�X�e�B�b�N�̎�t
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
