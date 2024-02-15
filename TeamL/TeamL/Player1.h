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
	void SetFuel(bool flg);		//�R���t���O�ݒ菈��

private:

};