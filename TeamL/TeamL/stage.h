
#pragma once
#include "Collinder.h"

class Stage:
	public Collinder

{

	int camerax;

	int tukiimage1;
	int tukiimage2;
	int tukiimage3;


private:


public:

	Stage(float locationx,float locationy,int width,int height);

	~Stage();

	//�`��ȊO�̍X�V�����s
	void Update(int camerax);

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const ;
};
