#pragma once

class Charactor;
class MainGame;

class FieldObjectBase
{
public:

	static ChPtr::Shared<FieldObjectBase> Create(const std::string& _str);

	void InitBase(MainGame* _participationGame) { game = _participationGame; }

	virtual void Init(){}

	MainGame& GetGame() { return *game; }

	virtual short PointMath(const short _point) { return _point; }

	ChStd::Bool IsDeath() { return (turnCount <= 0); }

	void CountDown() { turnCount = turnCount > 0 ? turnCount - 1 : 0; }

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

	static std::map<std::string, std::function<ChPtr::Shared<FieldObjectBase>(void)>>createrMap;

	MainGame* game = nullptr;

	unsigned long turnCount = 0;
};

class FO_Doubles :public FieldObjectBase
{
	short PointMath(const short _point)override;

	void Init()override { SetTurnCount(2); }
};

class FO_FierBall :public FieldObjectBase
{
	void TurnStunby()override;

	void Init()override { SetTurnCount(1); }
};