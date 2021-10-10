#pragma once

class FieldObjectBase;
class CharactorEffectBase;

class DiceScript
{
public:

    void Func(Charactor& _user);

    short PointMath(const short _point) { return _point; }

    inline void SetDamage(const short _damage) { damage = _damage; }

    inline void SetHealPoint(const short _healPoint) { heal = _healPoint; }

    inline void SetEffectText(const std::string& _text) { effectText = _text; }

    inline void AddScript(const unsigned char _script) { script.push_back(_script); }

    inline void AddCreateFieldObjectName(const std::string& _name) { createFieldObjectNames.push_back(_name); }

    inline void AddCreateCharactorEffectName(const std::string& _name) { createCharactorEffectNames.push_back(_name); }

private:

    std::string CreateTexter(Charactor& _user);

    void(DiceScript::* scripts[9])(Charactor& _user) =
    {
        Attack,
        CriticalAttack,
        BothPlayerAttack,
        AbsorptionAttack,
        SacrificeAttack,
        CreateFieldObject,
        CreateCharactorEffect,
        HealingPoint,
        ChangeLP
    };

    //�ʏ�̍U��//
    void Attack(Charactor& _user);

    //�N���e�B�J��//
    void CriticalAttack(Charactor& _user);

    //�X�^���̌��ʂ�t�^//
    //�A�C�X�̌��ʂ�t�^//

    //���v���C���[�ɍU��//
    void BothPlayerAttack(Charactor& _user);

    //�z���U��//
    void AbsorptionAttack(Charactor& _user);

    //���g��HP���w�萔�ɂ��čU��//
    void SacrificeAttack(Charactor& _user);

    //�ꕔ�U���𖢗��֔�΂��U��//
    //�{�_���[�W�e�X�g//

    //FieldObejct�̍쐬//
    void CreateFieldObject(Charactor& _user);

    //CharactorEffect�̍쐬//
    void CreateCharactorEffect(Charactor& _user);

    //��//
    void HealingPoint(Charactor& _user);

    //HP�����ւ���//
    void ChangeLP(Charactor& _user);

    //�K�[�h������//

private:

    short damage = 0;
    short heal = 0;
    short setLP = 0;
    std::vector<std::string> createFieldObjectNames;
    std::vector<std::string> createCharactorEffectNames;
    std::string effectText = "";
    std::vector<unsigned char>script;

};

