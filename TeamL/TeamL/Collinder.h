/****************************************************************/
/*	�v���W�F�N�g��:												*/
/*	�t�@�C�����F												*/
/*	���e�F														*/
/*	���t�F														*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF													*/
/****************************************************************/
#pragma once

//�T�C�Y
struct Area
{
	float height;
	float width;

};
//���S���W
struct Location
{
	float X;//���イ����
	float Y;//���イ����
};

class Collinder

{
protected:

	Area area;
	Location location;


public:

	bool HitBox(const class Collinder* collider)const;

	//���S���W�̎擾
	Location Getlocation()const;

	//�摜�̂͂񂯂��̎擾
	Area GetArea()const;

};