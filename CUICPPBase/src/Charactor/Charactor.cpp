#include<ChBaseLibrary.h>

#include"Charactor.h"

void Charactor::Init(const char* _name, const int _lp)
{
    name = _name;
    lp = _lp;
    guardFlg = false;
    status = 0;
    pandoraDiceCount = 0;
}

ChStd::Bool Charactor::IsGuard()
{

    if ((guardFlg) == false)return 0;
    printf("%sは攻撃をガードした\n", name.c_str());
    return 1;
}

void Charactor::Damage(const short _damage)
{
    if (IsGuard())return;

    printf(_damage <= 4 ? "%sに%dのダメージ\n" : "%sに%dのダメージ!!\n", name.c_str(), _damage);
    lp -= _damage;

}

void Charactor::Heal(const short _heal)
{
    printf((_heal <= 4 ? "%sのLPを%d回復\n" : "%sのLPを%d回復!!\n"), name.c_str(), _heal);
    lp += _heal;
}

void Charactor::TurnStart()
{

}

void Charactor::TurnStunby()
{

}

void Charactor::ThrowDice()
{

}

void Charactor::SelectTarget()
{

}

void Charactor::SelectDice()
{

}

void Charactor::TurnEnd()
{

}

char Guard(struct CharaData* _chara)
{
    if ((_chara->statusflg & guard) == 0)return 0;
    printf("%sは攻撃をガードした\n", _chara->name);
    return 1;
}

void CriticalDamage(struct CharaData* _chara, unsigned char _damage, char _skipFlg)
{
    if (Guard(_chara) == 1)return;

    printf("クリティカルヒット!!\n");
    printf("%sに%dのダメージ!!\n", _chara->name, _damage);
    if (_chara->statusflg & guard)
    {
        _chara->lp = _chara->lp - _damage;
        if (doubleFlg > 0)
        {
            _chara->lp = _chara->lp - _damage;
        } //if(dou>0)
    }//if(esn!=1)

    _chara->pandoraDiceCount++;
}

void AttackMiss(struct CharaData* _chara)
{
    printf("ミス!%sに0ダメージ\n", _chara->name);
}

void Critical1(struct CharaData* _chara)
{
    CrotocalDamage(_chara, 7, 0);
}

void Critical2(struct CharaData* _chara)
{
    AttackMiss(_chara);
}

void diceInit(void)
{
    Critical[0] = &Critical1;
}