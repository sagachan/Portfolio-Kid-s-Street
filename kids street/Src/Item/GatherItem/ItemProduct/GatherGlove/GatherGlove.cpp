//GatherGlove.cpp

#include "GatherGlove.h"
#include "DxLib.h"
#include "../../GatherFactory/GatherManager.h"
#include "../../../ItemCommon.h"
#include "../../../../Player/PlayerManager.h"
#include "../../../../Library/MyMath/MyMath.h"
#include "../../GatherFactory/GatherBase/GatherItem.h"
#include "../../../../UI/GameUIManager.h"

namespace
{
	
}

//������
void CGatherGlove::Init()
{
	//�A�C�e���Ǘ�����
	CGatherManager* gatherManager = CGatherManager::GetInstance();
	//�t�B�[���h��ɃA�C�e���𐶐�
	CGatherItem* gatherGlove = gatherManager->CreateItem(CGatherManager::BOSS_ONLY_ITEM);
	gatherGlove->Init(GLOVE_POS);
	gatherGlove->Load("Data/Item/glove.x");

	//UI�Ǘ�
	CGameUIManager* uiManager = CGameUIManager::GetInstance();

	//UI�Ƃ��Ă̐���
	CGameUI* uiGlove = uiManager->CreateUI(CGameUIManager::UI_TYPE_ITEM);
	uiGlove->Init(ITEM_UI_GLOVE, ITEM_UI_Y);
	uiGlove->Load("Data/UI/ItemBox/GloveUI.png");

	//���̃A�C�e�����I�΂�Ă���ۂɋ����\������UI����
	CGameUI* uiGloveBox = uiManager->CreateUI(CGameUIManager::UI_TYPE_ITEMBOX);
	uiGloveBox->Init(ITEM_UI_GLOVE, ITEM_UI_Y);
	uiGloveBox->Load("Data/UI/ItemBox/ItemBoxPoint.png");
}


//���t���[���Ăԏ���
void CGatherGlove::Step()
{
	Gather();
}




//�A�C�e�����W�X�V
void CGatherGlove::Gather()
{
	//�v���C���[���A�C�e���ɒ�߂����͈͓���ʂ����Ƃ��Ɋl���ł���悤�ɂ���
	CPlayer* player = CPlayerManager::GetInstance()->GetPlayer();
	VECTOR playerPos = player->GetPosition();

	if (CMyMath::RadiusCheck(playerPos.x, ITEM_GATHER_AREA, GLOVE_POS.x) &&
		CMyMath::RadiusCheck(playerPos.z, ITEM_GATHER_AREA, GLOVE_POS.z))
	{
		//�G���A���ɂ���Ȃ�t���O�𗧂Ă�
		CGatherManager::GetInstance()->GatherItem(GLOVE);
	}

}