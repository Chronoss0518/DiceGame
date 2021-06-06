#include<ChBaseLibrary.h>

#include"Charactor.h"

void Charactor::Init(const char* _name, const int _lp)
{
    name = _name;
    lp = 30;
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

void Charactor::Damage(const int _damage)
{
    if (IsGuard())return;

    printf(_damage <= 4 ? "%sに%dのダメージ\n" : "%sに%dのダメージ!!\n", name.c_str(), _damage);
    lp -= _damage;

}
