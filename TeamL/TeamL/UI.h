#pragma once

class UI
{
private: //�����o�ϐ��̓v���C�x�[�g�Ő錾
	int num; //�\������HP�̐�
	int image; //�\������摜
public:
	UI();
	void Update(int hp);				//�X�V����
	void Draw();				//�`�揈��
};

