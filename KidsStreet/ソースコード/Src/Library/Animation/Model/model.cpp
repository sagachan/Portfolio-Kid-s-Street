#include "model.h"


//------------------------------
//		コンストラクタ
//------------------------------
CModel::CModel() : pos_({ 0.0f }), rot_({ 0.0f }), scale_(DEFAULT_SCALE)
, hndl_(-1),oldPos_({ 0.0f }),rad_(0.0f),move_({0.0f}),oldRot_({0.0f}), colNum_(0)
{
}


//------------------------------
//		デストラクタ
//------------------------------
CModel::~CModel()
{
	if (hndl_ != -1)
	{
		MV1DeleteModel(hndl_);
		hndl_ = -1;
	}
}


//---------------------------------
//		初期化
//---------------------------------
void	CModel::Init(void)
{
	Fin();
	pos_ = { 0.0f };
	rot_ = { 0.0f };
	scale_ = DEFAULT_SCALE;
}


//---------------------------------
//		終了処理
//---------------------------------
void	CModel::Fin(void)
{
	DeleteModel();
}


//---------------------------------
//		更新処理
//---------------------------------
void	CModel::Update(void)
{
	MV1SetPosition(hndl_, pos_);
	MV1SetRotationXYZ(hndl_, rot_);
	MV1SetScale(hndl_, scale_);
}


//------------------------------
//		データ読み込み
//------------------------------
bool	CModel::LoadModel(const char* fileName)
{
	if (hndl_ != -1) return false;		// モデル読み込み済み
	hndl_ = MV1LoadModel(fileName);
	if (hndl_ == -1) return false;		// モデルの読み込み失敗
	return true;
}


//------------------------------
//		コピーデータ読み込み
//------------------------------
bool	CModel::DuplicateModel(int srcHndl)
{
	if (hndl_ != -1) return false;		// モデル読み込み済み
	hndl_ = MV1DuplicateModel(srcHndl);
	if (hndl_ == -1) return false;		// モデルの読み込み失敗
	return true;
}


//---------------------------------
//		モデルデータ削除
//---------------------------------
void	CModel::DeleteModel(void)
{
	if (hndl_ == -1) return;

	MV1DeleteModel(hndl_);
	hndl_ = -1;
}


//---------------------------------
//		モデルデータ描画
//---------------------------------
void	CModel::Draw(void)
{
	MV1DrawModel(hndl_);
}
