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
    void CreateCharactorEffect(Charactor& _user);

    //回復//
    void HealingPoint(Charactor& _user);

    //HPを入れ替える//
    void ChangeLP(Charactor& _user);

    //ガードさせる//

private:

    short damage = 0;
    short heal = 0;
    short setLP = 0;
    std::vector<std::string> createFieldObjectNames;
    std::vector<std::string> createCharactorEffectNames;
    std::string effectText = "";
    std::vector<unsigned char>script;

};

