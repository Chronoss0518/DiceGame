#include<ChBaseLibrary.h>

#include"../Game/Game.h"
#include"../Charactor/Charactor.h"
#include"FieldObjectBase.h"


ChPtr::Shared<FieldObjectBase>(*FieldObjectBase::createrMap[(unsigned char)FieldObjectNames::None])(void)
=
{
	[]()->ChPtr::Shared<FieldObjectBase> {return ChPtr::Make_S<FO_Doubles>(); },
	[]()->ChPtr::Shared<FieldObjectBase> {return ChPtr::Make_S<FO_FireBall>(); }
};

ChPtr::Shared<FieldObjectBase> FieldObjectBase::Create(const FieldObjectNames _names)
{
	return _names != FieldObjectNames::None ? FieldObjectBase::createrMap[ChStd::EnumCast(_names)]() : nullptr;
}

short FO_Doubles::PointMath(const short _point)
{
	return _point * 2;
}

void FO_FireBall::TurnStunby()
{
	GetGame().GetTurnPlayer().Damage(2);
}

