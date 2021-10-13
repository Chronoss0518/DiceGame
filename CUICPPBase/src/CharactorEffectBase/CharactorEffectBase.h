#pragma once

class Charactor;

#include"CharactorEffectNames_Enum.h"

class CharactorEffectBase
{
public:

	static ChPtr::Shared<CharactorEffectBase> Create(const CharactorEffectNames _names);

	void InitBase(Charactor* _thisHaver) { haver = _thisHaver; }

	virtual void Init() {}

	inline void SetTurn(const unsigned long _turn) { turnCount = _turn; }

	Charactor& GetCharactor() { return *haver; }

	virtual short PointMath(const short _point) { return _point; }

	ChStd::Bool IsDeath() { return deathFlg; }

	void CountDown() { turnCount = turnCount > 0 ? turnCount - 1 : 0; }

	virtual void TurnStart() {}

	virtual void TurnStunby() {}

	virtual void SelectTarget() {}

	virtual void SelectDice() {}

	virtual void ThrowDice() {}

	virtual void DiceEffect() {}

	virtual void TurnEnd() {}

protected:

	void SetDeathFlgTrue() { deathFlg = true; }

private:

	static ChPtr::Shared<CharactorEffectBase>(*createrMap[(unsigned char)CharactorEffectNames::None])(void);

	Charactor* haver = nullptr;

	unsigned long turnCount = 0;

	ChStd::Bool deathFlg = false;

};

class C_AttackDouble :public CharactorEffectBase
{
	void Init()override;

	short PointMath(const short _point)override;
};

class C_GuardEffect:public CharactorEffectBase
{
	void Init()override;

	short PointMath(const short _point)override;
};

class C_StanEffect : public CharactorEffectBase
{
	void Init()override;

	void TurnStunby()override;
};

class C_Ice : public CharactorEffectBase
{
	void Init()override;

	void TurnStunby()override;
};