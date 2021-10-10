#include<ChBaseLibrary.h>
#include<regex>

#include"../Game/Game.h"
#include"../Charactor/Charactor.h"
#include"../CharactorEffectBase/CharactorEffectBase.h"
#include"../FieldObjectBase/FieldObjectBase.h"
#include"DiceScript.h"

void DiceScript::Func(Charactor& _user)
{

	auto&& target = *_user.GetAttackCharactor();

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

}

//通常攻撃//
void DiceScript::Attack(Charactor& _user)
{
	auto&& target = *_user.GetAttackCharactor();

	printf("%sにダメージを与える\n", target.GetName().c_str());

	target.Damage(damage);
}

void DiceScript::CriticalAttack(Charactor& _user)
{
	auto&& target = *_user.GetAttackCharactor();

	printf("クリティカルヒット!!\n%sにガード無視のダメージを与える\n", target.GetName().c_str());

	target.CriticalDamage(damage);
}

//両プレイヤーに攻撃//
void DiceScript::BothPlayerAttack(Charactor& _user)
{
	auto&& target = *_user.GetAttackCharactor();

	printf("%sと%sにダメージを与える\n", _user.GetName().c_str(), target.GetName().c_str());

	target.Damage(damage);

	_user.Damage(damage);

}

//吸収攻撃//
void DiceScript::AbsorptionAttack(Charactor& _user)
{
	auto&& target = *_user.GetAttackCharactor();

	printf((damage <= 4 ? "%sのLPから%dポイント吸い取る\n" : "%sのLPから%dポイント吸い取る!!\n"), target.GetName().c_str(), damage);
	
	_user.Heal(target.Damage(damage));
}

//自身のHPを指定数にして攻撃//
void DiceScript::SacrificeAttack(Charactor& _user)
{

	auto&& target = *_user.GetAttackCharactor();
	
	printf("%sのLPを%dにして攻撃を続ける\n", _user.GetName().c_str(), setLP);

	_user.SetLP(setLP);

	target.Damage(damage);

}

//一部攻撃を未来へ飛ばす攻撃//
void DiceScript::CreateFieldObject(Charactor& _user)
{
	for (auto&& str : createFieldObjectNames)
	{
		_user.GetParticipationGame().AddFieldObject(str);
	}
}

//回復//
void DiceScript::HealingPoint(Charactor& _user)
{
	_user.Heal(heal);
}

//HPを入れ替える//
void DiceScript::ChangeLP(Charactor& _user)
{
	_user.ChangeLPToAttackTarget();
}
