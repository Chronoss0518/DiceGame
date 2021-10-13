#include<ChBaseLibrary.h>

#include"../Charactor/Charactor.h"
#include"../Game/Game.h"
#include"CharactorEffectBase.h"


ChPtr::Shared<CharactorEffectBase>(*CharactorEffectBase::createrMap[(unsigned char)CharactorEffectNames::None])(void)
={
	[]()->ChPtr::Shared<CharactorEffectBase> {return ChPtr::Make_S<C_AttackDouble>(); },
	[]()->ChPtr::Shared<CharactorEffectBase> {return ChPtr::Make_S<C_GuardEffect>(); },
	[]()->ChPtr::Shared<CharactorEffectBase> {return ChPtr::Make_S<C_StanEffect>(); },
	[]()->ChPtr::Shared<CharactorEffectBase> {return ChPtr::Make_S<C_Ice>(); }
};

ChPtr::Shared<CharactorEffectBase> CharactorEffectBase::Create(const CharactorEffectNames _names)
{
	return _names != CharactorEffectNames::None ? CharactorEffectBase::createrMap[ChStd::EnumCast(_names)]() : nullptr;
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

	if (_point <= 0) return _point;

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

void C_Ice::Init()
{
	printf("%sを凍らせた!!\n次の%sのターンをスキップする。\n", GetCharactor().GetName().c_str(), GetCharactor().GetName().c_str());
}

void C_Ice::TurnStunby()
{
	printf("\n%sはこのターン凍り付いていて行動できません\n", GetCharactor().GetName().c_str());

	GetCharactor().GetParticipationGame().SetTrueEnd();

	SetDeathFlgTrue();
}
