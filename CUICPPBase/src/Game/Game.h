#pragma once

class Charactor;
class FieldObjectBase;

#include"../FieldObjectBase/FieldObjectBase.h"

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

    void AddFieldObject(const FieldObjectNames _name, const unsigned long _turnCount);

    inline void SetTurnCount(const unsigned char _turnCount) { turnCount = _turnCount < ChStd::EnumCast(TurnNames::None) ? _turnCount : turnCount; }

    Charactor& GetTurnPlayer() { return *charactors[turnPlayer]; }

    inline unsigned char GetTurnCount() { return turnCount; }

    std::vector<ChPtr::Shared<Charactor>> GetCharactorList() { return charactors; }

    std::vector<ChPtr::Shared<FieldObjectBase>> GetFieldObjectList() { return fieldObjects; }

    inline void SetTurnStart() { turnCount = ChStd::EnumCast(TurnNames::TurnStart); }

    inline void SetTurnStunby() { turnCount = ChStd::EnumCast(TurnNames::TurnStunby); }

    inline void SetThrowDice() { turnCount = ChStd::EnumCast(TurnNames::ThrowDice); }

    inline void SetSelectTarget() { turnCount = ChStd::EnumCast(TurnNames::SelectTarget); }

    inline void SetSelectDice() { turnCount = ChStd::EnumCast(TurnNames::SelectDice); }

    inline void SetDiceEffect() { turnCount = ChStd::EnumCast(TurnNames::DiceEffect); }

    inline void SetTrueEnd() { turnCount = ChStd::EnumCast(TurnNames::TrueEnd); }

    inline unsigned long GetPandoraCount() { return pandoraCount; }

    inline void TurnCountUps() { turnCount = (turnCount + 1) % ChStd::EnumCast(TurnNames::None); }

private:

    void StartDice();

    void TurnStart();

    void TurnStunby();

    void SelectTarget();

    void SelectDice();

    void ThrowDice();

    void DiceEffect();

    void TurnEnd();

    void(MainGame::*turns[8])(void);

    unsigned char turnCount = 0;

    unsigned char turnPlayer = 0;

    unsigned long pandoraCount = 6;

    std::vector<ChPtr::Shared<Charactor>> charactors;
    
    std::vector<ChPtr::Shared<FieldObjectBase>> fieldObjects;

    ChStd::Bool gameEndFlg = false;

};
