#pragma once
class VBullet //�N���X��
{
public: //�A�N�Z�X�w��q
	float x;           //X���W���
	float y;           //Y���W���
	float radius;		// ���a
	float color;        //�F���
	float move_x;		// �i�s�����x�N�g�����X
	float move_y;		// �i�s�����x�N�g�����Y

	VBullet();
	VBullet(float mx, float my,float vx, float vy);   //������
	~VBullet();

	void Draw();      //�`�悷�鏈��
	void Update();    //�X�V����
	void Move();      //�ړ�����
};