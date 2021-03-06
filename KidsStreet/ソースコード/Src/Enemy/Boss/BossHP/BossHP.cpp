//BossHP.cpp

#include "BossHP.h"
#include "DxLib.h"
#include "../../../UI/GameUIManager.h"
#include "../../EnemyManager.h"
#include "../../EnemyCommon.h"


namespace
{
	const float UI_posX = 10.0f;
	const float UI_posY = 25.0f;
}


CBossHP::CBossHP()
{
	Init();
}

CBossHP::~CBossHP()
{

}

//初期化
void CBossHP::Init()
{
	//UI管理生成
	CGameUIManager::CreateInstance();
	CGameUIManager* ui_manager = CGameUIManager::GetInstance();
	//背景生成
	hp_ = ui_manager->CreateUI(CGameUIManager::UI_TYPE_HP);
	hp_->Init(BOSS_HP_POS.x, BOSS_HP_POS.y);
	hp_->Load("Data/UI/HP/BossHP.png");
	hp_->SetEndPos(BOSS_HP_END_POS);
}

//読み込み
void CBossHP::Load()
{

}

//各変数などに初期値を設定（セット）
void CBossHP::Set()
{
	
}

//毎フレーム呼ぶ処理
void CBossHP::Step()
{
	//毎週HPをUIに渡す
	CBoss* boss = CEnemyManager::GetInstance()->GetBoss();
	hp_->SetSize(boss->GetHP());
}


//描画
void CBossHP::Draw()
{
	
}


//後処理
void CBossHP::Fin()
{
	//UI管理後処理
	CGameUIManager::GetInstance()->DeleteAll();
}