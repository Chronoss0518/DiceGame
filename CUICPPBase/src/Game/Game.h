#pragma once

class Charactor;
class FieldObjectBase;

enum class TurnNames:unsigned char
{
    TurnStart,TurnStunby, SelectTarget, SelectDice,ThrowDice,DiceEffect,TrueEnd,None
};

class MainGame :public ChCpp::BaseFrame
{
public:

    void Init()override;

    void Frame()override;

    void Release()override;

    void AddFieldObject(const std::string& _str);

    Charactor& GetTurnPlayer() { return *charactors[turnPlayer]; }

    std::vector<ChPtr::Shared<Charactor>> GetCharactorList() { return charactors; }

    std::vector<ChPtr::Shared<FieldObjectBase>> GetFieldObjectList() { return fieldObjects; }

    inline void SetTurnStart() { turnCount = ChStd::EnumCast(TurnNames::TurnStart); }

    inline void SetTurnStunby() { turnCount = ChStd::EnumCast(TurnNames::TurnStunby); }

    inline void SetThrowDice() { turnCount = ChStd::EnumCast(TurnNames::ThrowDice); }

    inline void SetDiceEffect() { turnCount = ChStd::EnumCast(TurnNames::SelectTarget); }

    inline void SetDiceEffect() { turnCount = ChStd::EnumCast(TurnNames::SelectDice); }

    inline void SetDiceEffect() { turnCount = ChStd::EnumCast(TurnNames::DiceEffect); }

    inline void SetTrueEnd() { turnCount = ChStd::EnumCast(TurnNames::TrueEnd); }

private:

    void StartDice();

    void TurnStart();

    void TurnStunby();

    void SelectTarget();

    void SelectDice();

    void ThrowDice();

    void DiceEffect();

    void TurnEnd();

    void(MainGame::*turns[7])(void);

    unsigned char turnCount = 0;

    unsigned char turnPlayer = 0;

    std::vector<ChPtr::Shared<Charactor>> charactors;
    
    std::vector<ChPtr::Shared<FieldObjectBase>> fieldObjects;

    ChStd::Bool gameEndFlg = false;

};
