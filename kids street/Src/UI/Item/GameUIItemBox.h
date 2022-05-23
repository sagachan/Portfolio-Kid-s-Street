//GameUIItem.h
//ID�ƃt���O�ɂ���Ď����̕`����Ǘ�����

#pragma once

#include "../GameUI.h"
#include "DxLib.h"
#include "../../Item/ItemCommon.h"

class CGameUIItemBox :public CGameUI
{
public:
	CGameUIItemBox();
	~CGameUIItemBox();

public:
	void Init(float posX, float posY) override;	//������
	void Load(const char* file_path) override;		//�ǂݍ���
	void Step() override;							//�X�e�b�v
	void Draw() override;							//�`��
	void Delete() override;							//�폜
	void Fin() override;							//�㏈��


private:
	int handle_;	//�摜�n���h��
	ITEM_ID id_;
};