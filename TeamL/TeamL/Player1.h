#pragma once

#include"Collinder.h"

class Player1:public Collinder
{
public:
	bool is_jump;	//�W�����v�\���H
	bool is_fly;	//���V�\���H
	int X;			//�v���C���[��X���W
	int Y;			//�v���C���[��Y���W
	int R;			//�v���C���[�̔��a
	float speed;	//�X�s�[�h
	int low;		//���W�����v�̍���
	int high;		//��W�����v�̍���
	int count;		//�W�����v�̍ō��_
	int type;		//�W�����v�̃^�C�v
	int abs;		//�W�����v�̍����̐�Βl
	float fuel;		//�R��
	float g;			//�����ϐ�
	float ground;		//���̍��W

	int view_charx; //��ԁ@�X�N���[������
	int hp; //��ԁ@HP�Ǘ�
	int imgae; //��ԁ@�摜

public:
	Player1();		//�R���X�g���N�^
	~Player1();		//�f�X�g���N�^

	void Update(int view_charx);				//�X�V����
	void Draw();				//�`�揈��
	void Move();				//�ړ�����
	void Flg();					//�W�����v���菈��
	void Jump(int jump);		//�W�����v����
	void SetJump(bool flg);		//�W�����v�t���O�ݒ菈��
	void Fly();					//���V����
	void SetFly(bool flg);		//���V�t���O�ݒ菈��
	void Fuel();				//�R���Q�[�W����
	void Damage(); //��ԁ@���̊֐��Ă΂���HP�����炷
	int GetHP(); //HP�̒l���Q�Əo����悤��

private:

};