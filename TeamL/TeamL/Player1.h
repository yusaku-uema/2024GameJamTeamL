#pragma once

#include"Collinder.h"

class Player1:public Collinder
{
public:
	bool is_jump;	//�W�����v�\���H
	bool is_fly;	//���V�\���H
	bool is_fuel;	//�R�������邩�H
	int X;			//�v���C���[��X���W
	int Y;			//�v���C���[��Y���W
	int R;			//�v���C���[�̔��a
	int low;		//���W�����v�̍���
	int high;		//��W�����v�̍���
	int count;		//
	int type;		//�W�����v�̃^�C�v
	int abs;		//�W�����v�̍����̐�Βl
	float speed;	//�X�s�[�h
	float fuel;		//�R��
	float g;		//�����ϐ�
	float ground;	//���̍��W

	int view_charx; //��ԁ@�X�N���[������
	int hp; //��ԁ@HP�Ǘ�
	int imgae; //��ԁ@�摜

public:
	Player1();		//�R���X�g���N�^
	~Player1();		//�f�X�g���N�^

	void Update(int view_charx);//�X�V����
	void Draw();				//�`�揈��
	void Move();				//�ړ�����
	void Flg();					//���菈��
	void Jump(int jump);		//�W�����v����
	void Fly();					//��������
	void Fuel();				//�R���Q�[�W����
	void SetJump(bool flg);		//�W�����v�t���O�ݒ菈��
	void SetFly(bool flg);		//���V�t���O�ݒ菈��
	void Damage(); //��ԁ@���̊֐��Ă΂���HP�����炷
	int GetHP(); //HP�̒l���Q�Əo����悤��
	void SetFuel(bool flg);		//�R���t���O�ݒ菈��

private:

};

///****************************************************************/
///*	�v���W�F�N�g��:		�e�X�g									*/
///*	���e�F		player�N���X�̍쐬								*/
///*	���t�F		�Q�O�Q�S�N�O�Q���P4��							*/
///*	�R���p�C��:													*/
///*	note:														*/
///*	�쐬�ҁF	���											*/
///****************************************************************/
//
//class Player1 :public Collinder
//{
//private: //�����o�ϐ���private�Ő錾
//	int view_charx; //��ԁ@�X�N���[������
//	int hp; //��ԁ@HP�Ǘ�
//	int imgae; //��ԁ@�摜
//	int speed; //�ړ��X�s�[�h
//
//	float jumping_power; //�W�����v(��Ɍ�������)
//	float descent_speed; //�~���X�s�[�h
//public:
//	Player1();		//�R���X�g���N�^
//	~Player1();		//�f�X�g���N�^
//
//	void Update(int view_charx);				//�X�V����
//	void Draw();				//�`�揈��
//	void Move();				//�ړ�����
//	void Flg();					//�W�����v���菈��
//	void Descent();             //����
//	void Damage(); //��ԁ@���̊֐��Ă΂���HP�����炷
//	int GetHP(); //HP�̒l���Q�Əo����悤��
//}