
#pragma once
#include "AbstractScene.h"
#include"camerawork.h"
#include"stage.h"

class GameMain :
	public AbstractScene

{



private:
	//�т傤�����Ђ傤
	int rendering_coodinates_x;

	CameraWork* camerawork;
	Stage* stage[25][111];

public:
	GameMain();
	~GameMain();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};
