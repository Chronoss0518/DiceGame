#include<ChBaseLibrary.h>

#include"../Game/Game.h"
#include"../Charactor/Charactor.h"
#include"FieldObjectBase.h"


std::map<std::string, std::function<ChPtr::Shared<FieldObjectBase>(void)>>FieldObjectBase::createrMap
=
{
	{"Double",[]()->ChPtr::Shared<FieldObjectBase> {return ChPtr::Make_S<FO_Doubles>(); }},
	{"FierBall",[]()->ChPtr::Shared<FieldObjectBase> {return ChPtr::Make_S<FO_FierBall>(); }}
};

ChPtr::Shared<FieldObjectBase> FieldObjectBase::Create(const std::string& _str)
{
	return createrMap[_str]();
}

short FO_Doubles::PointMath(const short _point)
{
	return _point * 2;
}

void FO_FierBall::TurnStunby()
{
	GetGame().GetTurnPlayer().Damage(2);
}

