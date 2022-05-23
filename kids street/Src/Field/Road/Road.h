//Road.h
//���N���X

#pragma once

#include "DxLib.h"
#include "../FieldCommon.h"
#include "../../Library/Animation/Model/model.h"

class CRoad : public CModel
{
public:
	
public:
	CRoad();
	~CRoad();

public:
	void Init();
	void Load();
	void Set();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

public:
	//�Q�b�^�[
	bool	Is_in_Air() { return air_flg_; }			//�����݋󒆂ɂ��邩�ǂ����A�������Ă��Ȃ����ǂ�����Ԃ�
	MapInfo GetMapInfo() { return mapInfo_; }

	//�Z�b�^�[
	void	SetAirFlg(bool flg) { air_flg_ = flg; }

private:
	MapInfo					mapInfo_;
	bool					air_flg_;
};