/****************************************************************/
/*	�v���W�F�N�g��:												*/
/*	�t�@�C�����F												*/
/*	���e�F														*/
/*	���t�F														*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF													*/
/****************************************************************/
#include "Main_Title.h"
#include"GameMain.h"
#include "common.h"
#include "DxLib.h"
#include"Help.h"
#include"PadInput.h"
#include"setumei.h"

//-----------------------------------
// �R���X�g���N�^
// �錾���������o�ϐ�������������ꏊ
//-----------------------------------
Main_Title::Main_Title()
{
	input_margin = 0;

	select_menu = static_cast<int>(MENU::PLAYER_GAME);

	stick_y = 0;

	cursor_y = 300;

	
		

	title_image = LoadGraph("../imege/title.png");

	title_bgm = LoadSoundMem("../BGM/Noesis_2.mp3");

	definite_se = LoadSoundMem("../BGM/����{�^��������1.mp3");

	selection_se = LoadSoundMem("../BGM/�J�[�\���ړ�1.mp3");

}

//-----------------------------------
// �f�X�g���N�^
// ���������    
//-----------------------------------
Main_Title::~Main_Title()
{
	DeleteGraph(title_image);
	DeleteSoundMem(title_bgm);
	DeleteSoundMem(definite_se);
	DeleteSoundMem(selection_se);

}

//-----------------------------------
// �X�V����
//-----------------------------------
AbstractScene* Main_Title::Update()
{
	
	if (CheckSoundMem(title_bgm) != 1)
	{   //BGM������Ă��Ȃ�������Đ�
		PlaySoundMem(title_bgm, DX_PLAYTYPE_LOOP, TRUE); //BGM�Đ�
	}



	// ����Ԋu����
	const int max_input_margin = 10;

	// �X�e�B�b�N�̊��x
	const int stick_sensitivity = 20000;

	//���쎞�ԁA�Ԋu
	if (input_margin < max_input_margin)
	{
		input_margin++;
	}
	else //����
	{

		// �X�e�B�b�N��Y���W���擾
		//int stick_y = PadInput::GetLStick().y;
		stick_y = PadInput::GetLStick().y;

		//�X�e�B�b�N�̎�t
		if (stick_y > stick_sensitivity || stick_y < stick_sensitivity * -1)
		{

			// �X�e�B�b�N����Ɉړ������ꍇ
			if (stick_y > 0) {

				PlaySoundMem(selection_se, DX_PLAYTYPE_BACK, TRUE); //SE�Đ�

				// ���j���[�I��������O�Ɉړ�
				select_menu = (select_menu - 1 + static_cast<int>(MENU::MENU_SIZE)) % static_cast<int>(MENU::MENU_SIZE);
			}
			// �X�e�B�b�N�����Ɉړ������ꍇ
			else if (stick_y < 0) {

				PlaySoundMem(selection_se, DX_PLAYTYPE_BACK, TRUE); //SE�Đ�

				// ���j���[�I����������Ɉړ�
				select_menu = (select_menu + 1) % static_cast<int>(MENU::MENU_SIZE);
			}

			//�A��������󂯕t���Ȃ��悤��
			input_margin = 0;

		}


		//�\���L�[�ő���
		if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_UP) || PadInput::OnPressed(XINPUT_BUTTON_DPAD_DOWN))
		{

			if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_UP))
			{

				PlaySoundMem(selection_se, DX_PLAYTYPE_BACK, TRUE); //SE�Đ�

				// ���j���[�I��������O�Ɉړ�
				select_menu = (select_menu - 1 + static_cast<int>(MENU::MENU_SIZE)) % static_cast<int>(MENU::MENU_SIZE);
			}
			else if (PadInput::OnPressed(XINPUT_BUTTON_DPAD_DOWN))
			{

				PlaySoundMem(selection_se, DX_PLAYTYPE_BACK, TRUE); //SE�Đ�

				// ���j���[�I����������Ɉړ�
				select_menu = (select_menu + 1) % static_cast<int>(MENU::MENU_SIZE);
			}

			//�A�����͂��Ȃ��悤��
			input_margin = 0;

		}

	}

	//�J�[�\���̈ʒu
	switch (select_menu)
	{
	case 0:
		cursor_y = 150; //�X�^�[�g�̃J�[�\���ʒu
		break;
	case 1:
		cursor_y = 250; //EXIT�̃J�[�\���ʒu
		break;
	case 2:
		cursor_y = 350; //EXIT�̃J�[�\���ʒu
		break;
	case 3:
		cursor_y = 450;//SETUMEI�̃J�[�\���ʒu
	default:
		break;
	}


	//A�{�^���������ꂽ�Ƃ�
	if (PadInput::GetNowKey(XINPUT_BUTTON_A) && (PadInput::OnButton(XINPUT_BUTTON_A) == true))
	{


		//BGM���~�߂�
		StopSoundMem(title_bgm);

		PlaySoundMem(definite_se, DX_PLAYTYPE_NORMAL, TRUE); //SE�Đ�

		input_margin = 0;
		MENU current_selection = static_cast<MENU>(select_menu);

		//�I������Ă����V�[���ɑJ�ڂ���
		switch (current_selection)
		{
		case MENU::PLAYER_GAME:
			return new GameMain(); //�Q�[�����C����
			break;

		case MENU::HELP:
			return new Help(); //�w���v���
			break;

		case MENU::END: //�Q�[���I��
			return 0;
		case MENU::SETUMEI:
			return new Setumei;
			break;

		default:
			printfDx("�������ȋ@�\�ł��B\n");
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

	//�J�[�\��
	DrawString(800, cursor_y, "��", GetColor(255, 0, 0));
}
