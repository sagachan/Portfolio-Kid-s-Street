//GatherPencil.h
//GatherPencilシーン

#pragma once

#include "../../GatherFactory/GatherBase/GatherBase.h"

//GatherPencilクラス
class CGatherPencil : public CGatherBase
{
public:
	CGatherPencil() {}
	~CGatherPencil() {}

	
	void Init() override;			//初期化
	void Load() override {}			//読み込み
	void Set() override {}			//各変数などに初期値を設定（セット）
	void Step() override;			//毎フレーム呼ぶ処理
	void Draw() override {}			//描画
	void Fin() override {}			//後処理

private:
	void Gather();					//アイテム収集更新
};