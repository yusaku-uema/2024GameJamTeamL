
#pragma once
#include "AbstractScene.h"

class GameMain :s
	public AbstractScene
{

	int tukiimage1;
	int tukiimage2;
	int tukiimage3;


private:


public:
	GameMain();
	~GameMain();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};
