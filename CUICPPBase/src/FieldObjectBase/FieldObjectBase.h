#pragma once

class Charactor;
class MainGame;

#include"FieldObjectNames_Enum.h"

class FieldObjectBase
{
public:

	static ChPtr::Shared<FieldObjectBase> Create(const FieldObjectNames _names);

	void InitBase(MainGame* _participationGame) { game = _participationGame; }

	virtual void Init(){}

	inline void SetTurn(const unsigned long _turn) { turnCount = _turn; }

	MainGame& GetGame() { return *game; }

	virtual FieldObjectNames GetType() = 0;

	virtual short PointMath(const short _point) { return _point; }

	ChStd::Bool IsDeath() { return (turnCount <= 0); }

	void CountDown() { turnCount = turnCount > 0 ? turnCount - 1 : 0; }

	virtual void Update(){}

	virtual void Draw(){}

	virtual void TurnStart(){}

	virtual void TurnStunby(){}

	virtual void SelectTarget(){}

	virtual void SelectDice(){}

	virtual void ThrowDice(){}

	virtual void DiceEffect() {}

	virtual void TurnEnd(){}

protected:

	void SetTurnCount(const unsigned long _turnCount) { turnCount = _turnCount; }

protected:

	void SetDeathFlgTrue() { turnCount = 0; }

private:

	static ChPtr::Shared<FieldObjectBase>(*createrMap[(unsigned char)FieldObjectNames::None])(void);

	MainGame* game = nullptr;

	unsigned long turnCount = 0;
};

class FO_Doubles :public FieldObjectBase
{
	short PointMath(const short _point)override;

	void Init()override { SetTurnCount(2); }

	inline FieldObjectNames GetType()override { return FieldObjectNames::Doubles; }
};

class FO_FireBall :public FieldObjectBase
{
	void TurnStunby()override;

	void Init()override { SetTurnCount(1); }

	inline FieldObjectNames GetType()override { return FieldObjectNames::FireBall; }
};