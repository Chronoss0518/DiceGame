#include<ChBaseLibrary.h>
#include<regex>

#include"../Game/Game.h"
#include"../PandoraDice/PandoraDice.h"
#include"../Charactor/Charactor.h"
#include"../CharactorEffectBase/CharactorEffectBase.h"
#include"../FieldObjectBase/FieldObjectBase.h"
#include"DiceScript.h"



void DiceScript::Init()
{
	scripts[0] = &DiceScript::Attack;
	scripts[1] = &DiceScript::CriticalAttack;
	scripts[2] = &DiceScript::BothPlayerAttack;
	scripts[3] = &DiceScript::AbsorptionAttack;
	scripts[4] = &DiceScript::SacrificeAttack;
	scripts[5] = &DiceScript::CreateFieldObject;
	scripts[6] = &DiceScript::CreateCharactorEffectToUser;
	scripts[7] = &DiceScript::CreateCharactorEffectToTarget;
	scripts[8] = &DiceScript::HealingPoint;
	scripts[9] = &DiceScript::HealingPointForTarget;
	scripts[10] = &DiceScript::ChangeLP;
	scripts[11] = &DiceScript::ThrowPandoraDice;
}

void DiceScript::Func(Charactor& _user)
{
	std::string text = CreateTexter(_user);

	printf(text.c_str());

	for (auto&& obj : script)
	{
		scripts[obj];
	}
}


std::string DiceScript::CreateTexter(Charactor& _user)
{
	std::string out = effectText;

	auto&& target = *_user.GetAttackCharactor();

	out = std::regex_replace(effectText.c_str(), std::regex("{u}"), _user.GetName().c_str());
	out = std::regex_replace(effectText.c_str(), std::regex("{t}"), target.GetName().c_str());

	return out;

}

//�ʏ�U��//
void DiceScript::Attack(Charactor& _user)
{
	auto&& target = *_user.GetAttackCharactor();

	printf("%s�Ƀ_���[�W��^����\n", target.GetName().c_str());

	target.Damage(damage);
}

void DiceScript::CriticalAttack(Charactor& _user)
{
	auto&& target = *_user.GetAttackCharactor();

	printf("�N���e�B�J���q�b�g!!\n%s�ɃK�[�h�����̃_���[�W��^����\n", target.GetName().c_str());

	target.CriticalDamage(damage);
}

//���v���C���[�ɍU��//
void DiceScript::BothPlayerAttack(Charactor& _user)
{
	auto&& target = *_user.GetAttackCharactor();

	printf("%s��%s�Ƀ_���[�W��^����\n", _user.GetName().c_str(), target.GetName().c_str());

	target.Damage(damage);

	_user.Damage(damage);

}

//�z���U��//
void DiceScript::AbsorptionAttack(Charactor& _user)
{
	auto&& target = *_user.GetAttackCharactor();

	printf((damage <= 4 ? "%s��LP����%d�|�C���g�z�����\n" : "%s��LP����%d�|�C���g�z�����!!\n"), target.GetName().c_str(), damage);
	
	_user.Heal(target.Damage(damage));
}

//���g��HP���w�萔�ɂ��čU��//
void DiceScript::SacrificeAttack(Charactor& _user)
{

	auto&& target = *_user.GetAttackCharactor();
	
	printf("%s��LP��%d�ɂ��čU���𑱂���\n", _user.GetName().c_str(), setLP);

	_user.SetLP(setLP);

	target.Damage(damage);

}

//�ꕔ�U���𖢗��֔�΂��U��//
void DiceScript::CreateFieldObject(Charactor& _user)
{
	for (auto&& str : createFieldObjectNames)
	{
		_user.GetParticipationGame().AddFieldObject(str, setTurns);
	}
}

void DiceScript::CreateCharactorEffectToUser(Charactor& _user)
{
	auto&& target = *_user.GetAttackCharactor();

	for (auto&& str : createCharactorEffectToUserNames)
	{
		target.AddCharactorEffect(str, setTurns);
	}
}

void DiceScript::CreateCharactorEffectToTarget(Charactor& _user)
{

	for (auto&& str : createCharactorEffectToTargetNames)
	{
		_user.AddCharactorEffect(str, setTurns);
	}
}

//��//
void DiceScript::HealingPoint(Charactor& _user)
{
	_user.Heal(heal);
}

void DiceScript::HealingPointForTarget(Charactor& _user)
{
	auto&& target = *_user.GetAttackCharactor();
	target.Heal(heal);
}

//HP�����ւ���//
void DiceScript::ChangeLP(Charactor& _user)
{
	_user.ChangeLPToAttackTarget();
}

void DiceScript::ThrowPandoraDice(Charactor& _user)
{
	_user.ThrowPandoraDice();
}