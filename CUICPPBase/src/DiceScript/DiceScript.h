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

    //通常の攻撃//
    void Attack(Charactor& _user);

    //クリティカル//
    void CriticalAttack(Charactor& _user);

    //スタンの効果を付与//
    //アイスの効果を付与//

    //両プレイヤーに攻撃//
    void BothPlayerAttack(Charactor& _user);

    //吸収攻撃//
    void AbsorptionAttack(Charactor& _user);

    //自身のHPを指定数にして攻撃//
    void SacrificeAttack(Charactor& _user);

    //一部攻撃を未来へ飛ばす攻撃//
    //倍ダメージテスト//

    //FieldObejctの作成//
    void CreateFieldObject(Charactor& _user);

    //CharactorEffectの作成//
    void CreateCharactorEffectToUser(Charactor& _user);

    void CreateCharactorEffectToTarget(Charactor& _user);

    //回復//
    void HealingPoint(Charactor& _user);

    void HealingPointForTarget(Charactor& _user);

    //HPを入れ替える//
    void ChangeLP(Charactor& _user);

    //ガードさせる//

    //パンドラダイスを起動//
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

