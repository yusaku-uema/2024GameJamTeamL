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
	location.x = locationx * width;
	location.y = locationy * height;

	//�T�C�Y
	area.width = width;
	area.height = height;

	camerax = 0;

	tukiimage1 = LoadGraph("../imege/tuki.png");
	tukiimage2 = LoadGraph("../imege/tuki2.png");
	tukiimage3 = LoadGraph("../imege/tuki3.png");
	tukiimage4 = LoadGraph("../imege/tuki4.png");
	
	



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
		DrawRotaGraph(location.x - camerax, location.y, 1,0,tukiimage1, FALSE);
		break;
	case 2:
		//DrawRotaGraph(location.x - camerax, location.y,1,0, tukiimage2, FALSE);
		break;
	case 3:
		DrawRotaGraph(location.x - camerax, location.y,1,0, tukiimage3, FALSE);
		break;
	case 4:
		DrawRotaGraph(location.x - camerax, location.y,1,0, tukiimage4, FALSE);
		break;
	}
	
	

}

int Stage::BlockType()
{
	return type;
}
