#pragma once

class FieldObjectBase;
class CharactorEffectBase;

#include"../CharactorEffectBase/CharactorEffectNames_Enum.h"
#include"../FieldObjectBase/FieldObjectNames_Enum.h"

enum class DiceScriptNames :unsigned char
{
    Attack,
    CriticalAttack,
    BothPlayerAttack,
    AbsorptionAttack,
    SacrificeAttack,
    CreateFieldObject,
    CreateCharactorEffectToUser,
    CreateCharactorEffectToTarget,
    HealingPoint,
    HealingPointForTarget,
    ChangeLP,
    ThrowPandoraDice,
    None
};

class DiceScript
{
public:

    void Init();

    void Func(Charactor& _user);

    short PointMath(const short _point) { return _point; }

    inline void SetDamage(const short _damage) { damage = _damage; }

    inline void SetHealPoint(const short _healPoint) { heal = _healPoint; }

    inline void SetLPs(const short _lp) { setLP = _lp; }

    inline void SetTurns(const short _turn) { setTurns = _turn; }

    inline void SetEffectText(const std::string& _text) { effectText = _text; }

    inline void AddScript(const DiceScriptNames _script) { script.push_back(ChStd::EnumCast(_script)); }

    inline void AddCreateFieldObjectName(const FieldObjectNames _name) { createFieldObjectNames.push_back(_name); }

    inline void AddCreateCharactorEffectToUserName(const CharactorEffectNames _name) { createCharactorEffectToUserNames.push_back(_name); }

    inline void AddCreateCharactorEffectToTargetName(const CharactorEffectNames _name) { createCharactorEffectToTargetNames.push_back(_name); }

private:

    std::string CreateTexter(Charactor& _user);

    void(DiceScript::* scripts[(unsigned char)DiceScriptNames::None])(Charactor& _user);

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
    void CreateCharactorEffectToUser(Charactor& _user);

    void CreateCharactorEffectToTarget(Charactor& _user);

    //��//
    void HealingPoint(Charactor& _user);

    void HealingPointForTarget(Charactor& _user);

    //HP�����ւ���//
    void ChangeLP(Charactor& _user);

    //�K�[�h������//

    //�p���h���_�C�X���N��//
    void ThrowPandoraDice(Charactor& _user);

private:

    short damage = 0;
    short heal = 0;
    short setLP = 0;
    unsigned long setTurns = 0;
    std::vector<FieldObjectNames> createFieldObjectNames;
    std::vector<CharactorEffectNames> createCharactorEffectToUserNames;
    std::vector<CharactorEffectNames> createCharactorEffectToTargetNames;
    std::string effectText = "";
    std::vector<unsigned char>script;

};

