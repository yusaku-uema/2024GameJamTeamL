#pragma once
#include "AbstractScene.h"
#include"PadInput.h"

class Help :
    public AbstractScene
{
	//�w���v�̔w�i�摜
	int help_image;


public:
	//�R���X�g���N�^ 
	Help();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};

