#include "ItemBase.h"

CItemBase::CItemBase()
{
	
}

CItemBase::~CItemBase()
{

}

//現在使用継続しているかどうか
bool CItemBase::GetMoveFlg()
{
	if (isUse_ && !endflg_)
	{
		return true;
	}
	else
	{
		return false; 
	}
}