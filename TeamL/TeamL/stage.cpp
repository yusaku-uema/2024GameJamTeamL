/****************************************************************/
/*	�v���W�F�N�g��:												*/
/*	�t�@�C�����F												*/
/*	���e�F														*/
/*	���t�F														*/
/*	�R���p�C��:													*/
/*	note:														*/
/*	�쐬�ҁF													*/
/****************************************************************/
#include"DxLib.h"
#include"stage.h"


Stage::Stage(float locationx, float locationy, int width, int height,int type)
{

	//�`��ʒu
	location.X = locationx * width;
	location.Y = locationy * height;

	//�T�C�Y
	area.width = width;
	area.height = height;

	camerax = 0;

	tukiimage1 = LoadGraph("../imege/tuki.png");
	tukiimage2 = LoadGraph("../imege/tuki2.png");
	
	



	this->type = type;


}

Stage::~Stage()
{
}



void Stage::Update(int camerax)
{


	this->camerax = camerax;



}

void Stage::Draw()const
{

	switch (type)
	{
	
	case 1:
		DrawGraph(location.X - camerax, location.Y, tukiimage1, FALSE);
		break;
	case 2:
		DrawGraph(location.X - camerax, location.Y, tukiimage2, FALSE);
		break;
	}
	
	

}