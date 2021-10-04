#pragma once


class Charactor;
class FutureObjectBase;
class PlayerEffectBase;

class DiceEffectBase
{
public:

    virtual void func(Charactor& _user);

protected:

    //通常攻撃//
    void NormalAttack(Charactor& _target, int _damage);

    //スタン攻撃//
    void StanAttack(Charactor& _target, int _damage);

    //アイス攻撃//
    void IceAttack(Charactor& _target, int _damage);

    //両プレイヤーに攻撃//
    void BothPlayerAttack(Charactor& _target, int _damage);

    //吸収攻撃//
    void AbsorptionAttack(Charactor& _target, int _damage);

    //自身のHPを指定数にして攻撃//
    void SacrificeAttack(Charactor& _target, int _targetDamage, int _thisHP);

    //一部攻撃を未来へ飛ばす攻撃//
    void FutureAttack(Charactor& _target, FutureObject* _obj, int _damage);

    //倍ダメージテスト//
    void DoubleTest(Charactor& _target, int _damage);

    //回復//
    void HealingPoint(Charactor& _target, int _healingPoint);

    //HPを入れ替える//
    void ChangeHP(Charactor& _target, Charactor& _this);

    //ガードさせる//
    void SetGuard(Charactor& _target);

};
