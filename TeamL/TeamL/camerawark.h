
#pragma once
#include "AbstractScene.h"

class CameraWork :
	public AbstractScene
{
private:


public:
	CameraWork();
	~CameraWork();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};
