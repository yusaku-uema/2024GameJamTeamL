
#pragma once
#include "AbstractScene.h"

class Main_Title :
	public AbstractScene
{
private:


public:
	Main_Title();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};
