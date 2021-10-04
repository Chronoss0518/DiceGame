#pragma once


class Charactor;
class FutureObjectBase;
class PlayerEffectBase;

class DiceEffectBase
{
public:

    virtual void func(Charactor& _user);

protected:

    //�ʏ�U��//
    void NormalAttack(Charactor& _target, int _damage);

    //�X�^���U��//
    void StanAttack(Charactor& _target, int _damage);

    //�A�C�X�U��//
    void IceAttack(Charactor& _target, int _damage);

    //���v���C���[�ɍU��//
    void BothPlayerAttack(Charactor& _target, int _damage);

    //�z���U��//
    void AbsorptionAttack(Charactor& _target, int _damage);

    //���g��HP���w�萔�ɂ��čU��//
    void SacrificeAttack(Charactor& _target, int _targetDamage, int _thisHP);

    //�ꕔ�U���𖢗��֔�΂��U��//
    void FutureAttack(Charactor& _target, FutureObject* _obj, int _damage);

    //�{�_���[�W�e�X�g//
    void DoubleTest(Charactor& _target, int _damage);

    //��//
    void HealingPoint(Charactor& _target, int _healingPoint);

    //HP�����ւ���//
    void ChangeHP(Charactor& _target, Charactor& _this);

    //�K�[�h������//
    void SetGuard(Charactor& _target);

};
