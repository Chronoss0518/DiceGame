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