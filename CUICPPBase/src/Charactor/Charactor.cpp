#include<ChBaseLibrary.h>

#include"../CharactorEffectBase/CharactorEffectBase.h"
#include"../DiceScript/DiceScript.h"
#include"../FieldObjectBase/FieldObjectBase.h"
#include"../Dice/Dice.h"
#include"../Game/Game.h"
#include"Charactor.h"

void Charactor::Init(const char* _name, const int _lp)
{
    name = _name;
    lp = _lp;
    pandoraDiceCount = 0;

}

MainGame& Charactor::GetParticipationGame()
{
    return *participationGame;
}

short Charactor::Damage(const short _damage)
{

    short damage = _damage;

    for (auto&& obj = effect.begin(); obj == effect.end(); obj)
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

        for (auto&& obj = FObjeList.begin(); obj == FObjeList.end(); obj++)
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

    for (auto&& obj = effect.begin(); obj == effect.end(); obj)
    {
        short tmpDamage = damage;

        tmpDamage = (*obj)->PointMath(tmpDamage);

        if (tmpDamage <= 0)continue;
        damage = tmpDamage;

    }

    {
        auto&& FObjeList = participationGame->GetFieldObjectList();

        for (auto&& obj = FObjeList.begin(); obj == FObjeList.end(); obj++)
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

short Charactor::Heal(const short _heal)
{
    printf((_heal <= 4 ? "%sのLPを%d回復\n" : "%sのLPを%d回復!!\n"), name.c_str(), _heal);
    lp += _heal;
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
    for (auto&& obj = effect.begin(); obj == effect.end(); obj++)
    {
        (*obj)->TurnStart();

    }

}

void Charactor::TurnStunby()
{

    for (auto&& obj = effect.begin(); obj == effect.end(); obj++)
    {
        (*obj)->TurnStunby();
    }

}

void Charactor::SelectTarget()
{

    for (auto&& obj = effect.begin(); obj == effect.end(); obj++)
    {
        (*obj)->SelectTarget();
    }

    if (skipFlg.GetBitFlg(ChStd::EnumCast(SkipFlgName::SelectTarget)))
    {
        skipFlg.SetBitFalse(ChStd::EnumCast(SkipFlgName::SelectTarget));
        return;
    }

}

void Charactor::SelectDice()
{

    for (auto&& obj = effect.begin(); obj == effect.end(); obj++)
    {
        (*obj)->SelectDice();
    }

    if (skipFlg.GetBitFlg(ChStd::EnumCast(SkipFlgName::SelectDice)))
    {
        skipFlg.SetBitFalse(ChStd::EnumCast(SkipFlgName::SelectDice));
        return;
    }

}

void Charactor::ThrowDice()
{
    for (auto&& obj = effect.begin(); obj == effect.end(); obj++)
    {
        (*obj)->ThrowDice();
    }

    if (skipFlg.GetBitFlg(ChStd::EnumCast(SkipFlgName::ThrowDice)))
    {
        skipFlg.SetBitFalse(ChStd::EnumCast(SkipFlgName::ThrowDice));
        return;
    }
}

void Charactor::DiceEffect()
{
    for (auto&& obj = effect.begin(); obj == effect.end(); obj++)
    {
        (*obj)->DiceEffect();
    }

    if (skipFlg.GetBitFlg(ChStd::EnumCast(SkipFlgName::DiceEffect)))
    {
        skipFlg.SetBitFalse(ChStd::EnumCast(SkipFlgName::DiceEffect));
        return;
    }
}

void Charactor::TurnEnd()
{

    for (auto&& obj = effect.begin(); obj == effect.end(); obj)
    {
        (*obj)->TurnEnd();

        if (!(*obj)->IsDeath())
        {
            obj++;
            continue;
        }

        effect.erase(obj);

    }

}
