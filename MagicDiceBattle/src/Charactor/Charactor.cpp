#include<ChBaseLibrary.h>

#include"../CharactorEffectBase/CharactorEffectBase.h"
#include"../DiceScript/DiceScript.h"
#include"../FieldObjectBase/FieldObjectBase.h"
#include"../PandoraDice/PandoraDice.h"
#include"../Dice/Dice.h"
#include"../Game/Game.h"
#include"Charactor.h"

void Charactor::TestData_Dice()
{
	{
		auto dice = ChPtr::Make_S<Dice>();

		dice->Init(this);
		
		dice->SetName("クリティカルダイス");

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::CriticalAttack);
			ds->SetEffectText("{u}の攻撃はクリティカルヒット!!\n");
			ds->SetDamage(7);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::Attack);
			ds->SetEffectText("{u}の攻撃は外れた\n");

			dice->AddDiceScript(ds);
		}

		{

			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::CriticalAttack);
			ds->AddScript(DiceScriptNames::CreateCharactorEffectToTarget);
			ds->SetEffectText("{u}の攻撃はクリティカルヒット!!\n");
			ds->SetDamage(5);
			ds->AddCreateCharactorEffectToTargetName(CharactorEffectNames::Stan);

			dice->AddDiceScript(ds);

		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::Attack);
			ds->SetEffectText("{u}の攻撃は外れた\n");

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::ThrowPandoraDice);
			ds->SetEffectText("パンドラダイスが起動した!!\nダイスを振れ!!\n");

			dice->AddDiceScript(ds);

		}

		{

			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::CriticalAttack);
			ds->SetEffectText("{u}の攻撃はクリティカルヒット!!\n");
			ds->SetDamage(5);

			dice->AddDiceScript(ds);

		}

		haveDice.push_back(dice);
	}

	{
		auto dice = ChPtr::Make_S<Dice>();

		dice->Init(this);

		dice->SetName("マジックダイス");

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::Attack);
			ds->AddScript(DiceScriptNames::CreateFieldObject);
			ds->SetEffectText("{u}は炎魔法、ファイアーボールを発動!!\n");
			ds->SetDamage(3);
			ds->AddCreateFieldObjectName(FieldObjectNames::FireBall);

			dice->AddDiceScript(ds);
		}

		{

			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::BothPlayerAttack);
			ds->SetEffectText("{u}は雷魔法、サンダーボルトを発動!!\n");
			ds->SetDamage(4);

			dice->AddDiceScript(ds);

		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::Attack);
			ds->SetEffectText("{u}の攻撃は外れた\n");
			ds->SetDamage(0);

			dice->AddDiceScript(ds);

		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::ThrowPandoraDice);
			ds->SetEffectText("パンドラダイスが起動した!!\nダイスを振れ!!\n");

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::CriticalAttack);
			ds->AddScript(DiceScriptNames::CreateCharactorEffectToTarget);
			ds->SetEffectText("{u}は氷魔法、サークルフロストを発動!!\n");
			ds->SetDamage(3);
			ds->AddCreateCharactorEffectToTargetName(CharactorEffectNames::Ice);

			dice->AddDiceScript(ds);

		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::SacrificeAttack);
			ds->SetEffectText("{u}は宇宙魔法、メテオを発動!!\n");
			ds->SetDamage(10);
			ds->SetLPs(1);

			dice->AddDiceScript(ds);
		}

		haveDice.push_back(dice);
	}

	{
		auto dice = ChPtr::Make_S<Dice>();

		dice->Init(this);

		dice->SetName("ガードダイス");

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::CriticalAttack);
			ds->AddScript(DiceScriptNames::CreateCharactorEffectToUser);
			ds->SetEffectText("{u}の攻撃はクリティカルヒット!!\n");
			ds->SetDamage(6);
			ds->AddCreateCharactorEffectToUserName(CharactorEffectNames::Guard);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::CreateCharactorEffectToUser);
			ds->SetEffectText("{u}は守りを固めた\n");
			ds->AddCreateCharactorEffectToUserName(CharactorEffectNames::Guard);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::ThrowPandoraDice);
			ds->SetEffectText("パンドラダイスが起動した!!\nダイスを振れ!!\n");

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::Attack);
			ds->SetEffectText("{u}の攻撃は外れた\n");

			dice->AddDiceScript(ds);

		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::Attack);
			ds->SetEffectText("{u}の攻撃\n");
			ds->SetDamage(3);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::CreateCharactorEffectToUser);
			ds->SetEffectText("{u}は守りを固めた\n");
			ds->AddCreateCharactorEffectToUserName(CharactorEffectNames::Guard);

			dice->AddDiceScript(ds);
		}

		haveDice.push_back(dice);
	}

	{
		auto dice = ChPtr::Make_S<Dice>();

		dice->Init(this);

		dice->SetName("ヒーリングダイス");

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::AbsorptionAttack);
			ds->SetEffectText("{u}はドレインを発動!!\n");
			ds->SetDamage(5);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::ThrowPandoraDice);
			ds->SetEffectText("パンドラダイスが起動した!!\nダイスを振れ!!\n");

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::Attack);
			ds->SetEffectText("{u}の攻撃\n");
			ds->SetDamage(3);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::HealingPoint);
			ds->SetDamage(6);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::CreateCharactorEffectToUser);
			ds->SetEffectText("{u}は守りを固めた\n");
			ds->AddCreateCharactorEffectToUserName(CharactorEffectNames::Guard);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::Attack);
			ds->SetEffectText("{u}の攻撃は外れた\n");

			dice->AddDiceScript(ds);

		}

		haveDice.push_back(dice);
	}

	{
		auto dice = ChPtr::Make_S<PandoraDice>();

		dice->Init(this);

		dice->SetName("パンドラダイス");

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::AbsorptionAttack);
			ds->SetEffectText("{u}はギガドレインを発動!!\n");
			ds->SetDamage(10);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::SacrificeAttack);
			ds->SetEffectText("{u}は宇宙魔法、ブラックホールを発動!!\n");
			ds->SetDamage(15);
			ds->SetLPs(1);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::ChangeLP);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::Attack);
			ds->SetEffectText("{u}はゼウスを召喚した\n");
			ds->SetDamage(13);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::HealingPoint);
			ds->SetEffectText("{u}はヒーリング・ノヴァを発動した!!\n");
			ds->SetHealPoint(10);

			dice->AddDiceScript(ds);
		}

		{
			auto&& ds = ChPtr::Make_S<DiceScript>();

			ds->AddScript(DiceScriptNames::CreateFieldObject);
			ds->SetEffectText("次の{u}のターンまで、発生する全てのダメージは2倍になる\n");
			ds->AddCreateFieldObjectName(FieldObjectNames::Doubles);

			dice->AddDiceScript(ds);

		}

		pandoraDice = dice;
	}

}

void Charactor::Init(const char* _name, const int _lp)
{
	name = _name;
	lp = _lp;
	TestData_Dice();
}

void Charactor::AddCharactorEffect(const CharactorEffectNames _name, const unsigned long _turnCount)
{
	auto&& obj = CharactorEffectBase::Create(_name);

	if (obj == nullptr)return;

	obj->InitBase(this);

	obj->Init();

	obj->SetTurn(_turnCount);

	effect.push_back(obj);
}

void Charactor::SetDiceCount(const unsigned char _count)
{
	if (_count >= 6)return;
	throwDice.lock()->SetDiceCount(_count);
}

MainGame& Charactor::GetParticipationGame()
{
	return *participationGame;
}

short Charactor::Damage(const short _damage)
{

	short damage = _damage;

	for (auto&& obj = effect.begin(); obj != effect.end(); obj)
	{
		damage = (*obj)->PointMath(damage);

		if (!(*obj)->IsDeath())
		{
			obj++;
			continue;
		}

		effect.erase(obj);

	}

	{
		auto&& FObjeList = participationGame->GetFieldObjectList();

		for (auto&& obj = FObjeList.begin(); obj != FObjeList.end(); obj++)
		{
			damage = (*obj)->PointMath(damage);

		}
	}

	if (damage <= 0)return damage;

	printf(damage <= 4 ? "%sに%dのダメージ\n" : "%sに%dのダメージ!!\n", name.c_str(), damage);
	lp -= damage;

	return damage;

}

short Charactor::CriticalDamage(const short _damage)
{

	short damage = _damage;

	for (auto&& obj = effect.begin(); obj != effect.end(); obj)
	{
		short tmpDamage = damage;

		tmpDamage = (*obj)->PointMath(tmpDamage);

		if (tmpDamage <= 0)continue;
		damage = tmpDamage;

	}

	{
		auto&& FObjeList = participationGame->GetFieldObjectList();

		for (auto&& obj = FObjeList.begin(); obj != FObjeList.end(); obj++)
		{
			short tmpDamage = damage;
			damage = (*obj)->PointMath(damage);

			if (tmpDamage <= 0)continue;
			damage = tmpDamage;

		}
	}

	if (damage <= 0)return damage;

	printf(damage <= 4 ? "%sに%dのダメージ\n" : "%sに%dのダメージ!!\n", name.c_str(), damage);
	lp -= damage;

	return damage;

}

void Charactor::ThrowPandoraDice()
{
	throwDice = pandoraDice;

	participationGame->SetSelectDice();

}

short Charactor::Heal(const short _heal)
{
	printf((_heal <= 4 ? "%sのLPを%d回復\n" : "%sのLPを%d回復!!\n"), name.c_str(), _heal);
	lp += _heal;

	return _heal;
}

void Charactor::ChangeLPToAttackTarget()
{

	auto&& target = *attackTarget.lock();

	printf("%sと%sのLPを入れ替える!\n", name.c_str(), target.name.c_str());

	lp += target.lp;
	target.lp = lp - target.lp;
	lp -= target.lp;

}

void Charactor::TurnStart()
{
	printf("%sのターンです\n", name.c_str());

	std::getchar();

	for (auto&& obj = effect.begin(); obj != effect.end(); obj++)
	{
		(*obj)->TurnStart();
	}

	if (!controller->Decision())return;

	participationGame->AddTurnCount();
}

void Charactor::TurnStunby()
{

	for (auto&& obj = effect.begin(); obj != effect.end(); obj++)
	{
		(*obj)->TurnStunby();
	}

	if (!controller->Decision())return;

	participationGame->AddTurnCount();
}

void Charactor::SelectTarget()
{
	for (auto&& obj = effect.begin(); obj != effect.end(); obj++)
	{
		(*obj)->SelectTarget();
	}

	if (skipFlg)return;

	auto cList = participationGame->GetCharactorList();

	if (controller->Decision())
	{
		attackTarget = cList[targetCharactor];

		participationGame->AddTurnCount();
	}

	if (controller->Up())
	{
		targetCharactor++;
		targetCharactor %= cList.size();
	}

	if (controller->Down())
	{
		targetCharactor--;
		targetCharactor %= cList.size();
	}

}

void Charactor::SelectDice()
{

	for (auto&& obj = effect.begin(); obj != effect.end(); obj++)
	{
		(*obj)->SelectDice();
	}

	if (skipFlg)return;

	throwDice = pandoraDice;

	if (pandoraDice->IsThrow())
	{
		printf("パンドラダイスが起動!!\nダイスを振れ!!");
		return;
	}

	if (controller->Decision())
	{
		throwDice = haveDice[targetDice];

		participationGame->AddTurnCount();
	}

	if (controller->Up())
	{
		targetDice++;
		targetDice %= haveDice.size();
	}

	if (controller->Down())
	{
		targetDice--;
		targetDice %= haveDice.size();
	}

}

void Charactor::ThrowDice()
{
	unsigned char throwCount = rand() % 6;

	for (auto&& obj = effect.begin(); obj != effect.end(); obj++)
	{
		(*obj)->ThrowDice();
	}

	if (skipFlg)return;

	if (!controller->ThrowDice())return;

	throwDice.lock()->SetDiceCount(throwCount);

	participationGame->AddTurnCount();
}

void Charactor::DiceEffect()
{
	for (auto&& obj = effect.begin(); obj != effect.end(); obj++)
	{
		(*obj)->DiceEffect();
	}

	if (skipFlg)return;

	throwDice.lock()->DiceEffect();

	if (!controller->Decision())return;

	participationGame->AddTurnCount();
}

void Charactor::TurnEnd()
{

	for (auto&& obj = effect.begin(); obj != effect.end(); obj)
	{
		(*obj)->TurnEnd();

		if (!(*obj)->IsDeath())
		{
			obj++;
			continue;
		}

		effect.erase(obj);

	}

	if (!controller->Decision())return;

	participationGame->AddTurnCount();

}
