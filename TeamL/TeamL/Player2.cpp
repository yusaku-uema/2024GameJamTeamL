#include "Player2.h";
#include "DxLib.h";
#include "PadInput.h"
#include "Bullet.h"
#include"VBullet.h"

#define PLAYER2_SIZE_X   (30.0f)

Player2::Player2()
{
	
	location.x = 1200.0f;
	location.y = 350.0f;
	move_y = 0.0f;
	radius = 10.0f;
	view_charx = 0;

	Player2image = LoadGraph("../imege/Player2.png");
	UFOimage = LoadGraph("../imege/UFO.png");

	MoveSE = LoadSoundMem("../BGM/MoveSE.mp3");
}

Player2::~Player2()
{
	DeleteSoundMem(MoveSE);
	DeleteGraph(Player2image);
	DeleteGraph(UFOimage);
}


Player2::Player2(float mx, float my)
{
	location.x = mx;
	location.y = my;
	move_y = 5.0f;
	radius = 10.0f;
}

void Player2::Update(int view_charx)
{
	this->view_charx = view_charx;

	location.y += move_y;

	if (location.y > (480 - radius) || location.y < (0 + radius))
	{
		move_y *= -1.0f;
	}

	Move();
}

void Player2::Draw()
{
	DrawRotaGraph(location.x + view_charx, location.y, 0.5 ,0,Player2image,TRUE);
	DrawRotaGraph(location.x + view_charx, location.y+100, 0.4, 0, UFOimage, TRUE);
}

void Player2::Move()
{
	int stick_y = PadInput::GetLStick(1).y;
		//�L�[���g���ē�����
		if ( location.y>=0.0f+80.0f && stick_y > 2000) // ��L�[�������Ə�ɍs��
		{
			location.y -= 5.0f;
			if (CheckSoundMem(MoveSE) != 1)
			{
				PlaySoundMem(MoveSE, DX_PLAYTYPE_BACK, TRUE);
			}
		}
		//else if (CheckHitKeyAll() == 0)//�L�[�𗣂��Ǝ~�܂�
		//{
		//	location.y += 0.0f;
		//}

		if (location.y <= 550.0f - 130.0f && stick_y < -2000) //���L�[�������Ɖ��ɍs��
		{
			location.y += 5.0f;
			if (CheckSoundMem(MoveSE) != 1)
			{
				PlaySoundMem(MoveSE, DX_PLAYTYPE_BACK, TRUE);
			}
		}

		if (stick_y<2000 && stick_y>-2000)
		{
			StopSoundMem(MoveSE);
		}
		//else if (CheckHitKeyAll() == 0)//�L�[�𗣂��Ǝ~�܂�
		//{
		//	location.y += 0.0f;
		//}
		//
		////�����ɏ㉺�{�^�������Ǝ~�܂�
		//if (CheckHitKey(KEY_INPUT_UP) != FALSE && CheckHitKey(KEY_INPUT_DOWN) != FALSE)
		//{
		//	location.y += 0.0f;
		//}
	
}