#include<ChBaseLibrary.h>

#include"../Charactor/Charactor.h"
#include"../Game/Game.h"
#include"CharactorEffectBase.h"


std::map<std::string, std::function<ChPtr::Shared<CharactorEffectBase>(void)>>CharactorEffectBase::createrMap
=
{
	{"Double",[]()->ChPtr::Shared<CharactorEffectBase> {return ChPtr::Make_S<C_AttackDouble>(); }},
	{"Guard",[]()->ChPtr::Shared<CharactorEffectBase> {return ChPtr::Make_S<C_GuardEffect>(); }},
	{"Stan",[]()->ChPtr::Shared<CharactorEffectBase> {return ChPtr::Make_S<C_StanEffect>(); }}
};

ChPtr::Shared<CharactorEffectBase> CharactorEffectBase::Create(const std::string& _str)
{
	return createrMap[_str]();
}

void C_AttackDouble::Init()
{
	printf("%sは力をためた!!\n"
		"(次の%sの攻撃時、ダメージ2倍!!)\n",
		GetCharactor().GetName().c_str(),
		GetCharactor().GetName().c_str());
}

short C_AttackDouble::PointMath(const short _point)
{
	printf("%sは力をためていたため、ダメージ2倍!!\n",
		GetCharactor().GetName().c_str());

	SetDeathFlgTrue();

	return _point * 2;
}

void C_GuardEffect::Init()
{
	printf("%sは守りを固めた!!\n"
		"(次の%sのターンまで%sが受けるダメージは0となる)\n",
		GetCharactor().GetName().c_str(), 
		GetCharactor().GetName().c_str(),
		GetCharactor().GetName().c_str());
}

short C_GuardEffect::PointMath(const short _point)
{

	printf("%sは攻撃をガードした\n", GetCharactor().GetName().c_str());

	SetDeathFlgTrue();

	return 0;

}

void C_StanEffect::Init()
{
	printf("次の%sのターンをスキップする。\n", GetCharactor().GetName().c_str());
}

void C_StanEffect::TurnStunby()
{
	printf("\n%sはこのターン行動できません\n", GetCharactor().GetName().c_str());

	GetCharactor().GetParticipationGame().SetTrueEnd();

	SetDeathFlgTrue();
}