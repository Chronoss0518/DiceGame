#pragma once

class Charactor;

class PlayerEffectBase
{
public:

	void Init(Charactor* _this) { haver = _this; }

	virtual void TurnStart() {}

	virtual void TurnStunby() {}

	virtual void ThrowDice() {}

	virtual void TurnEnd() {}

private:

	Charactor* haver = nullptr;

};