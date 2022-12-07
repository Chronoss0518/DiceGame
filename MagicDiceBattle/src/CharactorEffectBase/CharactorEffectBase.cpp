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
	printf("%s�͗͂����߂�!!\n"
		"(����%s�̍U�����A�_���[�W2�{!!)\n",
		GetCharactor().GetName().c_str(),
		GetCharactor().GetName().c_str());
}

short C_AttackDouble::PointMath(const short _point)
{
	printf("%s�͗͂����߂Ă������߁A�_���[�W2�{!!\n",
		GetCharactor().GetName().c_str());

	SetDeathFlgTrue();

	return _point * 2;
}

void C_GuardEffect::Init()
{
	printf("%s�͎����ł߂�!!\n"
		"(����%s�̃^�[���܂�%s���󂯂�_���[�W��0�ƂȂ�)\n",
		GetCharactor().GetName().c_str(), 
		GetCharactor().GetName().c_str(),
		GetCharactor().GetName().c_str());
}

short C_GuardEffect::PointMath(const short _point)
{

	if (_point <= 0) return _point;

	printf("%s�͍U�����K�[�h����\n", GetCharactor().GetName().c_str());

	SetDeathFlgTrue();

	return 0;

}

void C_StanEffect::Init()
{
	printf("����%s�̃^�[�����X�L�b�v����B\n", GetCharactor().GetName().c_str());
}

void C_StanEffect::TurnStunby()
{
	printf("\n%s�͂��̃^�[���s���ł��܂���\n", GetCharactor().GetName().c_str());

	GetCharactor().GetParticipationGame().SetTrueEnd();

	SetDeathFlgTrue();
}

void C_Ice::Init()
{
	printf("%s�𓀂点��!!\n����%s�̃^�[�����X�L�b�v����B\n", GetCharactor().GetName().c_str(), GetCharactor().GetName().c_str());
}

void C_Ice::TurnStunby()
{
	printf("\n%s�͂��̃^�[������t���Ă��čs���ł��܂���\n", GetCharactor().GetName().c_str());

	GetCharactor().GetParticipationGame().SetTrueEnd();

	SetDeathFlgTrue();
}
